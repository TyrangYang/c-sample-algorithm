#include <iostream>
#include <bitset>
using namespace std;
int main(int argc, char const *argv[])
{
	bitset<8> test(123);
	int test2 = 123;

	cout << sizeof(test) << endl;
	cout << sizeof(test2) << endl;

	cout << test << endl;
	
	for (int i = 0; i < 8; ++i)
	{
		cout << test[i] << ' ';
	}

	
	return 0;
}