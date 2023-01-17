//	author: FULVIO BRUZZESE

//#include <iostream>
#include <fstream>
#include "Match.h"

using std::ifstream, std::ios;

// rinominata perché crea interferenza con l'altro main
int main_f(void){
	
//	Log file_log = Log();
	ifstream input("Progetto\\log.txt", ios::in);
 
	re_play(input);
	
	input.close();
	return 0;
}


//PAUSA

//#include <chrono>
//#include <thread>
//
//std::this_thread::sleep_for(std::chrono::milliseconds(500));