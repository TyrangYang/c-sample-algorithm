#include <iostream>
#include <random>
#include <fstream>
using namespace std;





int main(int argc, char const *argv[])
{
	const int num = 1000000;
	const int biggest = 1000;
	default_random_engine generator;
	uniform_int_distribution<int> rand(0,biggest);
	

	ofstream f("test.dat");
	f << num;
	f << '\n';
	for(int i = 0; i < num; i++){
		f << rand(generator) << " ";
	}
	return 0;
}