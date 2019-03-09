#include <iostream>
#include <string>
#include <map>
using namespace std;

//g++ -g c++map.cc

int main(int argc, char const *argv[])
{
	map<string, double> stock;
	stock["IBM"] = 119.5;
	stock["apple"] = 152;
	stock["bidu"] = 138;

	for(map<string, double>:: iterator i = stock.begin(); i!= stock.end();++i){
		cout << i -> first << " ==> " << i -> second << endl;
	}
	cout << endl;
	for(auto p:stock){
		cout << p.first << " ==> " << p.second << endl;
	}
	return 0;
}