#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

default_random_engine generator;
int randomInt(int L, int R)
{
	uniform_int_distribution<int> random(L, R);
	return random(generator);
}

void quickSort(vector<int> &willSorted, int left, int right)
{ // [left, rigth)
	int pivotIndex = randomInt(left, right - 1);
	int pivot = willSorted[pivotIndex];

	swap(willSorted[pivotIndex], willSorted[right - 1]);

	auto it = partition(willSorted.begin() + left, willSorted.begin() + right - 1, [pivot](int a) { return a < pivot; });

	int position = it - willSorted.begin();
	swap(it, willSorted[right - 1]);

	if (position - left > 1)
	{
		// cout << " * " <<endl;
		quickSort(willSorted, left, position);
	}
	if (right - 1 - position + 1 > 1)
	{
		// cout << "-" << endl;
		quickSort(willSorted, position + 1, right);
	}

	return;
}

int main(int argc, char const *argv[])
{
	fstream f("hw3.dat");

	int num1;
	f >> num1;

	vector<vector<int>> all;

	for (int i = 0; i < num1; ++i)
	{
		int num2;
		vector<int> one;
		f >> num2;
		for (int j = 0; j < num2; ++j)
		{
			int temp;
			f >> temp;
			one.push_back(temp);
		}
		all.push_back(one);
	}

	for (int i = 0; i < all.size(); ++i)
	{
		quickSort(all[i], 0, all[i].size());
	}

	for (int i = 0; i < all.size(); ++i)
	{
		for (int j = 0; j < all[i].size(); ++j)
		{
			cout << all[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
