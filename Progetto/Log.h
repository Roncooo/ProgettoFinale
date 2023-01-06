
#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>
using std::string, std::cin, std::ofstream;

class Log
{
private:
	string actions;
	ofstream output_file;
public:
	Log() : actions{""}, output_file{"log.txt"} {};	
	void write(const string& s);
	void close();
	
};


#endif //LOG_H