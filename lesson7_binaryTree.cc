#include <iostream>
using namespace std;

class BinaryTree
{
private:
	class TreeNode
	{
	public:
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode* parent;
		TreeNode(int v) : val(v), parent(nullptr), left(nullptr), right(nullptr){}
		TreeNode(int v, TreeNode* parent){
			val = v;
			parent = parent;
			left = nullptr;
			right = nullptr;
		}
		~TreeNode(){};
	};
	
public:

	TreeNode* root;
	BinaryTree():root(nullptr){}
	~BinaryTree(){}

	void add(int v){
		if(root == nullptr){
			root = new TreeNode(v);
			return;
		}

		TreeNode* temp = root;

		while(temp != nullptr){
			if(v <= temp -> val){
				if(temp -> left == nullptr){
					TreeNode* newTNode = new TreeNode(v,temp);
					temp -> left = newTNode;	
					return;
				}else{
					temp = temp -> left;
					continue;
				}
			}else{
				if(temp -> right == nullptr){
					TreeNode* newTNode = new TreeNode(v, temp);
					temp -> right = newTNode;
					return;
				}else{
					temp = temp -> right;
					continue;
				}
			}
		}		
	}

	void printInorder(TreeNode* n){
		if(n == nullptr)
			return;
		printInorder(n -> left);
		cout << n -> val << " ";
		printInorder(n -> right);
	}

	void printPreorder(TreeNode* n){
		if(n == nullptr)
			return;
		cout << n -> val << " ";
		printPreorder(n -> left);
		printPreorder(n -> right);
	}

	void printPostorder(TreeNode* n){
		if(n == nullptr)
			return;
		printPostorder(n -> left);
		printPostorder(n -> right);
		cout << n -> val << " ";
	}
	
};


int main(int argc, char const *argv[])
{
	BinaryTree t;
	t.add(4);
	t.add(2);
	t.add(1);
	t.add(3);
	t.add(6);
	t.add(5);
	t.add(7);
	t.printInorder(t.root);
	cout << endl;
	t.printPreorder(t.root);
	cout << endl;
	t.printPostorder(t.root);
	cout << endl;

	
	return 0;
}