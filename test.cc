#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <list>
#include <fstream>

using namespace std;

#include "stdint.h" /* Replace with <stdint.h> if appropriate */
#undef get16bits
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
  || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
#define get16bits(d) (*((const uint16_t *) (d)))
#endif

#if !defined (get16bits)
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
                       +(uint32_t)(((const uint8_t *)(d))[0]) )
#endif

uint32_t SuperFastHash (const char * data, int len) {
	uint32_t hash = len, tmp;
	int rem;

    if (len <= 0 || data == NULL) return 0;

    rem = len & 3;
    len >>= 2;

    /* Main loop */
    for (;len > 0; len--) {
        hash  += get16bits (data);
        tmp    = (get16bits (data+2) << 11) ^ hash;
        hash   = (hash << 16) ^ tmp;
        data  += 2*sizeof (uint16_t);
        hash  += hash >> 11;
    }

    /* Handle end cases */
    switch (rem) {
        case 3: hash += get16bits (data);
                hash ^= hash << 16;
                hash ^= ((signed char)data[sizeof (uint16_t)]) << 18;
                hash += hash >> 11;
                break;
        case 2: hash += get16bits (data);
                hash ^= hash << 11;
                hash += hash >> 17;
                break;
        case 1: hash += (signed char)*data;
                hash ^= hash << 10;
                hash += hash >> 1;
    }

    /* Force "avalanching" of final 127 bits */
    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;

    return hash;
}

class hashtable
{
private:
	vector<list<int>* > table;
public:
	
	hashtable(){
		table.assign(5, nullptr);
		// for (int i = 0; i < 4; ++i)
		// {
		table[1] = new list<int>;
		table[3] = new list<int>;
		// }
		list<int> li = {1,2,3};
		table[1]->assign(li.begin(),li.end());
		table[3]->assign(li.begin(),li.end());
		// list<int> li = {1,2,3};
		// list<int> li2 = {};
		// table.assign(2,li);
		// table.push_back(li2);
		// table.push_back(li);
		// table.push_back(li2);
	};
	~hashtable(){};

	vector<list<int>* > getHashTable(){
		return table;
	}

	bool empty(){
		for(list<int>* i: table){
			if(i != nullptr)
				return false;
		}
		return true;
	}

	class const_Iterator
	{
	private:
		// hashtable& ht;
		vector<list<int>* > vl;
		unsigned vpos;
		list<int> :: iterator itl;
		list<int> empty = {};
	public:
		const_Iterator(hashtable& v): vl(v.table), vpos(0){
			while(vl[vpos]== nullptr){
				vpos++;
			}
			itl = vl[vpos]->begin();
			// cout << 1 << endl;
		}
		~const_Iterator(){};
		bool operator !(){
			// cout << "^" << endl;
			return itl != empty.end() && itl != vl[vpos]->end();
		}
		void operator ++(){
			++itl;
			if(itl == vl[vpos]->end()){
				if(vpos == vl.size() - 1) return;
				vpos++;
				while(vl[vpos]== nullptr && vpos != vl.size() - 1)
					vpos++;
				if(vl[vpos] == nullptr)
					itl = empty.end();
				else
					itl = vl[vpos]->begin();
			}
		}
		int operator *(){
			return *itl;
		}
	};
	
};

int main(int argc, char const *argv[])
{
	// int test[] = {2,5,21,998,33,569,23,87,431,5467,9};
	// std::vector<int> v = {1,2,3,4,5};


	// list<int> li = {};
	// forward_list<int> li2 = {};

	// cout << li.empty() << " " << li2.empty() << endl; 
	// cout << "list: " << li.front() << endl;
	// cout << "forward_list: " << li2.front() << endl;

	// std::vector<int*> v = {nullptr};
	// cout << v.empty() << endl;
	int t1 = 10;
	double t2 = 0.7;
	int t3 = 11;
	cout << (t1*t2 < 8) << endl;


	hashtable t ;
	cout << t.empty() << endl;

	for(hashtable::const_Iterator i(t); !i; ++i){
		cout << *i << " "; 
	}
	cout << endl;
	
	// cout << li.front() << endl;
	// cout << fli.front() << endl;
	// vector<list<int>> vl;
	// list<int>::iterator i = li.begin();
	// cout << (i == li2.end()) << endl;

	// std::vector<list<int> > test (2, li); 
	// test.push_back(li);
	// test[0].push_front(10);
	// test[1].push_front(0);
	// test[2].push_front(3);

	// cout << test.size() << endl;
	// cout << test[0].empty() << endl;
	// cout << test[1].empty() << endl;
	// cout << test[2].empty() << endl;
	
	// cout << test[0].front() << " " << test[1].front() << " " << *test[2].begin() << endl;



	// ifstream f("dict.txt");
	// string s;
	// const char* data;
	// int size;
	// std::vector<int> result(100,0);
	// while(!f.eof()){
	// 	f >> s;
	// 	data = s.c_str();
	// 	size = s.size();
	// 	uint32_t test = SuperFastHash(data, size);

	// 	test = test % 100;
	// 	// cout << test << endl;
	// 	result[test]++;
	// }

	// for (std::vector<int>::iterator i = result.begin(); i != result.end(); ++i)
	// {
	// 	cout << *i << endl;
	// }
	
	return 0;
}

