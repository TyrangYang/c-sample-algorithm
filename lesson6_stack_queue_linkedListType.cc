class LinkedList1 {
private:
	class Node
	{
	public:
		Node();
		~Node();
		int val;
		Node* next;
	};
	Node* head;
public:
	void addFirst(int v); //O(1)
	void addEnd(int v);//O(n)
	int removeFirst(); //O(1)
	int removeEnd(); //O(n)
	int size() const;	//O(n)
	bool isEmpty(); //O(1)
}

class LinkedList2 {
private:
	class Node
	{
	public:
		Node();
		~Node();
		int val;
		Node* next;
	};
	Node* head;
	Node* tail;
public:
	void addFirst(int v); //O(1)
	void addEnd(int v);//O(1)
	int removeFirst(); //O(1)
	int removeEnd(); //O(n) because do not have prev
	int size() const;	//O(n)
	bool isEmpty(); //O(1)
}

class LinkedList3 {
private:
	class Node
	{
	public:
		Node();
		~Node();
		int val;
		Node* next;
		Node* prev
	};
	Node* head;
public:
	void addFirst(int v); //O(1)
	void addEnd(int v);//O(1)
	int removeFirst(); //O(1)
	int removeEnd(); //O(n) because do not have prev
	int size() const;	//O(n)
	bool isEmpty(); //O(1)
}

class LinkedList4 {
private:
	class Node
	{
	public:
		Node();
		~Node();
		int val;
		Node* next;
		Node* prev
	};
	Node* head;
	Node* tail;
public:
	void addFirst(int v); //O(1)
	void addEnd(int v);//O(1)
	int removeFirst(); //O(1)
	int removeEnd(); //O(1)
	int size() const;	//O(n)
	bool isEmpty(); //O(1)
}

class stack
{
private:
	LinkedList1 imp1;
public:
	stack();
	~stack();
	void push(int v){
		imp1.addFirst(v);
	}
	void pop(){
		return imp1.removeFirst();
	}
	bool isEmpty(){
		return imp1.isEmpty();
	}
};