//	author: FULVIO BRUZZESE

#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>


class Log
{
private:
	std::string actions;
	std::ofstream output;
	std::ifstream input;
	//nel file saranno inseriti:
	//- nomi dei giocatori (1° riga)
	//- posizioni delle navi (dalla 2° alla 17° riga)		per comodità, e per evitare doppie conversioni, sono salvate row e col anzichè le Posizioni
	//- comandi NON speciali (uno per ogni riga)
public:
	Log();
	void write(const std::string& s);
	std::string getInput();
	void close();
	
};


#endif //LOG_H