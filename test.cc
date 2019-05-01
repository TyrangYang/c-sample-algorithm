#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "test" << endl;
    std::vector<int> isprime (10,1);
    // for (int i = 0; i < 100; ++i)
    // {
    //     isprime[i] = 0;
    // }
    cout << "test" << endl;
    isprime[0] = 1;
    isprime[1] = 0;

    for(auto i: isprime)
        cout << i << endl;
    cout << "test" << endl;
    return 0;
}