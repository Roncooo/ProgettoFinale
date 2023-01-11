//	author: FULVIO BRUZZESE

#include "Log.h"

Log::Log() 
	: actions{""}
{
	output.open("log.txt", std::ios::out);
	input.open("log.txt", std::ios::in);
};

void Log::add(const std::string s) { actions += s; }

std::string Log::getActions() const { return actions; }

void Log::write() 
{ 
	output << actions; 
}

std::string Log::getInput()
{
//	actions = "";
//	while(!input.eof())
//	{
//		std::getline(input, actions);
//		actions += "\n";
//	}
//	return actions;
}

void Log::close() { output.close(); }

//#include <windows.h>
//Sleep(1000);