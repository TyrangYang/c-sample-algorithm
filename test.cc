#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>

using namespace std;



int main(int argc, char const *argv[])
{
	string s = "aword";
	cout << s << " " << s.length() << endl;
	for (int i = 0; i < s.length(); ++i)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	char c = 'A';
	char a = tolower(c);
	cout << a << " " << c << endl;
	int test = c - s[0];
 	cout << test << endl;
	return 0;
}

