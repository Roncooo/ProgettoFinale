//	author: FULVIO BRUZZESE

#include "Log.h"

Log::Log() 
{
	output.open("log.txt", std::ios::out);
};


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



void Log::close() 
{
	output.close();
}