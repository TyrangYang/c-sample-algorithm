
template <typename T>
class linkList{
private:
	class Node{
	public:
		Node* next;
		T val;
		Node(Node* next, const T& v) : next(next), val(v){}
	};
	Node* head;

public:
	linkList() : head(nullptr){}
	// void addStart(const T& val){
	// 	Node* temp = new Node();
	// 	temp -> val = val;  //(*temp).val
	// 	temp -> next = head;
	// 	head = temp;
	// }

	void addStart(const T& val){
		head = new Node(head,val);
	}

	void addEnd (const T& val){
		Node* temp = new Node(nullptr,val);
		Node* p = head;

		if(p == nullptr){
			head = temp;
			return;
		}
		for(; p -> next != nullptr; p = p -> next)
			;
		p -> next = temp;
	}

	void removeStart(){
		Node* temp = head;
		head = head -> next;
		delete temp;
	}

	void removeEnd(){
		Node* p = head;
		Node* q = p -> next;
		if(q==nullptr){
			delete head;
			head == nullptr;
			return;
		}
		for(;q->next!=nullptr;p=q, q= q->next)
			;
		delete p->next;
		p->next = nullptr;
	}
	~linkList(){
		Node* q;
		for(Node* p = head; p != nullptr; p = q){
			q = p-> next;
			delete p;
		}

	}
	linkList(const linkList& orig){
		if(orig.head == nullptr){
			head = nullptr;
			return;
		}
		head = new Node(nullptr,orig.head->val);

		Node* src = orig.head -> next;
		Node* dest = head;

		while(src != null){
			dest->next = new Node(nullptr, src->val);
			dest = dest -> next;
			src = src -> next;
		}
	}

	linkList(linkList&& orig){ //move constructor
		head = orig.head;
		orig.head = nullptr;
	}
};

linkList<int> f(){
	linkList<int> a;
	a.addEnd(5);
	a.addEnd(4);
	return a;
}
int main(int argc, char const *argv[])
{
	linkList<int> a;
	const int n = 10;
	for(int i = 0; i < n ;i++){
		a.addEnd(i);
		a.addStart(i);
	}
	a.removeStart();


	linkList<int> b = a;
	linkList<int> c = f();//need finish
	cout << b << endl;
 	return 0;
}