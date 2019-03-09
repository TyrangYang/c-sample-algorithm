#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <ctime>
using namespace std;

default_random_engine generator;
int randomInt(int L, int R){
    uniform_int_distribution<int> random(L, R);
    return random(generator);
}

void quickSort(int x[], int L, int R, int k){//K mast larger than or equal to 1.
    if(k < 1){ // k means accuracy. (Every sets with k's elements are sorted)
        throw "error"; 
    }
    int pivotIndex = randomInt(L, R);
    int pivot = x[pivotIndex];
    int i = L , j = R;

    //swap the pivot to the end. Because, your scan from left first and calculate all number that equal to pivot
    int temp = x[pivotIndex];
    x[pivotIndex] = x[R];
    x[R] = temp;
    while(i < j){
        while(x[i] < pivot && i < j)
            i++;
        while(x[j] >= pivot && i < j)
            j--;
        if(i < j) {
            temp = x[j];
            x[j] = x[i];
            x[i] = temp;
            // i++;
        }
    }

    //swap the pivot back
    temp = x[R];
    x[R] = x[i];
    x[i] = temp;

    if((i-1) - L >= k) // left of pivot
        quickSort(x, L, i, k);
    if(R - (i+1) >= k) // right of pivot
        quickSort(x, i+1, R, k);
}

void insertionSort(int x[], int n){
    for (int i = 1; i < n ; i++){
        if (x[i - 1] > x[i]){
            int temp = x[i];
            int j = i-1;
            while (j >= 0 && x[j] > temp) {
                x[j+1] = x[j];
                j--;
            }
            x[j+1] = temp;
        }
    }
}

void knuthQuickSort(int x[] , int num, int k){
    quickSort(x,0,num-1,k);
    insertionSort(x,num);
}

bool isSorted(int* x, int n) {
    for(int i = n-1; i>0;i--){
        if(x[i]<x[i-1])
            return false;
    }
    return true;
}

const double pui = (1+sqrt(5))/ 2 ;
#if 0
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
	int S = (R - L)/pui;
	int x = R - S, y = L + S;

	while(S != 0){
		if (data[x] > data[y]){
			R = y;
			y = x;
			S = (R - L) / pui;
			x = R - S;
		}
		else{
			L = x;
			x = y;
			S = (R-L) / pui;
			y = L + S;
		}
	}

	if(data[L] >= data[R])
		return L;
	else
		return R;
}
#endif

int findK_goldenMean(int k_start, int k_end, int k_interval,int data[], int num){
	int L = 0, R = (k_end - k_start) / k_interval + 1 - 1;  // (k_end - k_start) / k_interval + 1 = n
	int S = (R - L)/pui;
	int x = R - S, y = L + S;
	int copyData[num];

	while(S != 0){
		for(int i=0; i<num; ++i)
	        copyData[i] = data[i];

		clock_t start;
	    double timex;
	    start = clock();
		knuthQuickSort(copyData,num,k_start + x * k_interval);
		timex = ( clock() - start ) / (double) CLOCKS_PER_SEC;

		for(int i=0; i<num; ++i)
	        copyData[i] = data[i];
	    double timey;
	    start = clock();
		knuthQuickSort(copyData,num,k_start + y * k_interval);
		timey = ( clock() - start ) / (double) CLOCKS_PER_SEC;
		cout << "L= " << L << "  x= " << x << "  y= " << y << "  R= " << R << endl;
		cout << "K_x= " << k_start + x * k_interval << "  K_y= " << k_start + y * k_interval << endl;
		cout << "time_x= " << timex << "  time_y= " << timey << endl;
		cout << "*************" << endl;
		if (timex < timey){
			R = y;
			y = x;
			S = (R - L) / pui;
			x = R - S;
		}
		else{
			L = x;
			x = y;
			S = (R-L) / pui;
			y = L + S;
		}
	}

	for(int i=0; i<num; ++i)
        copyData[i] = data[i];
    clock_t start;
    double timeL;
    start = clock();
	knuthQuickSort(copyData,num,k_start + L * k_interval);
	timeL = ( clock() - start ) / (double) CLOCKS_PER_SEC;

	for(int i=0; i<num; ++i)
        copyData[i] = data[i];
    double timeR;
    start = clock();
	knuthQuickSort(copyData,num,k_start + R * k_interval);
	timeR = ( clock() - start ) / (double) CLOCKS_PER_SEC;

	cout << "L= " << L << "  x= " << x << "  y= " << y << "  R= " << R << endl;
	cout << "K_L= " << k_start + L * k_interval << "  K_R= " << k_start + R * k_interval << endl;
	cout << "time_L= " << timeL << "  time_R= " << timeR << endl;
	cout << "*************" << endl;
	if(timeL <= timeR)
		return L;
	else
		return R;
}

int main(int argc, char const *argv[])
{
	const int k_start = 400;
	const int k_end = 2400;
	const int k_interval = 50;
	ifstream f("test.dat");
    int num;
    f >> num;

    int seq[num];
    for(int i = 0; i < num; i++)
        f >> seq[i];

    int index = findK_goldenMean(k_start,k_end,k_interval,seq,num);
    cout << "######## result ########" << endl;
    cout << "K = " <<  k_start + index * k_interval << endl;
	return 0;
}
#if 0
int main(){
	const int k_start = 400;
	const int k_end = 2300;
	const int k_interval = 50;
	double time[(k_end - k_start) / k_interval + 1];
	int i = 0;
	for(int k = k_start; k<=k_end ;k+=k_interval){
	    ifstream f("test.dat");
	    int num;
	    f >> num;

	    int seq[num];
	    for(int i = 0; i < num; i++)
	        f >> seq[i];

		clock_t start;
	    double duration;

	    start = clock();
	    // insertionSort(seq , num);
	    // quickSort(seq, 0, num-1, 1);
	    knuthQuickSort(seq,num,k);
	    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

	   	time[i] = 1 - duration;
	   	i++;
	    cout<<"K: "<< k<< "  Time: "<< duration << endl;

	    f.close();
	}

	cout << "############" << endl;
	// for(int i = 0; i < (k_end - k_start) / k_interval + 1; i++){
	// 	cout << "k: "<< k_start + k_interval * i << "  1 - Time: " << time[i] << endl; 
	// }
	int index = goldenMeanSearch(time, (k_end - k_start) / k_interval + 1);
	cout << "K = " <<  k_start + index * k_interval << " time: "<< 1- time[index] << endl;
}
#endif