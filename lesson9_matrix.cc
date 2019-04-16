// #ifndef MATRIX_H
// #define MATRIX_H
#include <iostream>
#include <vector>
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
	
	// Matrix transpose() const{
	// 	Matrix ans(rows, cols);
	// 	int i = 0;
	// 	for (int r = 0; r < rows; ++r)
	// 	{
	// 		for (int c = 0; c < cols; ++c, ++i)
	// 		{
	// 			ans.m(c, r) = m[i];
	// 		}
	// 	}

	// 	//alter one

	// 	// int i = 0;
	// 	// int j = 0;
	// 	// for (int r = 0; r < rows; ++r)
	// 	// {
	// 	// 	int j = r;
	// 	// 	for (int c = 0; c < cols; ++c , ++i , j += cols)
	// 	// 	{
	// 	// 		ans.m[j] = m[i];
	// 	// 	}
	// 	// }
	// }
};
// #endif


#if 0
int main(int argc, char const *argv[])
{
	Matrix<double> m1(3,4,0.0);
	m1(1,2) = 1.5;
	Matrix<double> m2(3,4, 1);
	cout << "=====" << endl;
	Matrix<double> m3 (m1 + m2) ;
	// m1 = m3 = m1+m2;
	cout << "rows:" << m3.getRows() << " cols:" <<  m3.getCols() << endl;
	cout << "===m1===" << endl;
	cout << m1 << endl;
	cout << "===m2===" << endl;
	cout << m2 << endl;
	cout << "===m3===" << endl;
	cout << m3 << endl;

	Matrix<double> m4(4, 2, 0.5);
	m4(0,0) = 5.0;
	m4(0,2) = -1.0;
	Matrix<double> m5 = m1 * m4;
	cout << "===m4===" << endl;
	cout << m4 << endl;
	cout << "===m5===" << endl;
	cout << m5 << endl;
	return 0;
}
#endif

// the main function on course
