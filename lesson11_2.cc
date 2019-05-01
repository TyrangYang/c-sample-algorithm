


int lcs (const char* A, const char* B){ // O(2^n)
	if(*A == '\0' || *B == '\0')
		return 0;
	else if(*A == *B)
		return 1+lcs(A+1, B+1);
	else
		return max(lcs(A+1, B), lcs(A, B+1));
}


