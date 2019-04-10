#include <iostream>
#include <vector>


using namespace std;
template <typename T>
class Matrix
{
private:
	int rows, cols;
	T* m;
public:
	Matrix(int row, int col): rows(row), cols(col), m(new T[rows*cols]){
		for (int i = 0; i < rows*cols; ++i)
		{
			m[i] = 0;
		}
	}

	Matrix(int row, int col, T val): rows(row), cols(col), m(new T[rows*cols]){
		for (int i = 0; i < rows*cols; ++i)
		{
			m[i] = val;
		}
	};
	~Matrix(){
		delete[] m;
	};

	T getValbyPos(int r, int c){
		return m[r*cols + c];
	}

	void setValbyPos(int r, int c, T val){
		if(r > rows || c > cols)
			throw "error";
		m[r*cols + c] = val;
	}

	int getRows(){
		return rows;
	}

	int getCols(){
		return cols;
	}

	Matrix(const Matrix& orig){
		rows = orig.rows;
		cols = orig.cols;
		m = new T[rows * cols];
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				m[i*cols + j] = orig.m[i * cols + j];
			}
		}
	}

	void showAll(){
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				cout << m[i*cols + j] << " ";
			}
			cout << endl;
		}
	}

	void operator =(const Matrix& orig){
		if(orig.rows != rows || orig.cols != cols)
			throw invalid_argument("The matrix should be matched");
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				m[i*cols + j] = orig.m[i * cols + j];
			}
		}

	}

	T& operator ()(int r, int c){
		return m[r*cols + c];
	}
	T operator ()(int r, int c) const{
		return m[r*cols + c];
	}
	
};

int main(int argc, char const *argv[])
{	
	Matrix<int> m1(3, 4, 1);
	m1(1,2) = 100;
	Matrix<int> m2(m1);
	Matrix<int> m3(3,4,0);
	m3 = m2;

	m1.showAll();
	cout << "=====" << endl;
	m2.showAll();
	cout << "=====" << endl;
	m3.showAll();


	return 0;
}

// the main function on course

// int main(int argc, char const *argv[])
// {
// 	Matrix m1(3,4,0.0);
// 	m1(1,2) = 1.5
// 	Matrix m2(3,4,1.0);
// 	Matrix m3 = m1 + m2;

// 	cout << m3 << endl;

// 	Matrix m4(4, 2, 0.5);
// 	m4(0,0) = 5.0;
// 	m4(0,2) = -1.0;
// 	Matrix m5 = m1 * m4;
// 	cout << m5 << endl;

// 	ifstream f("hw5.dat");
// 	Matrix A = Matrix::read(f);
// 	std::vector<double> B = read(A.getrows(), f);
// 	std::vector<double> x = solve(A, B);
// 	return 0;
// }