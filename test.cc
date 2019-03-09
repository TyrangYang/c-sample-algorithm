#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

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

class points
{
private:
	point a[10];
	int len = 0;
public:
	points(){};
	~points(){};
	void add(point p){
		a[len] = p;
		len++;
	}

	point* getPoints(){
		point* data = a;
		return data;
	}
	
};

int main() {
    point p1(1, 2);
    point p2(3, 4);

    points p;
    p.add(p1);
    p.add(p2);

    point* data;
    data = p.getPoints();

    for (int i = 0; i < 2; ++i)
    {
    	cout << data[i].x << endl;
    }
    
}
