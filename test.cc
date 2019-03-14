#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int test(int val){
	if (val == 1)
		return;
	else
		return val;
}
int main(int argc, char const *argv[])
{
	cout << test(2) << endl;
	cout << test(1) << endl;

	return 0;
}
