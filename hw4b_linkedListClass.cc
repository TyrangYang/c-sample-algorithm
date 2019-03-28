#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// template <typename T>
class LinkedList2
{
private:
	class LinkedListNode
	{
	public:
		LinkedListNode(){}
		LinkedListNode(int val, LinkedListNode* next): val(val), next(next){}
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

	class const_iterator
	{
	private:
		LinkedList2& list;
		LinkedListNode* temp;
	public:
		const_iterator(LinkedList2& list): list(list), temp(list.head){}
		~const_iterator(){};

		bool operator !() const {
			if(temp != nullptr)
				return true;
			// if(temp -> next != nullptr)
			// 	return true;
			return false;
		}

		void operator ++() {
			temp = temp -> next;
		}
		
		int operator *() const {
			return temp -> val;
		}
	};

	friend ostream& operator <<(ostream& s, LinkedList2& list){
		for (LinkedList2::const_iterator i(list); !i; ++i)
		{
			s << *i << " ";
		}
		return s;
	}
};


int main(int argc, char const *argv[])
{
	LinkedList2 ls;

	ifstream f("HW4b.txt");
	string oneline;
	while(!f.eof()){
		getline(f,oneline);
		replace(oneline.begin(), oneline.end(), ':', ' ');
		istringstream linestr(oneline);
		string cmd;
		int a, b, c;
		linestr >> cmd >> a >> b >> c;
		if(cmd == "ADD_FRONT"){
			ls.ADD_FRONT(a, b, c);
			continue;
		}
		if(cmd == "ADD_BACK"){
			ls.ADD_BACK(a, b, c);
			continue;
		}
		if(cmd == "REMOVE_FRONT"){
			ls.REMOVE_FRONT(a);
			continue;
		}
		if(cmd == "REMOVE_BACK"){
			ls.REMOVE_BACK(a);
			continue;
		}
		if(cmd == "OUTPUT"){
			cout << ls << endl;
		}
	}

	// ls.OUTPUT();

	// for (LinkedList2 :: const_iterator i(ls); !i; ++i)
	// {
	// 	cout << *i << " ";
	// }
	return 0;
}