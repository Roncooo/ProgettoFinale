//	author: FULVIO BRUZZESE

#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>
#include "Position.h"


class Log
{
private:
	std::string actions;
	std::ofstream output;
	std::ifstream input;
	//nel file saranno inseriti:
	//- nomi dei giocatori (1° riga)
	//- posizioni delle navi (dalla 2° alla 17° riga)
	//- comandi NON speciali (uno per ogni riga)
public:
	Log();
	void add(const std::string s);		//solo per il debug
	void write();
	void write(game_board::Position& prow, game_board::Position& prune);
	std::string getActions() const; 	//solo per debug
//	std::string getInput();
	void close();
	
};


#endif //LOG_H