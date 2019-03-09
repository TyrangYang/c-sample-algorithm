/*
HW1 - Prime 
Author: Haolin Yang
*/

#include <iostream>
#include <cmath>
using namespace std;

int improvedEratosthenes(int n){
  bool* isPrime = new bool[n+1];
  int num_Prime = 0;
  for (int i = 2; i <= n; i++){ // 2 and all odd number are signed true
    if(i == 2 || i % 2 == 1){
      isPrime[i] = true;
    }
    else{ // even number except 2 are signed false
      isPrime[i] = false;
    }
  }
  for (int i = 3; i <= n; i+=2){ //calculate number of prime and remove non-prime odd number
    if(isPrime[i]){
      //cout << i << " ";
      num_Prime++;
      for (uint64_t j = i*i; j <= n ; j += 2 * i)
        isPrime[j] = false;
    }
  }
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