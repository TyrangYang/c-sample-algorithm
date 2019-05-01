#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

template <typename T>
class Matrix
{
private:
	int rows, cols;
	T* m;
	Matrix(int row, int col): rows(row), cols(col), m(new T[rows*cols]){ //new for c++ is O(1). but for java is O(n)
		for (int i = 0; i < rows*cols; ++i)
		{
			m[i] = 0;
		}
	}
public:
	Matrix(int row, int col, T val): rows(row), cols(col), m(new T[rows*cols]){
		for (int i = 0; i < rows*cols; ++i)
		{
			m[i] = val;
		}
	};

	Matrix(const Matrix& orig): rows(orig.rows), cols(orig.cols), m(new T[rows * cols]) {
		// cout << "copy " << endl;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				m[i*cols + j] = orig.m[i * cols + j];
			}
		}
	}

	Matrix(Matrix&& orig) : rows(orig.rows), cols(orig.cols), m(orig.m) {
		// cout << "move" << endl;
		orig.m = nullptr;
	}

	~Matrix(){
		delete[] m;
	};
	
	Matrix& operator =(const Matrix& orig){
		delete[] m;
		rows = orig.rows;
		cols = orig.cols;
		m = new T[orig.rows * orig.cols];
		for (int i = 0; i < rows * cols; ++i)
		{
			m[i] = orig.m[i];
		} 
		return *this;
	}

	friend Matrix operator *(const Matrix& m1, const Matrix& m2){
		if(m1.cols != m2.rows)
			throw "The matrix should be matched";
		int m = m1.rows;
		int n = m1.cols;
		int p = m2.cols;

		Matrix<T> res(m,p);

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < p; ++j)
			{
				T sum = 0;
				for (int k = 0; k < n; ++k)
				{
					sum += m1(i, k) * m2(k, j);
				}
				res(i, j) = sum;
			}
		}

		return res;
	}

	friend Matrix operator +(const Matrix& m1, const Matrix& m2){
		// cout << "plus" << endl;
		if(m1.rows != m2.rows || m1.cols != m2.cols)
			throw "The matrix should be matched";
		int r = m1.rows; 
		int c = m1.cols;
		Matrix<T> res(r, c);

		for (int i = 0; i < r*c; ++i)
		{
			res.m[i] = m1.m[i] + m2.m[i];
		}

		return res;
	}

	friend ostream& operator <<(ostream& s, const Matrix<T>& source){
		for (int i = 0; i < source.rows; ++i){
			for (int j = 0; j < source.cols; ++j)
			{
				s << source.m[i * source.cols + j] << "\t";
			}
			if(i != source.rows - 1)
				s << "\n";
		}
		return s;
	}

	T& operator ()(int r, int c){
		return m[r*cols + c];
	}

	T operator ()(int r, int c) const{
		return m[r*cols + c];
	}

	T getRows(){
		return rows;
	}

	T getCols(){
		return cols;
	}

	static Matrix read(ifstream& f){
		int num;
		f >> num;
		Matrix<T> res(num,num,0);
		for (int i = 0; i < num; ++i)
		{
			for (int j = 0; j < num; ++j)
			{
				f >> res(i, j);
			}
		}
		return res;
	}
};


vector<double> solve(Matrix<double> A, vector<double> B){
	int num_solve = A.getRows();
	for (int i = 0; i < num_solve; ++i) // loop for all x
	{
		for (int j = i + 1; j < num_solve; ++j) // eliminate one column
		{
			if(A(j, i) == 0)
				continue;
			double factor = A(i, i) / A(j, i);
			for (int k = i; k < num_solve; ++k)
			{
				A(j, k) *= factor;
				A(j, k) -= A(i, k);
			}
			B[j] *= factor;
			B[j] -= B[i];
		}
	}

	vector<double> tempRes;
	for (int i = num_solve - 1; i >= 0 ; i--)
	{
		for (int j = num_solve - 1; j >= i; j--)
		{
			if(j == i){
				double oneRes = B[i] / A(i,i);
				tempRes.push_back(oneRes);
			}
			else{
				B[i] -= A(i, j) * tempRes[num_solve - j - 1];
			}
		}
	}
	vector<double> res;
	while(!tempRes.empty()){
		res.push_back(tempRes.back());
		tempRes.pop_back();
	}	
	return res;
}

int main(int argc, char const *argv[])
{
	Matrix<double> a(3,4,0.0);  // O(mn) = O(3*4)
	Matrix<double> b(4,2,1.0); //O(n*p) = O(4*2);
	Matrix<double> c = b; // make a copy O(np) // copy constructor
	Matrix<double> d = a + a;  //O(mn)

	a(1,1) = 10;
	b(1,1) = 5.2; // calls operator()(int,int)
	cout << b(1,2) << endl; // calls operator()(int,int)const

	Matrix<double> e = a * b;  //O(mnp)    O(n^3)
	cout << "+++++++++++a++++++++++++" << endl;
	cout << a << endl;
	cout << "+++++++++++b++++++++++++" << endl;
	cout << b << endl;
	cout << "+++++++++++c++++++++++++" << endl;
	cout << c << endl;
	cout << "+++++++++++d++++++++++++" << endl;
	cout << d << endl;
	cout << "+++++++++++e++++++++++++" << endl;
	cout << e << endl;

	a = e = b;
	cout << "+++++++++++e++++++++++++" << endl;
	cout << e << endl;
	cout << "+++++++++++a++++++++++++" << endl;
	cout << a << endl;
	/*
	a11 a12 a13      x           B1
	a21 a22 a23      y     =     B2
	a31 a32 a33      z           B3
	*/
	ifstream f("hw5.dat");
	Matrix<double> A = Matrix<double>::read(f);

	int n = A.getRows();
	vector<double> B;
	vector<double> x;
	double oneNum;
	for (int i = 0; i < n; ++i)
	{
		f >> oneNum;
		B.push_back(oneNum);
	}
	cout << "+++++++++++++++++++++++" << endl;
	cout << A << endl;
	for (vector<double>::iterator i = B.begin(); i != B.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
	x = solve(A, B);

	cout << "res:";
	for (vector<double>::iterator i = x.begin(); i != x.end(); ++i)
	{
		cout << " " << *i;
	}
	cout << endl;
	return 0;
}