#include "Match.h"

void user_placement_helper(Player& p, int n_coordinates, Position& prow, Position& prune, 
							std::string ship_name, int ship_size, int ship_number);
void user_placement(Player& p);
void bot_placement(Player& p);


Match::Match(const Player& p1, const Player& p2)
	: player1{p1}, player2{p2}
{

	// altro?
}

std::vector<std::string> split(std::string str, char delimiter);

//	non ho capito, così facendo il compilatore non considera una funzione diversa da quella
//	dichiarata nella classe?
int command(Position& a, Position& b)
{
	// inizializzazione della regex, non so bene come/dove metterla, potrebbe essere benissimo statica
	// ma non so bene come fare
	std::string reg_rule = "[";
	for(int i=0; i<Grid::rows; i++)
		reg_rule += Grid::letters[i];
	reg_rule+="]([1-9]|1[012])";
	std::regex reg_position = std::regex(reg_rule);
	
	std::string input_string;	// tutto l'input (cin invece si ferma allo spazio)
	std::getline(std::cin, input_string);
	// trasformo in uppercase l'input
	std::transform(input_string.begin(), input_string.end(), input_string.begin(), ::toupper);
	
	
	// COMANDI SPECIALI
	if(input_string == "XX")
		return 3;
		
	if(input_string == "XX XX")
		return 4;
	
	if(input_string == "AA AA")
		return 5;
	
	
	// COMANDI CON COORDINATE
	
	std::vector<std::string> vec = split(input_string, ' ');
	std::string in1, in2;
	
	// se non c'è neanche un comando o più di due comandi, errore
	if(vec.size()==0 || vec.size()>2)
		return -1;
	
	// memorizzo il primo comando che a questo punto c'è per forza
	in1 = vec.at(0);
	
	// se non c'è un secondo comando, il primo deve essere la coordinata di inserimento di un sottomarino
	if(vec.size()==1)
	{
		if(!std::regex_match(in1, reg_position))
		{
			return -1;
		}
		else	// inserimento di un sottomarino
		{
			a = in1;
			b = in1;
			return 1;
		}
	}
	
	// a questo punto i comandi sono necessariamente 2 quindi o 2 coordinate o altro
	in2 = vec.at(1);
	if(std::regex_match(in1, reg_position) && std::regex_match(in2, reg_position))
	{
		a = in1;
		b = in2;
		return 2;
	}
	
	// se fin'ora non è stato riconosciuto un comando valido, è invalido
	return -1;
}


void Match::ship_placement(Player& p)
{
	if(p.is_cpu)
		bot_placement(p);
	else
		user_placement(p);
}

void user_placement(Player& p)
{
	std::cout << "\n" + p.name + " inserisci le tue navi\n\n";
	Position prow, prune;
	
	for(int i=0; i<3; i++)
	{
		user_placement_helper(p, 2, prow, prune, "corazzata "+std::to_string(i+1), 5, i);
		p.defence.ships[i] = new Battleship(prow, prune, p);	// qui manca la griglia di attacco
	}
	for(int i=3; i<6; i++)
	{
		user_placement_helper(p, 2, prow, prune, "nave di supporto "+std::to_string(i+1-3), 3, i);
		p.defence.ships[i] = new Support(prow, prune, p); 
	}
	for(int i=6; i<8; i++)
	{
		user_placement_helper(p, 1, prow, prune, "sottomarino "+std::to_string(i+1-6), 1, i);
		p.defence.ships[i] = new Submarine(prow, p); 
	}
	
	std::cout << "\n" + p.name + ", questa e' la disposizione delle tue navi\n";
	p.defence.print();
}

void user_placement_helper(Player& p, int n_coordinates, Position& prow, Position& prune, 
							std::string ship_name, int ship_size, int ship_number)
{
	bool ok = false;
	while(!ok)
	{
		if(n_coordinates==2)
			std::cout << ">> Quali sono le coordinate per la "+ship_name+":\n";
		else
			std::cout << ">> Qual e' la coordinata per il "+ship_name+":\n";
			
		std::string prow_str, prune_str;
		
		int code = command(prow, prune);
		if(code==-1)
		{
			std::cout << "Il comando inserito non e' valido\n";
			continue;
		}
		if(code==3)
		{
			p.defence.print();
			continue;
		}
		if(code==4 || code==5)
		{
			std::cout << "La funzione inserita non e' disponibile in fase di inserimento delle navi\n";
			continue;
		}
		
		if(code!=n_coordinates)
		{
			if(n_coordinates==2)
				std::cout << "Sono necessarie due posizioni\n";
			else
				std::cout << "E' necessaria una posizione\n";
			continue;
		}
		
		if(!p.defence.is_valid(prow,prune))
		{
			if(n_coordinates==2)
				std::cout << "Le posizioni inserite non sono valide\n";
			else
				std::cout << "La posizione inserita non e' valida\n";
				
			continue;
		}
		
		// il +1 compensa abs che non considera la cella finale
		if((prow-prune).abs()+1 != ship_size)
		{
			if(n_coordinates==2)
				std::cout << "La "+ship_name+" deve essere lunga "+std::to_string(ship_size)+" caselle\n";
			else
				std::cout << "Il "+ship_name+" deve occupare una casella\n";
			
			continue;
		}
		
		// tutti i controlli sono andati a buon fine
		ok = true;
	}
}

void bot_placement(Player& p)
{
	std::cout << "bot";
}

std::vector<std::string> split(std::string str, char delimiter)
{
	std::vector<std::string> vec;
	std::string temp;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]==delimiter)
		{
			vec.push_back(temp);
			temp="";
		}
		else
		{
			temp += str[i];
		}
	}
	vec.push_back(temp);
	return vec;
}