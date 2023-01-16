
#include <iostream>
#include <fstream>
#include "Match.h"

using std::cout, std::cin, std::ofstream, std::ifstream;

// rinominata perché crea interferenza con l'altro main
int main_function(void){
	
	Log file_log = Log();
	Player p1, p2; 
//	while(!input_file.eof())		//restituisce true quando arriva alla fine del file
//		//fai qualcosa
	
	
//	re_play(p1, p2, file_log);
	
	file_log.close();
	return 0;
}


//PAUSA

//#include <chrono>
//#include <thread>
//
//std::this_thread::sleep_for(std::chrono::milliseconds(500));