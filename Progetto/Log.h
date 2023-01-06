//	author: FULVIO BRUZZESE

#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>

// MAI USING NEGLI HEADER
//using std::string, std::cin, std::ofstream;

class Log
{
private:
	std::string actions;
	std::ofstream output_file;
public:
	Log();
	void write(const std::string& s);
	void close();
	
};


#endif //LOG_H