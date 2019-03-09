/*
HW3 - QuickSort and KnuthQuickSort
Author: Haolin Yang
*/
#include <iostream>
#include <fstream>
#include <random>
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
int main(){
    // ifstream f("hw3.dat");
    ifstream f("test.dat");
    int num;
    f >> num;

    int seq[num];
    for(int i = 0; i < num; i++)
        f >> seq[i];

    // cout << "the original list:" << endl;
    // for(int i = 0; i < num ; i++)
    //     cout << seq[i] << " ";
    // cout << endl;

    // insertionSort(seq , num);
    // quickSort(seq, 0, num-1, 1);
    knuthQuickSort(seq,num,1800);
    
    // cout << "the sorted list:" << endl;
    // for(int i = 0; i < num ; i++){
    //     cout << seq[i] << " ";
    // }
    // cout << endl;

    cout<<"Is it sorted?: "<< endl;
    if(isSorted(seq,num))
        cout<< "YES" <<endl;
    else
        cout << "NO" << endl;


}