//	author: FULVIO BRUZZESE

#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>


class Log
{
private:
	std::string actions;
	std::ofstream output_file;
	//nel file saranno inseriti:
	//- nomi dei giocatori (1° riga)
	//- posizioni delle navi (2° riga)
	//- comandi NON speciali (uno per ogni riga)
public:
	Log();
	void write(const std::string& s);
	void close();
	
};


#endif //LOG_H