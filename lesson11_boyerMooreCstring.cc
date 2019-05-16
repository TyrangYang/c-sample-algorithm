#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int boyerMoore(const char* search, const char* target){
	int lent = strlen(target);
	int lens = strlen(search);
	vector<int> jump(256, lent);

	for (int i = 0; i < lent; ++i)
	{
		jump[target[i]] = lent - 1 - i;
	}

	for(int i = lent - 1; i < lens; ){
		int offset = jump[search[i]];
		if(offset > 0){
			i += offset;
		}
		else{
			int j = 0;
			for (; j < lent; ++j)
			{
				if(target[lent - 1 - j] != search[i - j])
					break;
			}
			if(j == lent){
				return i - lent + 1; 
			}
			i++;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	char search[] = "brigandagevolt aged. voltage";
	char target[] = "voltage";

	int res = boyerMoore(search, target);

	cout << res << endl;
	return 0;
}
