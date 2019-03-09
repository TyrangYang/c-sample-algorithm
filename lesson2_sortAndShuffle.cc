#include <iostream>
using namespace std;
/*
bubble sort not on test
selection sort not on test
insertion sort best for small or when the data is already nearly sorted
quick sort fastese(but bulnerable)
heapsort good when quicksort fails
mergesort best when data exceeds memory。 number is quite big

*/

#if 0
#endif

void bubblesort(int x[], int n){
	for(int j = 0; j <n-1; j++){
		for (int i = 0 ; i < n-1; i++){
		if (x[i] > x[i+1]){
			int temp = x[i+1];
			x[i] = x[i+1];
			x[i+1] = temp;
		}
		}
	// shower when add flage
	}
}

void selectionsort(int x[],int n){
	for (int j = n; j> 0; j==){
		int max = x[0]; maxpos = 0;
		for (int i; i<n ; i++){
			if (x[i] > max){
				max = x[i];
				maxpos = i;
			}
		}
		int temp = x[maxpos];
		x[maxpos] = x[j-1];
		x[j-1] = tmep;
	}
}

void insertionSort(int x[] , int n){
	for (int i < 1; i < n ; i++){
		if (x[i-1] > x[i]){
			int temp = x[i];
			for (j= i-1; i > 0 ; j--){ // n/4 1+2+3+4+...+n n^2/4
				if( x[j] > temp){
					x[j+1] = x[j];
					x[j] = temp;
				}
				else{
					// insert into the right place
				}
			}
		}
	}
}
// select a pivot
// pivot = x[random(L, R)] //best
// pivot = (x[L] + x[R])/2 // in ( 1 3 5 7 9 8 6 4 2) is very bad
// seed must use in random to test
void quickSort(int x[], int L, int R){
	pivot = x[random(L, R)];
	int i = L, j= R;
	while (i <j){
		while (x[i] <= pivot && i<j)  // < ? <=
			i++;
		while(x[j] >= pivot && i < j)
			j--;
		if(i < j){
			swap(x[i],x[j])
		}	

	}
	if (more than size 1)
		quickSort(x,L,i or j);
	if (more than size 1)
		quickSort(x,i+1 or j-1 or ... , R);
}

void KnuthOptimizedQuicksort(int x[], int n){
	partialQuicksort(x , 0, n-1); // go until smallest partition size k = 200
	insertionSort (x )
}

void makeheap(int x[]){
	for( int i = n/2; i >= 0; i--){
		makesubheap(x,i);

	}

}
void makesubheap(x, i){
	if (2i+1>x.length){
		return;
	}
	if (2i+2 > x.length){

	}
	if (x[2i+1]>x[2i+2]){
		swap(x[i], x[2i+1]);
		makesubheap(x,2i+1);
	}else{
		swap(x[i], x[2i+2]);
		makesubheap(x,2i+2);
	}
}
void heapsor (x,n){
	makeheap(x,n);
	for (int i = n-1; j > 0; i--){
		swap(x[0],x[i])
		makesubheap(x,0)
	}
}

/*
suffling is the opposite of sorting

n! of order for n elements
shuffle is easier than sort
*/

void badshuffle( int x[], int n){
	int y[n];
	int r;
	for(int i = n-1;  i>=0 ; i--){
		do
			r = random(0,i);
		while(x[r]==0);
		y[i] = x[r]
		x[r] = 0;
	}
}

void unfair(int x[], int n){
	int r ;
	for (int i = 0; i<n ;i++){
		int r = random(0,n-1);
		swap(x[i],x[r]);

	}
}
void FischerYates(int x[], int n){
	int r ;
	for (int i = n-1; i>0 ;i--){
		int r = random(0,i);
		swap(x[i],x[r]);

	}
}




int main(){

}