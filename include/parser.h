#pragma once

#include <memory>
#include <vector>

#include "state.h"

class csvParser
{
private:
public:
	static int ParseFile(const char * path, std::vector<std::shared_ptr<state>> & states);
	static int parse(char * data, std::vector<std::shared_ptr<state>> & states);
	static void DisplayStates(std::vector<std::shared_ptr<state>> & states);
};