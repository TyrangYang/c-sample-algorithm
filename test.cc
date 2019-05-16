#include <vector>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char const *argv[])
{

    string target = "This is a test";

    vector<int> offset(256, target.size());
    offset[target[0]] = 100;
    offset['a'] = 1000;
    for (std::vector<int>::iterator i = offset.begin(); i != offset.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}