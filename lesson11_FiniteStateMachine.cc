#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Naive search
// boyer moore
// finite state machine
// lsc
// edit distance
constexpr int NUMSTATES = 10;


class FiniteStateMachine
{
private:
	int currentState;
	int next[NUMSTATES][256];

public:
	FiniteStateMachine() : currentState(0) {
		for (int i = 0; i < 256; ++i)
		{
			next[0][i] = 1;
		}
		for (int i = 'a'; i < 'z'; ++i)
		{
			next[0][i] = 0;
		}
		for (int i = 'A'; i < 'Z'; ++i)
		{
			next[0][i] = 0;
		}
	};
	~FiniteStateMachine(){};

	void exec(const char inp[]){
		for (int i = 0; inp[i] != '\0'; ++i)
		{
			currentState = next[currentState][inp[i]];
			if(currentState == 1){
				return; //get out
			}
		}
	}
	
};


void fsm(const char inp[]){

}


int main(int argc, char const *argv[])
{
	const char s[] = "this is my test. find me some state!"
	return 0;
}