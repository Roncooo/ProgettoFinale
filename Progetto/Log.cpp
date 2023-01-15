//	author: FULVIO BRUZZESE

#include "Log.h"

Log::Log() 
	: actions{""}
{
	output.open("Progetto\\log.txt", std::ios::out);
	input.open("Progetto\\log.txt", std::ios::in);
};

void Log::add(const std::string s) { actions += s; }

std::string Log::getActions() const { return actions; }

void Log::write(const std::string s) 
{ 
	output << s; 
}

void Log::write(game_board::Position& prow, game_board::Position& prune)
{
	if(prow != prune)
		output << prow << " " << prune << "\n";
	else
		output << prow << "\n";
}

void Log::read(std::string s)
{
	std::getline(input, s);
}

//std::ifstream& Log::getInput()
//{
//	return input;
////	actions = "";
////	while(!input.eof())
////	{
////		std::getline(input, actions);
////		actions += "\n";
////	}
////	return actions;
//}

void Log::close() { output.close(); input.close(); }

//#include <windows.h>
//Sleep(1000);