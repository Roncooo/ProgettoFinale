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
public:
	Log();
	void write(const std::string& s);
	void close();
	
};


#endif //LOG_H