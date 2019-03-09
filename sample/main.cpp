/*******************
 * cpe_593
 * HW_4a GrowArray
 * Author: Qiuyang Tang
 * cite:
 ********************/
#include <iostream>
#include <fstream>
#include <cfloat>

using namespace std;

class Point{
public:
    double x, y;
    Point(double x=0 ,double y=0):x(x),y(y){}
};

template <typename T>
class GrowArray{
private:
    T* data;
    uint32_t used;
    uint32_t size;
    void grow() { // doubles the size each time it is called
        if (used < size)
            return;
        T* temp = data;
        size *= 2;
        data = new T[size];
        for (int i =0; i< used;i++)
            data[i]=temp[i];
        delete[] temp;
    }
public:
    GrowArray() {
        data = new T[1];
        used =0;
    }
    void addEnd(T v) {
        grow();
        data[used++] = v;
    }
    int length(){
        return used;
    }
    T operator[] (uint32_t index){
        return data[index];
    }
};

class ConvexHull{
public:
    GrowArray<Point*>** data;
    int size;
    double minX, maxX, minY, maxY;

    ConvexHull(int a){
        data = new GrowArray<Point*>*[a*a];
        for (int i = 0; i < a*a ; i++)
            data[i] = new GrowArray<Point*>;
        size = a;
    }
    void read(const string& filename){
        GrowArray<Point*> g;
        double x,y;
        minX = DBL_MAX, minY = DBL_MAX, maxX = DBL_MIN, maxY = DBL_MIN;
        fstream file(filename);
        while(!file.eof()){
            file >> x >> y;
            g.addEnd(new Point(x,y));
            minX = x > minX? minX : x;
            minY = y > minY? minY : y;
            maxX = x < maxX? maxX : x;
            maxY = y < maxY? maxY : y;
        }
        double XperBox  = (size-1)/(maxX-minX);
        double YperBox = (size-1)/(maxY-minY);
        for (uint32_t i = 0; i < g.length(); i++){
            Point* point = g[i];
            int cellj = (point->x - minX)*XperBox;
            int celli = (size - 1) - (int) (point->y - minY)*YperBox;
            cout << celli << " " << cellj << endl;
            data[celli*size + cellj]->addEnd(new Point(celli,cellj));
//            point->x;
        }
    }

    void printMinMax(){
        cout << "minx: " << minX << endl;
        cout << "maxx: " << maxX << endl;
        cout << "miny: " << minY << endl;
        cout << "maxy: " << maxY << endl;
    }

    int printAllListSizes(){
//         for(int i =0 ; i< size * size; i++){
//             cout << "cell " << i <<" has " << data[i]->length() << " point(s)" << endl;
//         }
for (int i =0; i < size; i++){
    for (int j=0; j < size; j++){
//        cout << "(" << j << "," << i << ")" <<"\t\n";
        cout << data[i*size + j] ->length() << "\t";
    }
    cout << "\n";
    }
    }
};
int main() {
    // for homework n=16
    ConvexHull ch(16); // create a 16x16 grid of GrowArray
    ch.read("convexhullpoints.dat");
    ch.printAllListSizes(); // tell us how many are in each list
    ch.printMinMax(); // print minx, maxx, miny, maxy for the entire dataset
    //ch.printPerimeterClockWiseOrder(); // p1,p2,p3,p4, p8,p12,p16...
}