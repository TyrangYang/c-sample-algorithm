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
				next[i] = nullptr;
		};
		~trieNode(){};
		trieNode* next[26];
		bool isWord;
	};

	void deleteNode(trieNode* p){
		for (int i = 0; i < 26; ++i)
		{
			if(p->next[i] != nullptr)
				deleteNode(p->next[i]);
		}
		delete p;
	}

public:
	TrieDictionary(){
		root = new trieNode();
	};
	~TrieDictionary(){
		for (int i = 0; i < 26; ++i)
		{
			if(root -> next[i] != nullptr)
				deleteNode(root -> next[i]);
		}
	};

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
	f.close();


	ifstream test("dict_test.txt");
	string testword;
	while(!test.eof()){
		test >> testword;
		cout << "Test word is: " << testword << "\t";
		cout << "isContains: " << td.isContains(testword) << "\t";
		cout << "isContainsPrefix: " << td.isContainsPrefix(testword) << endl;
	}

	return 0;
}