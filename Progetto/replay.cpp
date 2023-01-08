
#include <iostream>
#include <fstream>
#include "Match.h"

using std::cout, std::cin, std::ofstream, std::ifstream;

// rinominata perché crea interferenza con l'altro main
int main_function(void){
	
	ifstream input_file("log.txt");
	
//	while(input_file.eof())		//restituisce false quando arriva alla fine del file
//		//fai qualcosa
	
//	Player p1, p2; 
//	Match partita(p1, p2);
//	partita.re_play(input_file);
	
	input_file.close();
	return 0;
}