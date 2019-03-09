int main(){
	for (i = 0;  i < sqrt(n); i++){

	}
	for (int i = 0; i <n ;i += sqrt(n)){

	}
	for (int i = 0; i < n - sqrt(n); i++){

	}
	for (int i= 1; i<n ; i*=2){ // i is 1 not 0

	}
	for (int i = 1 ; i < n; i*=3){

	}
	// all log are same log2(n) = log3(n)/log2(3)

}


// memoried_

// binomial coefficient

bool isPrime(uint64_t n){
	for (uint64_t i = 2 ; i < n ; i++){
		if (n %i == 0){
			return false;
		}
		return true;
	}
}

bool isPrime2(uint64_t n){
	for (uint64_t i = 2 ; i < n/2 ; i++){
		if (n %i == 0){
			return false;
		}
		return true;
	}
}

bool isPrime3(uint64_t n){
	for (uint64_t i = 2 ; i < sqrt(n) ; i++){
		if (n %i == 0){
			return false;
		}
		return true;
	}
}


