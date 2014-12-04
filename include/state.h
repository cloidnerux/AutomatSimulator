#pragma once
#include <iostream>
#include <string>

void strcpy_e(char * dst, const char * source);

struct state
{
	char name[10];
	char nextStateNameTrue[10];
	char nextStateNameFalse[10];
	state * nextStateTrue;
	state * nextStateFalse;
	bool outputTrue;
	bool outputFalse;

	state()
	{
		memset(name, 0, 10);
		memset(nextStateNameFalse, 0, 10);
		memset(nextStateNameTrue, 0, 10);
		nextStateFalse = NULL;
		nextStateTrue = NULL;
		outputFalse = false;
		outputTrue = false;
	}

	state(char * line)
	{
		char * ptr = strtok(line, ",");
		strcpy_e(name, ptr);
		ptr = strtok(NULL, ",");	
		strcpy_e(nextStateNameFalse, ptr);
		ptr = strtok(NULL, ",");
		strcpy_e(nextStateNameTrue, ptr);
		ptr = strtok(NULL, ",");
		outputFalse = strchr(ptr, '1') != NULL;
		ptr = strtok(NULL, ",");
		outputTrue = strchr(ptr, '1') != NULL;
	}

	state(const state * c)
	{
		strcpy(name, c->name);
		strcpy(nextStateNameFalse, c->nextStateNameFalse);
		strcpy(nextStateNameTrue, c->nextStateNameTrue);
		nextStateFalse = c->nextStateFalse;
		nextStateTrue = c->nextStateTrue;
		outputFalse = c->outputFalse;
		outputTrue = c->outputTrue;
	}

	state(const state & c)
	{
		strcpy(name, c.name);
		strcpy(nextStateNameFalse, c.nextStateNameFalse);
		strcpy(nextStateNameTrue, c.nextStateNameTrue);
		nextStateFalse = c.nextStateFalse;
		nextStateTrue = c.nextStateTrue;
		outputFalse = c.outputFalse;
		outputTrue = c.outputTrue;
	}

};
