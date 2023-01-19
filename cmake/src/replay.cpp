//	author: FULVIO BRUZZESE

//#include <iostream>
//#include <fstream>		//vengono inclusi da "Match.h"
#include <cstring>
#include "Match.h"

using std::ifstream, std::ofstream, std::string, std::ios, game_board::Position, std::cout;



int command_for_replay(Position& a, Position& b, ifstream& input)
{
	
	string input_string;
	bool flag = false;
	
	while(!flag)
	{
		std::getline(input, input_string);
		
		if(input_string.length() < 1)				//controllo che ci siano almeno due caratteri
		{
			continue;
		}
		if (input_string.substr(0, 2) == ignore)		//controllo che non ci sia la flag che ignora la riga
		{
			continue;
		}
		
		if (input_string.substr(0, 2) == eof)		//controllo che non ci sia la flag di fine partita
		{
			cout << "\n";
			cout << input_string.substr(2) << "\n";
			return -1;
		}
		
		std::vector<std::string> vec = split(input_string, ' ');
		string in1, in2;
		
		in1 = vec.at(0);
		if(vec.size()==1)
		{
			a = Position(in1);
			b = Position(in1);
			return 1;
		}
		
		in2 = vec.at(1);
		a = Position(in1);
		b = Position(in2);
		
		flag = true;		//ha letto i comandi
	}
	return 1;
}


void replay_placement(Player& p, ifstream& input)
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


int replay_round(Player& player, Player& enemy, ifstream& input)
{
	Position origin, target;
	
	player.print_defence_attack();
	int code = command_for_replay(origin, target, input);
	player.act_ship(player.get_ship_index(origin), target, enemy);

	return code;
}

int replay_round_in_file(Player& player, Player& enemy, ifstream& input, string& match_string)
{
	Position origin, target;
	
	match_string += player.grids_to_string();
	int code = command_for_replay(origin, target, input);
	player.act_ship(player.get_ship_index(origin), target, enemy);

	return code;
}


void re_play(ifstream& input)
{
	if (!input.is_open())
	{
		cout << "~~~~ERRORE APERTURA FILE~~~~";
		return;
	}
	
	Player p1, p2;
	string temp = "";
	//leggo i nomi dei giocatori
	std::getline(input, temp);
	p1.name = temp;
	std::getline(input, temp);
	p2.name = temp;
	
	std::getline(input, temp);		//serve per bypassare la riga vuota
	
	//posizionamento delle navi
	replay_placement(p1, input);
	replay_placement(p2, input);
	
	int n_rounds = 1;
	//eseguo i turni, leggendo le mosse dal file, finchè non arrivo alla fine del file
	while(input.good())
	{
		std::getline(input, temp);		//serve per bypassare la riga vuota
		
		cout << "\nTurno: " << n_rounds << "\n";
		if (replay_round(p1, p2, input) == -1)
		{
			cout << "\n### FINE PARTITA ###\n";
			return;
		}
		n_rounds++;
		
		cout << "\n";
//		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		
		if(replay_round(p2, p1, input) == -1)
		{
			cout << "\n### FINE PARTITA ###\n";
			return;
		}
		n_rounds++;
	}
	
}

std::string replay_in_file(ifstream& input)
{
	string match_string = "";
	
	if (!input.is_open())
	{
		match_string += "~~~~ERRORE APERTURA FILE~~~~";
		return match_string;
	}
	
	Player p1, p2;
	string temp = "";
	//leggo i nomi dei giocatori
	std::getline(input, temp);
	p1.name = temp;
	std::getline(input, temp);
	p2.name = temp;
	
	std::getline(input, temp);		//serve per bypassare la riga vuota
	
	//posizionamento delle navi
	replay_placement(p1, input);
	replay_placement(p2, input);
	
	int n_rounds = 1;
	while(input.good())
	{
		std::getline(input, temp);		//serve per bypassare la riga vuota
		
		match_string += "\nTurno: " + std::to_string(n_rounds) + "\n";
		if (replay_round(p1, p2, input) == -1)
		{
			match_string += "\n### FINE PARTITA ###\n";
			return match_string;
		}
		n_rounds++;
		cout << "\n";
		
		if(replay_round(p2, p1, input) == -1)
		{
			match_string += "\n### FINE PARTITA ###\n";
			return match_string;
		}
		n_rounds++;
	}
	
}

