#include <iostream>

class BadGrowArray
{
private:
	int* data;
	int len;
	// int capacity;
	//void grow(){} // double the size
public:
	BadGrowArray(){
		data = nullptr;//?
		len = 0;
	}
	void insert(int pos, int val){
		int* old = data;
		data = new int[len+1];
		for (int i=0; i <pos; i++)
			data[i] = old[i];
		data[pos] = val;
		for(int i=pos+1; i < len; i++)
			data[i] = old[i];
		len ++;
		delete[] old;
	}
	void insertEnd(int val){
		int* old = data;
		data = new int[len+1]; //O(1) in cpp O(len) in java
		for(int i = 0; i <len ; i++){ //O(len)
			data[i] = old[i];
		}
		data[len] = val;
		len++;
		delete[] old;
	}
	void insertStart(int val){
		int* old = data;
		data = new int[len+1];
		data[0] = val;
		for(int i = 1; i <=len ; i++)
			data[i] = old[i-1];
		len++;
		delete[] old;
	}
	void removeStart(){
		int* old = data;
		data = new int[--len];
		for (int i=1; i <= len; i++)
			data[i-1] = old[i];
		delete[] old;
	}
	void removeEnd(){
		len--;
	}
	void rmove(int pos);
	uint32_t size() const;
	int get( int pos);
	void set(int pos,int val);
	list();
	~list();
	
};



int main(int argc, char const *argv[])
{
	BadGrowArray a;
	a.insertEnd(5);
	return 0;
}