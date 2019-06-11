#include <iostream>
#include <string>

using namespace std;


class Solution
{
public:
	bool isPolindrome(string input){
		int i = 0;
		int j = input.size() - 1;

		while(i > j){
			char head = input[i];
			char tail = input[j];
			if(head != tail){
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
};


int main(int argc, char const *argv[])
{
    
}