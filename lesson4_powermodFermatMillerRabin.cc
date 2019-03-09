#include <iostream>
#include <cmath>
using namespace std;

int random(int a, int b){
	return a + rand()%(b-a+1);
}

bool isPrime(int n){
	for(int i = 2; i < sqrt(n); i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

//a^n
uint64_t power(uint64_t a, uint64_t n){
	uint64_t prod = 1;
	while(n > 0){
		if(n % 2 != 0)
			prod = prod * a;
		a *= a;
		n /= 2;
	}
	return prod;
}

// a^n mod m
uint64_t powermod(uint64_t a, uint64_t n, uint64_t m){
	uint64_t prod = 1; // a^49 49 = 32 + 16 + 1 = 110001
	while(n > 0){
		if(n % 2 != 0)
			prod = prod * a % m;
		a = a * a % m; // can not be prod = prod * prod % m
		// Because prod * prod will multipul extra a inside. For n = 11, (((prod * a)^2 * a)^2^2 * a)^2. this is wrong
		// However, prod should be prod * a * a^2 * a^8.
		n = n / 2; // compiler n>>=1
	}
	return prod;
}//O(logn)


bool Fermat(uint64_t p, int k){
	for (int i = 0; i < k ;i++){
		uint64_t a = random(2,p-1);
		if(powermod(a,p-1,p) != 1)
			return false;
	}
	return true;//probably?
}//O(klogn) Sigma(logn)
// when a=2, p is Carmichael number. Fermat will be false.
// 2^560 mod 561 = 1. 561 = 3 * 11 * 17ß


// https://www.cnblogs.com/Norlan/p/5350243.html
bool MillerRabin(uint64_t p, int k){
	for (int i = 0; i < k ;i++){
		
		uint64_t a = random(2,p-2);
		uint64_t d = p-1;
		uint64_t s = 0;
		cout << "MillerRabin a= "<< a << " p="<< p<< endl;
		while (d % 2 == 0) {// d & 1 == 0
			s++;
			d /= 2; //d >> =1
		}
		cout <<"d=" << d << "  s=" << s << endl;
		// d*2^s = p-1 (d is odd number)
		// d contains high-order, non-zero bits(stripedd low zreo bits off)
		// s = #of bits that were stripp off
		uint64_t x = powermod(a,d,p);
		cout << "x= " << x << endl;
		if(x == 1 || x == p-1)
			continue;
		for(int j = 0; j < s-1; j++){
			x = x * x % p;
			if (x == 1)
				return false;
			if (x == p-1)
				goto nextTry;
		}
		return false;
		nextTry:;
	}
	return true; // probably?
}
int main(int argc, char const *argv[])
{
	cout << power(2,11) << endl;
	cout << 5 << " " << Fermat(5,3) << "  isPrime " << isPrime(5) << endl;
	cout << 101 << " " << Fermat(101,3) << "  isPrime " << isPrime(101) << endl;
	cout << 103 << " " << Fermat(103,3) << "  isPrime " << isPrime(103) << endl;
	cout << 111 << " " << Fermat(111,3) << "  isPrime " << isPrime(111) << endl;
	cout << 1000 << " " << Fermat(1000, 5) << "  isPrime " << isPrime(1000) << endl;
	cout << 10001 << " " << Fermat(10001, 5) << "  isPrime " << isPrime(10001) << endl;
	cout << 561 << " " << Fermat(561, 5) << "  isPrime " << isPrime(561) << endl; //Carmichael number 3*11*17 
	cout << 1105 << " " << MillerRabin(1105,5) << "  isPrime " << isPrime(1105) << endl;
	return 0;
}