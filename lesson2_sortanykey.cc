class Person{
public:
	string firstname;
	string lastname;
	int age;
	Person (const string& firstname,const string& lastname, int age):
		firstname(firstname), lastname(lastname), age(age){}
};

template<typname T>
void sort (T x[], int n){
	for(int i = 0; i<n-1 ; i++){
		for(int j = 0; j<i ; j++){
			T temp = x[j];
			x[j] = x[j+1];
			x[j+1] = temp;
		}
	}
}

template<typname T,typname Key>
void sort2 (T x[], T::*Key key, int n){
	for(int i = 0; i<n-1 ; i++){
		for(int j = 0; j<i ; j++){
			if (x[j].*key > x[j+1].*key)
			T temp = x[j];
			x[j] = x[j+1];
			x[j+1] = temp;
		}
	}
}


int main(){
	int x[] = {5,4,3,2,1}
	int y[] = {2.5,1.5,3}
	string x[] = {"Fred", "banana", "apple"}
	Person people[] = {Person("Dov","Kougr",25),Person("a","b",23)}

	sort2(people, &Person::firstname)
}

// 写所有的sort
// 修改上一周作业
// 看视频上一周
// anykey学习