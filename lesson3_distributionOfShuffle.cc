#include <iostream>
#include <random>
#include <iomanip>
#include <cmath>
using namespace std;

default_random_engine generator;

#if 0
void insertionSort(int x[], int n){
	for(int i = 1; i < n; i++){
		if(x[i] < x[i-1]){
			int temp = x[i];
			int j = i-1;
			while(j >= 0 && x[j] > temp){
				x[j+1] = x[j];
				j--;
			}
			x[j+1] = temp;
		}
		
	}
}
#endif

void showArray(int x[], int n){
	for(int i = 0; i< n; i++){
		cout << x[i] << " ";
	}
	cout << endl;

}

void FischerYates(int x[], int n){
	int index;
	for(int i = n-1; i > 0; i--){
		uniform_int_distribution<int> random(0, i);
		index = random(generator);
		swap(x[i],x[index]);
	}
}

void unfair(int x[], int n){
	int index;
	for (int i = 0; i<n ;i++){
		uniform_int_distribution<int> random(0, n-1);
		index = random(generator);
		swap(x[i],x[index]);
	}
}

double variance(int x[], int n){
	double average;
	int sum=0;
	double variance = 0;
	for(int i=0; i<n ; i++){
		sum += x[i];
	}
	average = double(sum) / n;
	// cout << average <<endl;

	for(int i = 0; i<n ; i++){
		variance += pow(double(x[i]) - average, 2);
	}
	return variance = variance / n;
}	



int main(int argc, char const *argv[])
{	
	const int array_len = 10;
	const int shullfe_time = 1000000;
	// cout << setprecision(4);
	// FischerYates
	int distribution_fisherYates[array_len][array_len] = {0};
	double variance_fisherYates[array_len] = {0};
	
	for(int i = 0; i < shullfe_time; i++){
		int original[array_len] = {0,1,2,3,4,5,6,7,8,9};
		FischerYates(original,array_len);

		for(int j = 0; j < array_len; j++){
			int num = original[j];
			distribution_fisherYates[j][num]++;
		}
	}

	cout << "########    FischerYates    ########" << endl;
	for(int i = 0; i < array_len; i++){
		cout << "Place" << i << ": " << " ";
		for(int j = 0; j < array_len; j++){
			cout << j << ":" << double(distribution_fisherYates[i][j])/double(shullfe_time)*100 << "%" << "  ";
			// cout << double(distribution_fisherYates[i][j])/double(shullfe_time) << "  ";
		}

		variance_fisherYates[i] = variance(distribution_fisherYates[i],array_len);
		cout << endl;
	}
	double sum_fisherYates = 0;
	for(int i = 0; i < array_len; i++){
		sum_fisherYates += variance_fisherYates[i];
	}
	cout << "Standard Deviation: " << sqrt(sum_fisherYates/array_len) << endl;
	cout << endl;


	// unfair
	int distribution_unfair[array_len][array_len] = {0};
	double variance_unfair[array_len] = {0};

	for(int i = 0; i < shullfe_time; i++){
		int original[array_len] = {0,1,2,3,4,5,6,7,8,9};
		unfair(original,array_len);
		
		for(int j = 0; j < array_len; j++){
			int num = original[j];
			distribution_unfair[j][num]++;
		}
	}

	cout << "########    unfair    ########" << endl;
	for(int i = 0; i < array_len; i++){
		cout << "Place" << i << ": " << " ";
		for(int j = 0; j < array_len; j++){
			cout << j << ":" << double(distribution_unfair[i][j])/double(shullfe_time)*100 << "%" << "  ";
			// cout << double(distribution_fisherYates[i][j])/double(shullfe_time) << "  ";
		}
		variance_unfair[i] = variance(distribution_unfair[i],array_len);
		cout << endl;
	}
	
	double sum_unfair = 0;
	for(int i = 0; i < array_len; i++){
		sum_unfair += variance_unfair[i];
	}
	cout << "Standard Deviation: " << sqrt(sum_unfair/array_len) << endl;

	return 0;
}
