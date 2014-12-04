#include <iostream>
#include <memory>
#include "parser.h"
#include <time.h>
#include <random>

using namespace std;

int main(int argc, char ** argv)
{
	if(argc < 2)
	{
		cout << "Too few arguments, expect path to state machine description!" << endl;
		cout << "Quit" << endl;
		getchar();
		return 0;
	}
	vector<shared_ptr<state>> states;
	try
	{
		cout << "Loaded " << csvParser::ParseFile(argv[1], states) << " states from file!" << endl;
	}
	catch(exception e)
	{
		cout << e.what() << endl;
		getchar();
		return 0;
	}
	catch(...)
	{
		cout << "Unknown exception!" << endl;
		getchar();
		return 0;
	}
	csvParser::DisplayStates(states);
	int cycles = 100000;
	state * currentState = states[0].get();
	bool input;
	srand(time(NULL));
	input = (rand() % 2) > 0;
	for(int i = 0; i < cycles; i++)
	{
		input = (rand() % 2) > 0;
		cout << "Cyle: " << i << ", State: " << currentState->name << ", input: " << input;
		if(input)
		{
			cout << ", output: " << currentState->outputTrue << endl;
			currentState = currentState->nextStateTrue;
		}
		else
		{
			cout << ", output: " << currentState->outputFalse << endl;
			currentState = currentState->nextStateFalse;
		}
	}
	getchar();
	return 0;
}