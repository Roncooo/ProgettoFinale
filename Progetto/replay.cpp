//	author: FULVIO BRUZZESE

//#include <iostream>
#include <fstream>
#include "Match.h"

using std::ifstream, std::ios, game_board::Position;


void command_for_replay(game_board::Position& a, game_board::Position& b, std::ifstream& input)
{
	
//	std::string ignore = ">>";
//	std::string eof = "<<";		//fine partita: stampa il risultato
	std::string input_string;
	bool flag = false;
	
	while(!flag)
	{
		std::getline(input, input_string);
		
		if(input_string.length() < 1)				//controllo che ci siano almeno due caratteri
		{
			std::cout << "Lunghezza insufficiente\n";
			break;
		}
		if (input_string.substr(0, 2) == ignore)		//controllo che non ci sia la flag che ho scelto
		{
			std::cout << "Qui c'è una flag\n";
			continue;
		}
		
		if (input_string.substr(0, 2) == eof)		//controllo che non ci sia la flag che ho scelto
		{
			std::cout << "### FINE PARTITA ###\n";
			std::cout << input_string.substr(2) << "\n";
			input.close();
			flag = true;
			break;
		}
		
		std::vector<std::string> vec = split(input_string, ' ');
		std::string in1, in2;
		
		in1 = vec.at(0);
		if(vec.size()==1)
		{
			a = Position(in1);
			b = Position(in1);
			flag = true;
			break;
		}
		
		in2 = vec.at(1);
		a = Position(in1);
		b = Position(in2);
		
		flag = true;		//ha letto i comandi
	}
}

void replay_placement(Player& p, std::ifstream& input)
{
	Position prow, prune;
	
	for(int i = 1; i <= game_board::MAX_BATTLESHIPS; i++)
	{
		command_for_replay(prow, prune, input);
		p.add_ship(new Battleship(prow, prune, p)); 
	}
	
	for(int i = 1; i <= game_board::MAX_SUPPORTS; i++)
	{
		command_for_replay(prow, prune, input);
		p.add_ship(new Support(prow, prune, p)); 
	}
	
	for(int i = 1; i <= game_board::MAX_SUBMARINES; i++)
	{
		command_for_replay(prow, prune, input);
		p.add_ship(new Submarine(prow, p)); 
	}
}

void replay_round(Player& player, Player& enemy, std::ifstream& input)
{
	Position origin, target;
	
	command_for_replay(origin, target, input);
	player.act_ship(player.get_ship_index(origin), target, enemy);
	std::cout << "Comando eseguito\n";
}


void re_play(std::ifstream& input)
{
	if (!input.is_open())
	{
		std::cout << "~~~~ERRORE APERTURA FILE~~~~";
		return;
	}
	
	std::string temp = "";
	int n_rounds = 1;
	
	//leggo i nomi dei giocatori
	std::getline(input, temp);
	Player p1(temp);
	std::getline(input, temp);
	Player p2(temp);
	
	std::getline(input, temp);		//serve per bypassare la riga vuota
	
	//posizionamento delle navi
	replay_placement(p1, input);
	replay_placement(p2, input);
	
	
	//eseguo i turni, leggendo le mosse dal file, finchè non arrivo alla fine del file
	while(input.good())
	{
		std::getline(input, temp);		//serve per bypassare la riga vuota
		
		std::cout << "\nTurno: " << n_rounds << "\n";
		replay_round(p1, p2, input);
		n_rounds++;
		
		replay_round(p2, p1, input);
		n_rounds++;
	}
	
	std::cout << "\nSI SI SI CAZZO SIIIIIIIIII";
	
}




// rinominata perché crea interferenza con l'altro main
int main_f(void){
	
//	Log file_log = Log();
	ifstream input("Progetto\\log.txt", ios::in);
	re_play(input);
	
	return 0;
}


//PAUSA

//#include <chrono>
//#include <thread>
//
//std::this_thread::sleep_for(std::chrono::milliseconds(500));