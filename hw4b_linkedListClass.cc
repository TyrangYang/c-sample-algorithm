#include <iostream>
#include <vector>
using namespace std;

class LinkedList2
{
private:
	class LinkedListNode
	{
	public:
		LinkedListNode(){}
		~LinkedListNode(){}
		int val;
		LinkedListNode* next;
	};
	LinkedListNode* head;
	LinkedListNode* tail;
public:
	LinkedList2():head(nullptr), tail(nullptr){}
	~LinkedList2(){
		LinkedListNode* pointer = head;
		LinkedListNode* temp; 
		if(pointer == nullptr)
			return;
		while(pointer != nullptr){
			temp = pointer;
			pointer = pointer -> next;
			delete temp;
		}
	}

	void addStart(int val){
		LinkedListNode* temp = new LinkedListNode;
		temp -> val = val;
		temp -> next = nullptr;
		if(head == nullptr)
			head = tail = temp;
		else{
			temp -> next = head;
			head = temp;
		}
	}

	void addEnd(int val){
		LinkedListNode* temp = new LinkedListNode;
		temp -> val = val;
		temp -> next = nullptr;
		if(tail == nullptr)
			head = tail = temp;
		else{
			tail -> next = temp;
			tail = temp;
		}
	}

	void removeStart(){
		if(head == tail){
			if(head == nullptr){
				cout << "remove start fail" << endl;
				return;
			}
			else{
				LinkedListNode* temp = head;
				head = tail = nullptr;
				delete temp;
			}
		}
		else{
			LinkedListNode* temp = head;
			head = head -> next;
			delete temp;
		}
	}
	
	void removeEnd(){
		if(head == tail){
			if(tail == nullptr){
				cout << "remove end fail" << endl;
				return;
			}
			else{
				LinkedListNode* temp = tail;
				head = tail = nullptr;
				delete temp;
			}
		}
		else{

			LinkedListNode* pointer = head;
			while(pointer -> next != tail){
				pointer = pointer -> next;
			}
			delete tail;
			tail = pointer;
			tail -> next = nullptr;
		}
	}

	int getStartVal(){
		if(head == nullptr)
			return -1;
		return head->val;
	}

	int getTailVal(){
		if(tail == nullptr)
			return -1;
 		return tail->val;
	}

	void OUTPUT(){
		if(head == nullptr)
			cout << "nothing" << endl;
		else{
			LinkedListNode* temp = head;
			while(temp != nullptr){
				cout << temp->val << " ";
				temp = temp -> next;
			}
			cout << endl;
		}
	}

	void ADD_FRONT(int start, int step, int end){
		if(start > end || end - start < step || step < 0){
			cout << "error! add fail" << endl;
			return;
		}
		if(step == 0 && start != end){
			cout << "error! add fail" << endl;
			return;
		}
		if(step == 0 && start == end){
			addStart(start);
			return;
		}
		for(int i = start; i <= end; i += step){
			addStart(i);
		}
	}

	void ADD_BACK(int start, int step, int end){
		if(start > end || end - start < step || step < 0){
			cout << "error! add fail" << endl;
			return;
		}
		if(step == 0 && start != end){
			cout << "error! add fail" << endl;
			return;
		}
		if(step == 0 && start == end){
			addEnd(start);
			return;
		}
		for(int i = start; i <= end; i += step){
			addEnd(i);
		}
	}

	void REMOVE_FRONT(int num){
		for (int i = 0; i < num; ++i)
		{
			removeStart();
		}
	}

	void REMOVE_BACK(int num){
		for (int i = 0; i < num; ++i)
		{
			removeEnd();
		}
	}
};


int main(int argc, char const *argv[])
{
	LinkedList2 ls;
	// ls.addStart(1);
	// ls.addStart(2);
	// ls.addStart(100);
	// ls.addEnd(9);
	// ls.addEnd(8);
	// ls.removeStart();
	// ls.removeEnd();
	ls.ADD_FRONT(1,2,10);
	ls.ADD_BACK(5,5,25);
	// cout << "start: " << ls.getStartVal() << endl;
	// cout << "end: " << ls.getTailVal() << endl;
	ls.OUTPUT();
	ls.REMOVE_FRONT(2);
	ls.REMOVE_BACK(2);
	ls.OUTPUT();
	// for(int i=0; i < 2; i++){
	// 	cout << head[0] << endl;
	// }
	return 0;
}