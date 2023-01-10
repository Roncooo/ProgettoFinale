//	author: FULVIO BRUZZESE

#include "Log.h"

Log::Log() 
	: actions{""}, output{"log.txt"}, input{"log.txt"} 
{
	
};

void Log::add(const std::string& s) { actions += s; }

void Log::write() { output << actions; }

std::string Log::getActions() { return actions; }

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