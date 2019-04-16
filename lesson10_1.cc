#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {return x*x;}
double h(double x) {return x*x*x;}
double g(double x) {return x*x*x*x;}

typedef double (*FuncOneVar)(double x);
double trapezoidal (FuncOneVar f, double a, double b, double eps){
	int n = 2;
	double h = (b - a)/n;

	double avgHeight = 0.5 * (f(a) + f(b)) + f((a+b)/2);
	double I2 = avgHeight * h;
	n *= 2;
	h *= 0.5;

	double x = h;
	for (int i = 0; i < n; i++ , x += 2*h)
	{
		avgHeight += f(x);
	}
	double I4 = avgHeight * h;
	return I4;
}

constexpr double x2 = 1 / sqrt(3);
double gauss2(FuncOneVar f, double a, double b){
	double mid = (a+b) / 2;
	double h  = (b - a)/2;
	double x0 = mid - x2 * h;
	double x1 = mid + x2 * h;
	double y0 = f(x0);
	double y1 = f(x1);
	return y0 + y1; 
}

constexpr double x3 = sqrt(3 / 5);
double gauss3(FuncOneVar f, double a, double b){
	double mid = (a+b) / 2;
	double h  = (b - a)/2;
	double y0 = f(mid);
	double y1 = f(mid - x3 * h);
	double y2 = f(mid + x3 * h);

	return 8.0/9*y0 + 5.0/9*(y1 + y2);
}

int main(int argc, char const *argv[])
{
	cout << gauss2(f, 0, 2) << endl;
	cout << gauss2(h, 0, 2) << endl;
	

	return 0;
}