#include <iostream>
using namespace std;

class TreeNode
{
private:
	int val;
	TreeNode* left, right;
	TreeNode* parent;
public:
	TreeNode(int v, TreeNode parent){
		val = v;
		parent = parent;
		left = nullptr;
		right = nullptr;
	}
	~TreeNode(){};
};

class Tree
{
private:
	TreeNode root;
public:
	Tree():root(nullptr){}
	~Tree(){}

	void add(int v){
		if(root == null){
			root = new TreeNode(v,p);
		}
		
	}
	
};