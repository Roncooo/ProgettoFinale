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
	//nel file saranno inseriti:
	//- nomi dei giocatori (1° riga)
	//- posizioni delle navi (2° riga)		per comodità, e per evitare doppie conversioni, sono salvate row e col anzichè le Posizioni
	//- comandi NON speciali (uno per ogni riga)
public:
	Log();
	void write(const std::string& s);
	void close();
	
};


#endif //LOG_H