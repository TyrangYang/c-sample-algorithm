#include <iostream>
#include <string>
#include <map> // RB-tree. // waste space since need many extra message
//but for many operation. map will be fast. O(logn)
#include <unordered_map>// hash table. //search fast. But other operation not good.
using namespace std;

//g++ -g c++map.cc

int main(int argc, char const *argv[])
{
	unordered_map<string, double> stock;
	stock["apple"] = 152;
	stock["IBM"] = 119.5;
	stock["baidu"] = 138;
	stock["apple"] = 1;

	for(unordered_map<string, double>:: iterator i = stock.begin(); i!= stock.end();++i){
		cout << i -> first << " ==> " << i -> second << endl;
	}
	cout << endl;
	
	for(auto p:stock){
		cout << p.first << " ==> " << p.second << endl;
	}


	map<int, int> a;
	for (int i = 10; i > 0; i--)
		a[i] = i;



	for (map<int, int>::iterator i = a.begin(); i != a.end(); ++i)
	{
		 cout << i-> second << '\n';
	}
	return 0;
}