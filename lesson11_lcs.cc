#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int longestCommonSubstring(const string& A, const string& B){
	int num_col = A.size() + 1; // i
	int num_row = B.size() + 1; // j

	vector<int> dp(num_col * num_row, 0);
	for(int i = 1; i < num_col; i++){
		for (int j = 1; j < num_row; ++j){
			if(A[i - 1] == B [j - 1]){
				dp[j * num_col + i] = dp[(j-1) * num_col + (i - 1)] + 1;
			}
			else{
				dp[j * num_col + i] = max(dp[(j) * num_col + (i - 1)],  dp[(j-1) * num_col + i]);
			}
		}
	}

	return dp[num_col * num_row - 1];
}

int main(int argc, char const *argv[])
{
	string s1 = "string";
	string s2 = "trtrit";

	int res = longestCommonSubstring(s1, s2);
	cout << res << endl;
	return 0;
}

// int lcs (const char* A, const char* B){ // O(2^n)
// 	if(*A == '\0' || *B == '\0')
// 		return 0;
// 	else if(*A == *B)
// 		return 1+lcs(A+1, B+1);
// 	else
// 		return max(lcs(A+1, B), lcs(A, B+1));
// }


