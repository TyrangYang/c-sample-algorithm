/*
HW1 - Prime 
Author: Haolin Yang
*/

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
// - 2 3 - 5 - 7 - 9 -- 11 -- 13 -- 15 // remove even
// - 2 3 - 5 - 7 - - -- 11 -- 13 -- 15 // i = 3
// for i = 3. we start from i*i since (i-x)i has already checked. 
// we step 2i since we don't need to calculate the even number.
#include <iostream>
#include <cmath>
using namespace std;

int improvedEratosthenes(uint64_t n){
  bool* isPrime = new bool[n+1];
  // bool isPrime[n+1];
  uint64_t num_Prime = 0;
  for (uint64_t i = 2; i <= n; i++){ // 2 and all odd number are signed true
    if(i == 2 || i % 2 == 1){
      isPrime[i] = true;
    }
    else{ // even number except 2 are signed false
      isPrime[i] = false;
    }
  }
  for (uint64_t i = 3; i <= n; i+=2){ //calculate number of prime and remove non-prime odd number
    if(isPrime[i]){
      //cout << i << " ";
      num_Prime++;
      for (uint64_t j = i*i; j <= n ; j += 2 * i)// improve from for(uint64_t j=i; j<=n; j+=i)
        isPrime[j] = false;
    }
  }
  delete[] isPrime;
  return num_Prime + 1; // start from 3. add 1 for conuting the number 2.
}

int main(){
	int n;
  //while(true){
  cout << "Please input a number: ";
  cin >> n;
  if(n < 0){
    cout << "Prime number must be positive." << endl;
  }
  else
      cout << "the number of primes less than or equal to " << n << " is " << improvedEratosthenes(n) << endl;
  //}
	
}