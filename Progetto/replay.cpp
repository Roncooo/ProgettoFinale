//	author: FULVIO BRUZZESE

//#include <iostream>
#include <fstream>
#include <cstring>
#include "Match.h"

using std::ifstream, std::ios, game_board::Position, std::cout;


int command_for_replay(game_board::Position& a, game_board::Position& b, std::ifstream& input)
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
			cout << "Lunghezza insufficiente\n";
			break;
		}
		if (input_string.substr(0, 2) == ignore)		//controllo che non ci sia la flag che ho scelto
		{
//			std::cout << "Qui c'è una flag\n";
			continue;
		}
		
		if (input_string.substr(0, 2) == eof)		//controllo che non ci sia la flag che ho scelto
		{
//			flag = true;
			cout << input_string.substr(2) << "\n";
			return -1;
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
	return 1;
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

int replay_round(Player& player, Player& enemy, std::ifstream& input)
{
	Position origin, target;
	
	int code = command_for_replay(origin, target, input);
	player.act_ship(player.get_ship_index(origin), target, enemy);
	player.print_defence_attack();
//	std::cout << "Comando eseguito\n";
	return code;
}


void re_play(std::ifstream& input)
{
	if (!input.is_open())
	{
		cout << "~~~~ERRORE APERTURA FILE~~~~";
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
		
		cout << "\nTurno: " << n_rounds << "\n";
		if (replay_round(p1, p2, input) == -1)
		{
			cout << "### FINE PARTITA ###\n";
			break; //o return
		}
		n_rounds++;
		
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		
		if(replay_round(p2, p1, input) == -1)
		{
			cout << "### FINE PARTITA ###\n";
			break;
		}
		n_rounds++;
	}
	
	
}




// rinominata perché crea interferenza con l'altro main
int main_f(int argc, char* argv[])
{
	std:: string match_type;
	std::string file_log_name;
	std::string file_output_replay_name;
	
	if(argc==1)
		match_type = "UNASSIGNED";
	if(argc==2)
		match_type = "TOO_LOW_ARGS";
	if(argc==3)
	{
		if (strcmp(argv[1], "v") || strcmp(argv[1], "V"))
			{
				file_log_name = argv[2];
				
				ifstream input(file_log_name, ios::in);
				re_play(input);
				input.close();
			}
		else if (strcmp(argv[1], "f") || strcmp(argv[1], "F"))
			match_type = "TOO_LOW_ARGS";
		else
			match_type = "INVALID";
	}
	if(argc==4)
	{
		if (strcmp(argv[1], "f") || strcmp(argv[1], "F"))
		{
			file_log_name = argv[2];
			file_output_replay_name = argv[3];
		}
		else
			match_type = "INVALID";
	}
	if(argc>4)
		match_type = "TOO_MANY_ARGS";
	
	
	if(match_type=="UNASSIGNED")
		cout << "Non e' stato inserito nulla nella riga di comando\n";
	if(match_type=="TOO_LOW_ARGS")
		cout << "Non e' stato inserito nulla nella riga di comando\n";
	if(match_type=="TOO_MANY_ARGS")
		cout << "Sono stati inseriti troppi elementi nella riga di comando\n";
	if(match_type=="INVALID")
		cout << "Il comando inserito da riga di comando non e' valido\n";
	
//	Log file_log = Log();
//	ifstream input("Progetto\\log.txt", ios::in);
//	re_play(input);
//	input.close();
	return 0;
}


//PAUSA

//#include <chrono>
//#include <thread>
//
//std::this_thread::sleep_for(std::chrono::milliseconds(500));