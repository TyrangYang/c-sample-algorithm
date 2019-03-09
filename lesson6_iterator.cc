#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> a;
	const int n = 10;
	a.reserve(n);
	for (int i = 0; i< n; i++)
		a.push_back(i);
	for(int i = 0; i <n ; i++)
		cout << a[i] << endl
	cout << endl;


	for (vector<int> :: iterator i = a.begin(); i != a.end(); ++i)
		cout << *i << " ";
	cout << endl;

	for (auto x : a)
		cout << x << ' ';
	cout << endl;

	return 0;
}