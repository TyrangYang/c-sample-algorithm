#include <iostream>

using namespace std;

class Matrix
{
private:
	int rows, cols;
	double* m;
public:
	Matrix(int row, int col, double val): rows(row), cols(col), m(new double[rows*cols]){
		for (int i = 0; i < rows*cols; ++i)
		{
			m[i] = val;
		}
	};
	~Matrix(){};
	Matrix(const Matrix& orig) = delete;
	Matrix operator =(const Matrix& orig) = delete;
	double& operator ()(int r, int c){
		return m[r*cols + c];
	}
	double operator ()(int r, int c) const{
		return m[r*cols + c];
	}
	
};

int main(int argc, char const *argv[])
{
	Matrix m1(3,4,0.0);
	m1(1,2) = 1.5
	Matrix m2(3,4,1.0);
	Matrix m3 = m1 + m2;

	cout << m3 << endl;

	Matrix m4(4, 2, 0.5);
	m4(0,0) = 5.0;
	m4(0,2) = -1.0;
	Matrix m5 = m1 * m4;
	cout << m5 << endl;

	ifstream f("hw5.dat");
	Matrix A = Matrix::read(f);
	std::vector<double> B = read(A.getrows(), f);
	std::vector<double> x = solve(A, B);
	return 0;
}