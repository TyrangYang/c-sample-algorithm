#include <iostream>
using namespace std;

uint64_t choose(int n, int r){
	if (n < r){
		cout << "error" << endl;
		return 0;
	}
	static uint64_t memo[200][200] = {0};
	if (r == 0 || r == n){
		return 1;
	}
	if (memo[n][r] != 0){
		return memo[n][r];
	}
	return memo[n][r] = choose(n-1,r-1) + choose(n-1,r);
}


uint64_t choose2(int n, int r){
	if (n < r){
		cout << "error" << endl;
		return 0;
	}
	static uint64_t memo[200][200] = {0};
	if (r == 0){
		return 1;
	}
	if (r > n/2){
		return choose2(n, n-r);
	}
	if (memo[n][r] != 0){
		return memo[n][r];
	}
	return memo[n][r] = choose(n-1,r-1) + choose(n-1,r);
}

int main(){
	int n,r;
	int num = 5;
	int testCastn[]= {4,4,5,5,69} ;
	int testCastr[] = {2,3,2,3,34};
	// cout << "n is: ";
	// cin >> n;
	// cout << "r is: ";
	// cin >> r;
	for(int i = 0; i < num;i++){
		n = testCastn[i];
		r = testCastr[i];
		cout << choose(n,r) << " " << choose2(n ,r) << endl;
	}

}
