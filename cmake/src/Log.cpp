//	author: FULVIO BRUZZESE

#include "Log.h"

Log::Log() 
	: actions{""}, output{"log.txt"}, input{"log.txt"} 
{
	
};

void Log::write(const std::string& s)
{
	output << s;
}

std::string Log::getInput()
{
	actions = "";
	while(!input.eof())
	{
		std::getline(input, actions);
		actions += "\n";
	}
	return actions;
}

void Log::close() { output.close(); }