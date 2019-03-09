#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f1(double x){return x*x - 9;}
typedef double (*FuncOneVar) (double x); 

double bisection(FuncOneVar f, double a, double b, double eps){
	
	double ya = f(a);
	double yb = f(b);
	if (ya * yb > 0)
		throw "Function does not appear to cross zero.";
	double mid;
	do{
		mid = (a+b)/2;
		double y = f(mid);
		if (y > 0)
			b = mid;
		else if (y < 0)
			a = mid;
		else 
			return mid;
	}while(b - a > eps);
	return mid;
}

double bisectionRec(FuncOneVar f, double a, double b, double eps){
	double ya = f(a);
	double yb = f(b);
	if(ya * yb > 0)
		throw "error";
	double mid = (a + b) / 2;
	double y = f(mid);
	if(b - a <= eps || y == 0)
		return mid;
	if(y > 0)
		return bisectionRec(f, a, mid, eps);
	if(y < 0)
		return bisectionRec(f, mid, b, eps);
	return 0;
}

int main(){
	// cout << f1(0) << " " << f1(3) << endl;
	cout << bisection(f1, 0, 3, 0.1) << endl;
	cout << setprecision(15);
	cout << bisection(f1, 0, 3, 0.0001) << endl;
	cout << bisection(f1, 0, 3, 0.000001) << endl;
	cout << bisection(f1, 0, 3, 0.000000000001) << endl;
	cout << bisectionRec(f1, 0, 3, 0.000000000001) << endl;
}