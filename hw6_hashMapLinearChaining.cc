#include <iostream>
#include <unordered_set>
#include <fstream>
#include <string>
#include <vector>
#include <list>
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

class hashMapLinearChaining
{
private:

	vector<list<string>* > table;
	unsigned tableLen;
	unsigned used;

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

	int hash(string s, int tableLen){
		int size = s.size();
		const char* data = s.c_str();
		unsigned first_hash = SuperFastHash(data, size);
		return first_hash % tableLen;
	}

	void grow(){
		vector<list<string>* > temp = table;
		tableLen *= 2;
		used = 0;
		table.assign(tableLen, nullptr);
		for(list<string>* i: temp){
			if(i != nullptr){
				for(list<string> :: iterator j = i->begin(); j != i->end(); ++j){
					add(*j);
				}
			}
		}
	}

public:
	hashMapLinearChaining(){
		tableLen = 100;
		used = 0;
		table.assign(tableLen, nullptr);
	};
	~hashMapLinearChaining(){
		for (unsigned i = 0; i < tableLen; ++i)
		{
			if(table[i] != nullptr){
				delete table[i];
			}
		}
	};
	
	void add(const string& s){
		// cout<< "====" << used << "====" << tableLen << endl;
		if(used >= 0.5 * tableLen)
			grow();
		int pos = hash(s, tableLen);
		if(table[pos] == nullptr){
			table[pos] = new list<string>;
			used++;
			table[pos] -> push_front(s);
		}else{
			for(list<string> :: iterator i = table[pos]->begin(); i != table[pos]->end(); ++i){
				if(*i == s)
					return;
			}
			table[pos] -> push_front(s);
		}
	}

	bool empty(){
		for(list<string>* i: table){
			if(i != nullptr)
				return false;
		}
		return true;
	}

	void hist(){
		cout << "linear chain have " << tableLen << " bucket." << endl;
		int result[10] = {0};
		for (int i = 0; i < tableLen; ++i)
		{
			int size_bucket;
			if(table[i]==nullptr){
				size_bucket = 0;
			}else{
				size_bucket = table[i]->size();
			}
			if(size_bucket < 10)
				result[size_bucket]++;
			else
				result[9]++;
		}
		for (int i = 0; i < sizeof(result)/sizeof(int); ++i)
		{
			cout << i << "\t" << result[i] << endl;
		}
	}

	class const_Iterator
	{
	private:
		// hashMapLinearChaining& ht;
		vector<list<string>* > vl;
		unsigned vpos;
		list<string> :: iterator itl;
		list<string> empty = {};
	public:
		const_Iterator(hashMapLinearChaining& v): vl(v.table), vpos(0){
			while(vl[vpos] == nullptr){
				vpos++;
			}
			itl = vl[vpos]->begin();
		}
		~const_Iterator(){};

		bool operator !(){
			return itl != empty.end() && itl != vl[vpos]->end();
		}

		void operator ++(){
			++itl;
			if(itl == vl[vpos]->end()){
				if(vpos == vl.size() - 1) return;
				vpos++;
				while(vl[vpos] == nullptr && vpos != vl.size() - 1)
					vpos++;
				if(vl[vpos] == nullptr)
					itl = empty.end();
				else
					itl = vl[vpos]->begin();
			}
		}

		string operator *(){
			return *itl;
		}
	};
	
};

int main(){
	ifstream f("dict.txt");
	string s;
	unordered_set<string> us;
	hashMapLinearChaining hmlc;
	while(!f.eof()){
		f >> s;
		// cout<< s << endl;
		us.insert(s);
		hmlc.add(s);
	}
	f.close();

	cout << "+++++ hash map linear chaining +++++" << endl;
	hmlc.hist();
	cout << "++++++++++++++++++++++++++++++++++++" << endl;
	cout << endl;
	cout << "--- compare with hash table in STL ---" << endl;
	cout << endl;
	cout << "++++++++++ unordered_set ++++++++++" << endl;
	unsigned n = us.bucket_count();
	cout << "unordered_set have " << n << " bucket." << endl;

	int result[10] = {0};

	for (int i = 0; i < n; ++i)
	{
		int size_bucket = us.bucket_size(i);
		if(size_bucket < 10)
			result[size_bucket]++;
		else
			result[9]++;
	}

	for (int i = 0; i < sizeof(result)/sizeof(int); ++i)
	{
		cout << i << "\t" << result[i] << endl;
	}
	cout << "++++++++++++++++++++++++++++++++++++" << endl;
	// for(hashMapLinearChaining :: const_Iterator it(hmlc); !it; ++it){
	// 	cout << *it << " ";
	// }
	// cout << endl;
}