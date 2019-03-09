/*
HW3 - insertionSort 
Author: Haolin Yang
*/
#include <iostream>
#include <fstream>
using namespace std;

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
/*
for(int i = 0; i<n ;i++){
	if(<condition 1>)
		<code 1>
	else
		//nothing
		break;
}
This is equal to:
int i = 0;
while(i < n and <condition 1>){
	<code 1>
}
*/
int main(){
	ifstream f("hw3.dat");
	int num;

	f >> num;
	int seq[num];
	for (int i = 0; i < num ; i++){
		f >> seq[i];
	}

	cout << "the original list:" << endl;
	for(int i = 0; i < num ; i++)
		cout << seq[i] << " ";
	cout  << endl;

	insertionSort(seq,num);

	cout << "the sorted list:" << endl;
	for(int i = 0; i < num ; i++)
		cout << seq[i] << " ";
	cout  << endl;


}