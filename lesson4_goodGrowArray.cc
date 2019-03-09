#include <iostream>
using namespace std;

template <typename T>
class goodGrowArray
{
private:
	T* data;
	int len;
	int capacity;
	void grow(){
		T* old = data;
		data = new T[2*capacity+1];
		capacity = 2*capacity+1;
		for(int i = 0; i < len; i++){
			data[i] = old[i];
		}
		delete[] old;
	}
public:
	goodGrowArray() : data(nullptr), len(0), capacity(0){}
	goodGrowArray(int capacity): data(new T[0]), len(0), capacity(capacity){}
	~goodGrowArray(){
		delete[] data;
	}
	
	void insert(int pos, T val){
		if(len >= capacity)
			grow();
		T* old = data;
		data = new T[len + 1];
		for(int i = 0; i < pos; i++)
			data[i] = old[i];
		data[pos] = val;
		for(int i = pos; i < len; i++)
			data[i + 1] = old[i];
		len++;
		delete[] old;
	}

	void insertEnd(T val){
		if(len >= capacity){
			grow();
			// cout << "Growed capacity " << capacity << endl;
		}
		data[len++] = val;
	}

	void insertStart(T val){
		if(len >= capacity)
			grow();
		T* old = data;
		data = new T[len + 1];
		data[0] = val;
		for(int i = 0; i<len; i++)
			data[i + 1] = old[i];
		len++;
		delete[] old;
	}

	void remove(int pos){
		if(len <= 0)
			return;
		T* old = data;
		data = new T[len-1];
		for(int i = 0; i < pos; i++)
			data[i] = old[i];
		for(int i = pos + 1; i < len; i++)
			data[i-1] = old[i];
		len--;
		delete[] old;
	}

	void removeEnd(){
		if(len <= 0)
			return;
		len--;
	}

	void removeStart(){
		if(len <= 0)
			return;
		T* old = data;
		data = new T[len-1];
		for(int i = 1; i < len; i++)
			data[i - 1] = old[i];
		len--;
		delete[] old;
	}

	int getlen(){
		return len;
	}

	T* getData(){
		return data;
	}

	int getCapacity(){
		return capacity;
	}

	friend ostream& operator << (ostream &s, const goodGrowArray<T>& list ){
        for (int i = 0; i < list.len; ++i)
        {
        	
        }
    }

};

int main(int argc, char const *argv[])
{
	goodGrowArray<double> a(4);
	
	a.insertStart(10.1);
	a.insertStart(20.1);
	a.insertStart(30.1);
	a.insertStart(40.1);
	a.insert(2, 1111);
	a.remove(3);
	int len = a.getlen();
	int capacity = a.getCapacity();
	double* data = a.getData();
	cout << len << " " << capacity << endl;
	for(int i=0; i<len; i++){
		cout << data[i] <<" ";
	}
	cout << endl;
	return 0;
}