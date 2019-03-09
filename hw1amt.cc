#include <iostream>
#include <cmath>
#include <thread>
#include <fstream>
#include <string>
using namespace std;

bool isPrime(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int countPrime(int start, int end)
{
    int count = 0;
    for (int i = start; i<=end; i++)
    {
        if (isPrime(i)){
            count ++;
        }
    }
    //cout << start << "-" << end <<" : "<<count << endl;

    //Write result to file
    ofstream file;
    file.open ("temp",ios::app);
    file << count << "\n";
    file.close();
}

int main() {
    int in = 0;
    int threads = 20;
    cout << "Give me a value: ";
    cin >> in;
    int block = (in/threads);
    // Flush the content in old file
    ofstream file;
    file.open ("temp");
    file << "";
    file.close();

    //20 Threads
    std::thread t1{countPrime,2,block};
    std::thread t2{countPrime,block+1,2*block};
    std::thread t3{countPrime,2*block +1 ,3*block};
    std::thread t4{countPrime,3*block+1,4*block};
    std::thread t5{countPrime,4*block+1,5*block};
    std::thread t6{countPrime,5*block+1,6*block};
    std::thread t7{countPrime,6*block+1,7*block};
    std::thread t8{countPrime,7*block +1 ,8*block};
    std::thread t9{countPrime,8*block+1,9*block};
    std::thread t10{countPrime,9*block+1,10*block};

    std::thread t11{countPrime,10*block+1,11*block};
    std::thread t12{countPrime,11*block+1,12*block};
    std::thread t13{countPrime,12*block +1 ,13*block};
    std::thread t14{countPrime,13*block+1,14*block};
    std::thread t15{countPrime,14*block+1,15*block};

    std::thread t16{countPrime,15*block+1,16*block};
    std::thread t17{countPrime,16*block+1,17*block};
    std::thread t18{countPrime,17*block +1 ,18*block};
    std::thread t19{countPrime,18*block+1,19*block};
    std::thread t20{countPrime,19*block+1,in};
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    t11.join();
    t12.join();
    t13.join();
    t14.join();
    t15.join();
    t16.join();
    t17.join();
    t18.join();
    t19.join();
    t20.join();

    int count = 0;

    //Read and add counts in file
    ifstream myfile;
    myfile.open ("temp");
    string line;
    while ( getline (myfile,line) )
    {
      count += stoi(line);
    }
    myfile.close();
    cout << "Total count is " << count << endl;
    return 0;
}