#include "Match.h"

Match::Match(const Player& p1, const Player& p2)
	: player1{p1}, player2{p2}
{
	// altro?
}

void user_placement_helper(const Player& p, int n_coordinates, Position& prow, Position& prune, 
							std::string ship_name, int ship_size, int ship_number);
void user_placement(Player& p);
void bot_placement(Player& p);

void Match::ship_placement(Player& p)
{
	if(p.is_cpu)
		bot_placement(p);
	else
		user_placement(p);
}

void user_placement(Player& p)
{
	std::cout << p.name + " inserisci le tue navi\n";
	Position prow, prune;
	
	for(int i=0; i<3; i++)
	{
		user_placement_helper(p, 2, prow, prune, "corazzata "+std::to_string(i+1), 5, i);
		p.defence.ships[i] = new Battleship(prow, prune, p.defence); 
	}
	for(int i=3; i<6; i++)
	{
		user_placement_helper(p, 2, prow, prune, "nave di supporto "+std::to_string(i+1-3), 3, i);
		p.defence.ships[i] = new Support(prow, prune, p.defence); 
	}
	for(int i=6; i<8; i++)
	{
		user_placement_helper(p, 1, prow, prune, "sottomarino "+std::to_string(i+1-6), 1, i);
		p.defence.ships[i] = new Submarine(prow, p.defence); 
	}
}

void user_placement_helper(const Player& p, int n_coordinates, Position& prow, Position& prune, std::string ship_name, int ship_size, int ship_number)
{
	bool ok = false;
	while(!ok)
	{
		// la Regular Expression così impostata descrive una qualsiasi coppia di coordinate formata da
		// una lettera maiuscola nell'intervallo A-I oppure L M N
		// e un numero nell'intervallo 1-9 oppure 1 seguito da 0 o 1 o 2, in altre parole un numero da 1 a 12
//		std::regex reg_position("[A-ILMN]([1-9]|1[012])");
		std::string reg_rule = "[";
		for(int i=0; i<Grid::rows; i++)
			reg_rule += Grid::letters[i];
		reg_rule+="]([1-9]|1[012])";
		std::regex reg_position(reg_rule);
		
		if(n_coordinates==2)
			std::cout << ">> Quali sono le coordinate per la "+ship_name+":\n";
		else
			std::cout << ">> Qual e' la coordinata per il "+ship_name+":\n";
			
		std::string prow_str, prune_str;
		std::cin >> prow_str;		// memorizza la prima coppia di coordinate
		if(n_coordinates==2)
			std::cin >> prune_str;	// e la seconda, saltando lo spazio
		else
			prune_str = prow_str;	// nel caso del sottomarino chiedo all'utente una sola coordinata 
									// ma la tratto come due uguali così il resto del codice non cambia
		// pulisce eventuali residui nell'input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// trasformo in uppercase le due stringhe
		std::transform(prow_str.begin(), prow_str.end(), prow_str.begin(), ::toupper);
		std::transform(prune_str.begin(), prune_str.end(), prune_str.begin(), ::toupper);
		// confronto con il pattern di riferimento
		if(!std::regex_match(prow_str, reg_position) || !std::regex_match(prune_str, reg_position))
		{
			std::cout << "Il comando inserito non e' valido\n";
			continue;
		}
		
		prow = (prow_str);
		prune = (prune_str);
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
