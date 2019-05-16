#include <iostream>

using namespace std;
class perm
{
private:
	int* p;
	int len;
public:
	perm(int n):p(new int[n]), len(n){
		for (int i = 0; i < n; ++i)
		{
			p[i] = i;
		}
	};
	~perm(){delete[] p;};

	void showPerm1(int n){
		if(n == 1){
			print();
			return;
		}
		for (int c = 0; c < n; ++c)
		{
			swap(p[c], p[n-1]);
			showPerm1(n-1);
			swap(p[c], p[n-1]);
		}
	}

	void showPerm2(int n){
		if(n == 0){
			print();
			return;
		}
		for (int c = 0; c < n; ++c)
		{
			showPerm2(n-1);
			swap(p[(n % 2 == 1 ? 0 : c )], p[n - 1]);
		}
	}

	void print(){
		for (int i = 0; i < len; ++i)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}
	
	friend ostream& operator <<(ostream& s, const perm& input){
		for (int i = 0; i < input.len; ++i)
		{
			s << input.p[i] << " ";
		}
		return s;
	}
};

int main(int argc, char const *argv[])
{
	int num = 3;
	perm test(num);
	cout << test << endl;
	cout << "+++++++++++++++++++" << endl;
	test.showPerm1(num);
	cout << "+++++++++++++++++++" << endl;
	test.showPerm2(num);
	return 0;
}