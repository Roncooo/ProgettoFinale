//	author: FULVIO BRUZZESE

#include "Log.h"

Log::Log() 
	: actions{""}, output_file{"log.txt"} 
{
	
};

void Log::write(const std::string& s)
{
	output_file << s;
}

void Log::close() { output_file.close(); }