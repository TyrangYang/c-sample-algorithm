#include <iostream>
using namespace std;
template<typename T>
class GrowArray
{
private:
	int capacity;
	int size;
	T* data;
public:
	GrowArray():capacity(0),size(0),data(nullptr){}
	GrowArray(int capacity) : capacity(capacity), size(0),data(new T[capacity]) {}
	~GrowArray(){
		delete [] data; // T :: ~T() capacity times
	}

	GrowArray(const GrowArray& orig) = delete;

	void addEnd (const T& v){
		data[size++] = v; // Cool
	}

	class const_Iterator
	{
	private:
		GrowArray<T>& list;
		int pos;
	public:
		const_Iterator(GrowArray<T>& list) : list(list), pos(0) {}
		bool operator !() const {return pos < list.size;}
		void operator ++() {pos ++;}
		T& operator *() const {return list.data[pos];}
		~const_Iterator(){};
		
	};
	
};

int main(int argc, char const *argv[])
{
	GrowArray<int> a(10);
	a.addEnd(5);
	a.addEnd(9);
	for(GrowArray<int> :: const_Iterator i(a); !i ; ++i){
		cout << *i << " ";
	}
	cout << endl;
	return 0;
}