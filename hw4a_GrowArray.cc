#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cfloat>
#include <algorithm>
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
		data = new T[2*capacity];
		capacity = 2*capacity;
		for(int i = 0; i < len; i++){
			data[i] = old[i];
		}
		delete[] old;
	}
public:
	goodGrowArray() : data(new T[1]), len(0), capacity(1){}
	goodGrowArray(int capacity): data(new T[1]), len(0), capacity(capacity){}
	~goodGrowArray(){
		delete [] data;
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
};

class point
{
public:
	double x;
	double y;
	point(){};
	point(const point& p){
		x = p.x;
		y = p.y;
	}
	point(double x, double y) : x(x) , y(y){};
	~point(){};	
};

class convexHull
{
private:
	goodGrowArray<point>** data;
	int gird_num;
public:
	double xmax, xmin, ymax, ymin;

	convexHull(int n){
		gird_num = n;
		data = new goodGrowArray<point>* [n*n];
		for (int i = 0; i < n*n; ++i)
		{
			data[i] = new goodGrowArray<point>;
		}
	};
	~convexHull(){
		for (int i = 0; i < gird_num; ++i)
			delete data[i];
		delete data;
	};


	void read(string str){
		goodGrowArray<point> store;

		xmax = DBL_MIN;
		xmin = DBL_MAX;
		ymax = DBL_MIN;
		ymin = DBL_MAX;

		ifstream f(str);

		while(!f.eof()){
			double x, y;
			f >> x >> y;
			point p(x, y);
			store.insertEnd(p);
			xmax = x > xmax ? x : xmax;
			xmin = x < xmin ? x : xmin;
			ymax = y > ymax ? y : ymax;
			ymin = y < ymin ? y : ymin;

		}
		double eps = 0.001;
		double XperBox = gird_num / (xmax-xmin+eps);
		double YperBox = gird_num / (ymax-ymin+eps);

		for (int i = 0; i < store.getlen(); ++i)
		{
			point* p = store.getData();
			int celli = (p[i].x - xmin) * XperBox;
			int cellj = (gird_num - 1) - (int)((p[i].y - ymin) * YperBox);
			data[cellj * gird_num + celli] -> insertEnd(p[i]);
		}

	}

	void printAllListSizes(){
		for (int i = 0; i < gird_num; ++i)
		{
			for (int j = 0; j < gird_num; ++j)
			{
				cout << data[i * gird_num + j] -> getlen() << '\t';
			}
			cout << endl;
		}
	}

	void printMinMax(){
		cout << "min_x: " << xmin << endl;
        cout << "max_x: " << xmax << endl;
        cout << "min_y: " << ymin << endl;
        cout << "max_y: " << ymax << endl;
	}
	
};

int main(int argc, char const *argv[])
{
	cout << "*****This part just for test.*****" << endl;
	vector<double> x;
	vector<double> y;
	double a,b;
	int num_grid = 4;
	int num_Node = 0;
	ifstream f("convexhullpoints.txt");
	
	while(!f.eof()){
		f >> a >> b;
		x.push_back(a);
		y.push_back(b);
		num_Node++;
	}
	cout << num_Node << endl;
	for(int i = 0; i < num_Node;i++){
		cout << x[i] << " " << y[i] << endl;
	}
	
	double xmax = *max_element(x.begin(), x.end());
	double xmin = *min_element(x.begin(), x.end());
	double ymax = *max_element(y.begin(), y.end());
	double ymin = *min_element(y.begin(), y.end());
	double eps = 0.001;

	double XperBox  = (double)num_grid/(xmax-xmin+eps);
	double YperBox = (double)num_grid/(ymax-ymin+eps);

	for(int i = 0; i < num_Node;i++){
		x[i] = (x[i] - xmin) * XperBox;
		y[i] = (y[i] - ymin) * YperBox;
	}

	point points[num_Node];
	for(int i = 0; i < num_Node;i++){
		points[i].x = x[i];
		points[i].y =  y[i];
	}
	for(int i = 0; i < num_Node;i++){
		cout << points[i].x << "---" << points[i].y << endl;
	}

	cout << "************************************" << endl;

	convexHull ch(4); // create a 16x16 grid of GrowArray
    ch.read("convexhullpoints.txt");
    ch.printAllListSizes();
    ch.printMinMax();
	return 0;
}