void re_write(ifstream& input, ofstream& output)
{
	//mi chiedo se abbia senso far eseguire il replay e salvare su una stringa tutto quello che viene stampato
	//ma come prelevo l'ostream?
	
	//oppure vado a modifcare print_defence, facendo in modo che tutto quello che stampa lo salva 
	//anche in una stringa che puoò benissimo ritornare
	
	
	//viene controllato che i file siano stati aperti correttamente
	if (!input.is_open())
		cout << "**** OPS!! QUALCOSA E' ANDATO STORTO COL FILE INPUT ****";
	if (!output.is_open())
		cout << "**** OPS!! QUALCOSA E' ANDATO STORTO COL FILE OUTPUT ****";
	
//	string line;
//	string txt = "";
//	
//	while(input.good())
//	{
//		std::getline(input, line);
//		line += "\n";
//		txt += line;
//	}
//	output << txt;
	
	//deve rigiocare la partita con replay, ma senza stampare nulla a video
	string text = replay_in_file(input);
	output << text;
}



// rinominata perché crea interferenza con l'altro main
int main(int argc, char* argv[])
{
	string match_type;
	string file_log_name;
	string file_output_replay_name;
	
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	
	//confronto quanti argomenti ci sono sulla riga di comando
	if(argc==1)
	{
		match_type = "UNASSIGNED";
		
//		file_log_name = "Progetto\\log.txt";
//		file_output_replay_name = "Progetto\\output.txt";
//		
//		ifstream input(file_log_name, ios::in);
//		ofstream output(file_output_replay_name, ios::out | ios::app);
//		
//		re_write(input, output);
//		input.close();
//		output.close();

//		Player p1("pippo");
//		string grid = p1.grids_to_string();
//		cout << grid;
	}
	if(argc==2)
		match_type = "TOO_LOW_ARGS";
	if(argc==3)								//se ci sono esattamente 3 argomenti, stampo a video il replay
	{
		if (strcmp(argv[1], "v") || strcmp(argv[1], "V"))
			{
				file_log_name = argv[2];
				cout << argv[1];
				
				ifstream input(file_log_name, ios::in);
				re_play(input);
				input.close();
			}
		else if (strcmp(argv[1], "f") || strcmp(argv[1], "F"))
			match_type = "TOO_LOW_ARGS";
		else
			match_type = "INVALID";
	}
	if(argc==4)								//se ci sono esattamente 4 argomenti, scrivo sul secondo file il replay che si trova nel primo file
	{
		if (strcmp(argv[1], "f") || strcmp(argv[1], "F"))
		{
			file_log_name = argv[2];
			file_output_replay_name = argv[3];
			
			ifstream input(file_log_name, ios::in);
			ofstream output(file_output_replay_name, ios::out | ios::app);
			
			re_write(input, output);
			input.close();
			output.close();
		}
		else
			match_type = "INVALID";
	}
	if(argc>4)
		match_type = "TOO_MANY_ARGS";
	
	
	//stampe a video dei possibili errori relativi all'inserimento su riga di comando
	if(match_type=="UNASSIGNED")
		cout << "Non e' stato inserito nulla nella riga di comando\n";
	if(match_type=="TOO_LOW_ARGS")
		cout << "Non sono stati inseriti abbastanza elementi nella riga di comando\n";
	if(match_type=="TOO_MANY_ARGS")
		cout << "Sono stati inseriti troppi elementi nella riga di comando\n";
	if(match_type=="INVALID")
		cout << "Il comando inserito da riga di comando non e' valido\n";
	
	return 0;
}


//	ifstream input("Progetto\\log.txt", ios::in);
//	re_play(input);
//	input.close();

//PAUSA

//#include <chrono>
//#include <thread>
//
//std::this_thread::sleep_for(std::chrono::milliseconds(500));

