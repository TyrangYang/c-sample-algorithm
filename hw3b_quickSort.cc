#include <iostream>
#include <fstream>
#include <random>
using namespace std;

default_random_engine generator;
int randomInt(int L, int R){
    uniform_int_distribution<int> random(L, R);
    return random(generator);
}

void quickSort(int x[], int L, int R, int k){
    int pivotIndex = randomInt(L, R);
    int pivot = x[pivotIndex];
    int i = L , j = R;

    //swap the pivot to the end. Because, your scan from left first and calculate all number that equal to pivot
    int temp = x[pivotIndex];
    x[pivotIndex] = x[R];
    x[R] = temp;
    while(i < j){
        while(x[i] < pivot && i < j) // reach the first one larger than or equal to pivot
            i++;
        while(x[j] >= pivot && i < j) // reach the last one smaller than pivot. // here must have equal, since the last one is pivot.
            j--;
        if(i < j) {
            int temp = x[j];
            x[j] = x[i];
            x[i] = temp;
//            i++;
        }
    }

    temp = x[R];
    x[R] = x[i];
    x[i] = temp;

    if((i-1) - L > k)
        quickSort(x, L, i, k);
    if(R - (i+1) > k)
        quickSort(x, i+1, R, k);
}


int isSorted(int x[], int n){
    for(int i = n-1; i>0;i--){
        if(x[i]<x[i-1])
            return false;
    }
    return true;
}

int main(){
    ifstream f("hw3.dat");
    int num;
    f >> num;

    int seq[num];
    for(int i = 0; i < num; i++)
        f >> seq[i];

    cout << "the original list:" << endl;
    for(int i = 0; i < num ; i++)
        cout << seq[i] << " ";
    cout  << endl;

    quickSort(seq, 0, num-1, 0);

    cout << "the sorted list:" << endl;
    for(int i = 0; i < num ; i++){
        cout << seq[i] << " ";
    }
    cout  << endl;

    cout<<isSorted(seq,num)<<endl;


}