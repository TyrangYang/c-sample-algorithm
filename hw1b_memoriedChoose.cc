/*
HW1 - choose 
Author: Haolin Yang
*/

#include <iostream>
#include <random>
using namespace std;

double choose_test(int n, int r) {
	return 0;
}
// need 6.7 seconds to run 100 million trials for this choose fuction on my laptop

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
}// Use Pascal's Triangle

uint64_t choose2(int n, int r){
	if (n < r){
		cout << n << " " << r << "#error" << endl;
		return 0;
	}
	static uint64_t memo[200][200] = {0};
	if (r == 0){
		return 1;
	}
	if (r > n/2){
		return choose2(n,n-r);
	}
	if (memo[n][r] != 0){
		return memo[n][r];
	}
	return memo[n][r] = choose2(n-1,r-1) + choose2(n-1,r);
}//Use Half Pascal's Triangle 

int main() {
	int numTrials = 100000000;
	//cin >> numTrials;

	default_random_engine generator;
	uniform_int_distribution<int> distribution(0,100);	

 	for (int i = 0; i < numTrials; i++) {
		int n = distribution(generator);
		uniform_int_distribution<int> rdist(0,n);	
		int r = rdist(generator);
		choose2(n,r);
		// choose_test(n,r);
    	// cout << n << " " << r << " " << choose(n,r) <<" "<< choose2(n,r) << endl;
    	
	}	
	//7.9 second for running choose 100 million times on my laptop
}