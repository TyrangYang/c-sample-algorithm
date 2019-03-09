/*The biggest bug is the condition of while loop.
The original condition is L>R. It is wrong since L will never larger than R.

Here is the proof:
Since S>0 and x = R - s, x always smaller than R.
Suppose you always shrink the array to the right, L will keep replacing x.
But x always smaller than R. L will always smaller than R.
Similarly, when you shrink the array to the left, we can proof R always larger than L.

Actually, the while loop will stop when L is contiguous to R.
Therefore, the condition is L+1>=R or S!=0 which I think is better.

Moreover, there are still have two problem in original version.

First, this algorithm will fail when length of array is small or equal to 4.
Suppose the length is 4. L = 0, R = 3. S = 1.
Now x = 2, y = 1. 
Algorithm fail since x should never larger then y. 

To fix this bug. Just loop all elements and find the max, because there are only 4 elements.

Second, return data[L] is incorrect.
we already proof that this algorithm shrink array to 2 that L is close to R.
But we do not know whether data[L] is bigger or not.
Therefore, we need to compare the last two and return the larger one.*/

#include <iostream>
#include <random>
#include <cmath>
using namespace std;

const double phi = (1+sqrt(5))/ 2 ;

int goldenMeanSearch(double data[], int n){
	if(n <= 4){
		double max = data[0];
		for(int i = 1; i < n; i++){
			if(max < data[i])
				max = data[i];
		}
		return max;
	}

	int L = 0, R = n-1;
	int S = (R - L)/phi;
	int x = R - S, y = L + S;

	while(S != 0){
		if (data[x] < data[y]){
			R = y;
			y = x;
			S = (R - L) / phi;
			x = R - S;
		}
		else{
			L = x;
			x = y;
			S = (R-L) / phi;
			y = L + S;
		}
	}

	if(data[L] <= data[R])
		return L;
	else
		return R;
}

int main(){
	int data[] = {1,2,3,4,5,6,7,8};
	// double data[] = {0.296647,0.284442,0.258755,0.243175,0.230389,0.211534,0.185993,0.164147,0.142713,0.11538,0.089589,0.062466,0.042204,0.03575,0.034408,0.035126,0.035204,0.035483,0.035021,0.035645,0.035416,0.036726,0.03517,0.03516,0.034614,0.034816,0.036161,0.03515,0.036643,0.035673,0.036606,0.047222,0.08148,0.113591,0.124631,0.123595,0.125999,0.126745,0.125287};
	int index = goldenMeanSearch(data, sizeof(data)/sizeof(double));
	cout << index << '\n';
	cout << 400 + index*50  <<" "<< sizeof(data)/sizeof(double) << endl;
}