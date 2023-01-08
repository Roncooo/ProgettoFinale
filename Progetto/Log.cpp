//	author: FULVIO BRUZZESE

#include "Log.h"

Log::Log() 
	: actions{""}, output{"log.txt"} 
{
	
};

void Log::write(const std::string& s)
{
	output << s;
}

void Log::close() { output.close(); }