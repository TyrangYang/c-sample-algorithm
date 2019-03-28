#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class TrieDictionary
{
private:
	class trieNode
	{
	public:
		trieNode(){
			isWord = false;
			for (int i = 0; i < 26; ++i)
			{
				next[i] = nullptr;
			}
		};
		~trieNode(){};
		trieNode* next[26];
		bool isWord;
	};

public:
	TrieDictionary(){
		root = new trieNode();
	};
	~TrieDictionary(){};

	trieNode* root;

	void insert(string word){
		trieNode* temp = root;
		for (int i = 0; i < word.length(); ++i)
		{
			int wordIndex = tolower(word[i]) - 'a';
			if(temp -> next[wordIndex] == nullptr)
				temp -> next[wordIndex] = new trieNode();
			temp = temp -> next[wordIndex];
		}
		temp -> isWord = true;
	}

	bool isContains(string word){
		trieNode* temp = root;
		for (int i = 0; i < word.length(); ++i)
		{
			int wordIndex = tolower(word[i]) - 'a';
			if(temp -> next[wordIndex] == nullptr)
				return false;
			temp = temp -> next[wordIndex];
		}
		return temp -> isWord;
	}

	bool isContainsPrefix(string word){
		trieNode* temp = root;
		for (int i = 0; i < word.length(); ++i)
		{
			int wordIndex = tolower(word[i]) - 'a';
			if(temp -> next[wordIndex] == nullptr)
				return false;
			temp = temp -> next[wordIndex];
		}
		return true;
	}
	
};

int main(int argc, char const *argv[])
{
	TrieDictionary td;
	ifstream f("dict.txt");
	string word;
	while(!f.eof()){
		f >> word;
		td.insert(word);
	}

	cout << td.isContains("zygon") << endl;
	cout << td.isContainsPrefix("CATA") << endl;

	return 0;
}