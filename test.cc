#include <iostream>
#include <string>
#include <vector>

using namespace std;

int* removeE(int* test, int index, int len){
    if(index > len)
        return test;
    else{
        for (int i = index; i < len - 1;)
        {
            test[i] = test[++i];
            // cout << test[i] << endl;
        }
        int* res = new int[len - 1];
        for (int i = 0; i < len - 1; ++i)
        {
            res[i] = test[i];
            // cout << res[i] << " " << test[i] << endl;
        }
        return res;
    }
}

int main()
{
    for (int i = 0; i < 4; ++i)
    {
        if(i == 0)
            continue;
        cout << i << endl;
    }
}