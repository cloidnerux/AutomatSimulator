#include "parser.h"
#include <fstream>
#include <iostream>


using namespace std;

void strcpy_e(char * dst, const char * source)
{
	int start = 0;
	while(source[start] == ' ')
		start++;
	strcpy(dst, source + start);
}

int csvParser::ParseFile(const char * path, std::vector<std::shared_ptr<state>> & states)
{
	ifstream * f = new ifstream(path, ios::in);
	cout << "File: " << path << endl;
	if(!f->is_open())
	{
		cout << "Could not open File " << path << "!" << endl;
		delete f;
		return 0;
	}
	size_t start = f->tellg();
	f->seekg(0, ios::end);
	size_t size = f->tellg();
	size = size - start;
	f->seekg(0, ios::beg);
	char * buffer = new char[size];
	f->read(buffer, size);
	int count = parse(buffer, states);

	delete f;
	delete buffer;
	return count;
}

int csvParser::parse(char * data, std::vector<std::shared_ptr<state>> & states)
{
	char * ptr = strtok(data, "\n");
	vector<char*> lines;
	//Read the lines
	do
	{
		if(strchr(ptr, '#') == NULL)
			lines.push_back(ptr);
		ptr = strtok(NULL, "\n");
	}while(ptr != NULL);
	//Parse the lines
	for(int i = 0; i < lines.size(); i++)
	{
		states.push_back(make_shared<state>(new state(lines[i])));
	}
	//make the connections
	int tmp = 0;
	for(int i = 0; i < states.size(); i++)
	{
		for(int a = 0; a < states.size(); a++)
		{
			if(strcmp(states[i]->nextStateNameFalse, states[a]->name) == 0)
			{
				states[i]->nextStateFalse = states[a].get();
				tmp++;
			}
			if(strcmp(states[i]->nextStateNameTrue, states[a]->name) == 0)
			{
				states[i]->nextStateTrue = states[a].get();
				tmp++;
			}
			if(tmp >= 2)
				break;
		}
		tmp = 0;
	}
	return states.size();
}

void csvParser::DisplayStates(std::vector<std::shared_ptr<state>> & states)
{
	for(auto it=states.begin(); it != states.end(); it++)
	{
		cout << "State: " << it->get()->name << ", " << it->get()->nextStateNameFalse << ", " << it->get()->nextStateNameTrue << ", " << it->get()->outputFalse << ", " << it->get()->outputTrue << endl;
	}
}