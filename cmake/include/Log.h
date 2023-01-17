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
	//nel file saranno inseriti:
	//- nomi dei giocatori (1° riga e 2° riga)
	//- posizioni delle navi (dalla 4° alla 19° riga)
	//- comandi NON speciali (uno per ogni riga)
public:
	Log();
//	std::ifstream input;		//essendo file di sola lettura, posso anche dichiararlo public
	void write(const std::string s);
	void write(game_board::Position& prow, game_board::Position& prune);
	void close();
};


#endif //LOG_H