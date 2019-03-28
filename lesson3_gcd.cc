// gcd(a,b) = gcd(b,b mod a) .... gcd(b,0) 
// lcm(a, b) = a * b / gcd(a,b)
// fema
// miller rabin


#include <iostream>
#include <cmath>
using namespace std;

int bruteforcegcd(int a, int b){
	for(int i = min(a,b); i >= 2; i--){
		if(a % i == 0 && b % i == 0){
			return i;
		}
	}
	return 1;
}
int gcd(int a, int b){ // greatest common divisor.
	int small = min(a,b);
	int big = max(a,b);
	while(small != 0){
		int temp = small;
		small = big % small;
		big = temp;
	}
	return big;
}

int gcdRec(int a, int b){
	int small = min(a, b);
	int big = max(a, b);
	if(small == 0)
		return big;
	return gcdRec(small, big % small);
}

int lcm(int a, int b){ // least common multiple.
	return a * b / gcd(a, b);
}


int main(){
	cout << bruteforcegcd(3025, 1025) << endl;
	cout << gcdRec(18,12) << endl;
	cout << "gcd: " << gcd(18, 12) << "  lcm: " << lcm(18, 12) << endl;
}