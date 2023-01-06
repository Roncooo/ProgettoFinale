
#include "Log.h"

void Log::write(const string& s)
{
	output_file << s;
}

void Log::close() { output_file.close(); }