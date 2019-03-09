#include <iostream>
#include <cmath>
using namespace std;

int sum(int n){
	if (n == 0){
		return 0;
	}
	return n + sum(n-1);
}

int fibo_recision(int n){
	if (n <= 2)
		return 1;
	return fibo_recision(n-2)+fibo_recision(n-1);
}

uint64_t fibo(uint64_t n){
	uint64_t a = 1, b = 1 , c;
	for (uint64_t i = 0; i < n-2 ; i++){
		c = a+b;
		a = b;
		b = c;
	}
	return c;
}

uint64_t fibo_better(int n){
	if (n <= 2){
		return 1;
	}
	static uint64_t memo[200] = {0};
	if (memo[n] != 0){
		return memo[n];
	}
	return memo[n] = fibo_better(n-1)+fibo_better(n-2);
}

bool isPrime(uint64_t n){
	for (uint64_t i = 2; i <=  sqrt(n); i++){
		if (n % i == 0){
			return false;
		}
	}
	return true;
}

bool isPrime_new(uint64_t n){
	if (n == 2)
		return false;
	if (n % 2 == 0)
		return false;
	for (uint64_t i = 3; i <= sqrt(n); i++){
		if (n % i == 0)
			return false;
	}
	return true;
}

// 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21
// 2, 3, --, 5, --, 7, --, 9, --, 11, --, 13, --, 15, --, 17, --, 19, --, 21
// 2, 3, --, 5, xx, 7, --, --, --, 11, xx, 13, --, --, --, 17, xx, 19, --, --

void eratosthenes(int n) {

	bool sieve[n]; //初始化0到n
	int num = 0;
	for (int i = 2; i < n; i++)	//都标记为true
		sieve[i] = true;
   	for (int i = 2; i < n; i++) {//忽略0和1.从2开始
      	if (sieve[i]) {
       		cout << i << endl; //最开始打印2.
        for (int j = 2*i; j < n; j += i) //抹除 2i, 3i, 4i, 5i, ..., n.
        	sieve[j] = false;
        	num ++ ;
    	}
  	}
  	cout << "the number of prime that less than " << n << " is " << num << endl;

}

void eratosthenes_better(int n){
	bool sieve[n];
	int num = 0;
	for (int i = 2; i<n; i++){
		sieve[i] = true;
	}
	for (int i = 2; i<n ; i++){
		if (sieve[i]){
			cout << i << endl;
			num++ ;
		}
		if (i == 2){
			for (int j = i*i; j < n ; j += i){
				sieve[j] = false;
			}
		}
		else{
			for (int j = i*i; j < n ; j += 2 * i){
				sieve[j] = false;
			}
		}
		
	}
	cout << "the number of prime that less than " << n << " is " << num << endl;
}

int improvedEratosthenes(uint64_t n){
	bool isPrime[n+1];
	uint64_t num_Prime = 0;
	for (uint64_t i = 2; i <= n; i++){ // 2 and all odd number are signed true
		if(i == 2 || i % 2 == 1){
			isPrime[i] = true;
		}
		else{ // even number except 2 are signed false
			isPrime[i] = false;
		}
	}
	for (uint64_t i = 3; i <= n; i += 2){ //calculate number of prime and remove non-prime odd number
		if(isPrime[i]){
			//cout << i << " ";
			num_Prime++;
		}
		for (uint64_t j = i*i; j <= n ; j += 2 * i)
			isPrime[j] = false;
	}
	//cout << endl;
	cout << "the number of prime that less than or equal to " << n << " is " << num_Prime+1 << endl;
	return num_Prime+1; 
}

int main(){
	int n;
	while(true){
		cout << "input a number: ";
		cin >> n;
		if(n < 0){
			break;
		}
		cout << "#### eratosthenes ####" << endl;
		improvedEratosthenes(n);
		cout << "######################" << endl;
		if(n >= 1){
			cout << "the fibo of number " << n << " is " << fibo(n) << endl;
			
		}
		cout << "another function of fibo:" << endl;
		cout << "the fibo of number " << n << " is " << fibo_better(n) << endl;
		cout << "######################" << endl;
		if (isPrime_new(n))
			cout << n << " is a prime number" << endl;
		else
			cout << n << " is not a prime number" << endl;
	}
}

