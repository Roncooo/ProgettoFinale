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
	//- nomi dei giocatori (1° riga e 2° riga)
	//- posizioni delle navi (dalla 4° alla 19° riga)
	//- comandi NON speciali (uno per ogni riga)
public:
	Log();
	void add(const std::string s);		//solo per il debug
	void write(const std::string s);
	void write(game_board::Position& prow, game_board::Position& prune);
	void read(std::string s);
	std::string getActions() const; 	//solo per debug
//	std::ifstream& getInput();
	void close();
	
};


#endif //LOG_H