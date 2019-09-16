#include <iostream>
#include <vector>
#include <string>

using namespace std;

int boyerMoore(const string& search, const string& target){
	int len_target = target.size();
	int len_search = search.size();
	vector<int> offsets(256, len_target); // offset 

	for (int i = 0; i < len_target; ++i)
	{
		offsets[target[i]] = len_target - i - 1;
	}

	for (int i = len_target - 1; i < len_search;)
	{
		int jump = offsets[search[i]];
		if(jump == 0){ // the last char in target is match
			int j = 0;
			for(; j < len_target; j ++){
				if(search[i - j] != target[len_target - 1 - j])
					break;
			}
			if(j == len_target)
				return i - (len_target - 1);
			i++;
		}
		else{
			i += jump;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	string target = "voltage";
	string search = "brigandroltage aged. voltage";

	int res = boyerMoore(search, target);

	cout << res << endl;
	return 0;
}