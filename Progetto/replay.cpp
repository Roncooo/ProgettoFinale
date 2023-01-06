
#include <iostream>
#include <fstream>
#include "Match.h"

using std::cout, std::cin, std::ofstream, std::ifstream;

// rinominata perché crea interferenza con l'altro main
int main_function(void){
	
	ifstream input_file("log.txt");
	
	while(input_file.eof())		//restituisce false quando arriva alla fine del file
		//fai qualcosa
	
	input_file.close();
	return 0;
}