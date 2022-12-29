#include "Match.h"

Match::Match(const Player& p1, const Player& p2)
	: player1{p1}, player2{p2}
{
	// altro?
}

void user_placement_helper(const Player& p, Position& prow, Position& prune, std::string ship_name, int ship_size, int ship_number);
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
		user_placement_helper(p, prow, prune, "corazzata "+std::to_string(i+1), 5, i);
		p.defence.ships[i] = new Battleship(prow, prune, p.defence); 
	}
	for(int i=0; i<3; i++)
	{
		user_placement_helper(p, prow, prune, "supporto "+std::to_string(i+1), 3, i);
		p.defence.ships[i] = new Support(prow, prune, p.defence); 
	}
	// manca inserimento dei sottomarini che richiede un solo parametro quindi una funzione modificata
}

void user_placement_helper(const Player& p, Position& prow, Position& prune, std::string ship_name, int ship_size, int ship_number)
{
	bool ok = false;
	while(!ok)
	{
		// la Regular Expression così impostata descrive una qualsiasi coppia di coordinate formata da
		// una lettera maiuscola nell'intervallo A-I oppure L M N
		// e un numero nell'intervallo 1-9 oppure 1 seguito da 0 o 1 o 2, in altre parole un numero da 1 a 12
		std::regex reg_position("[A-ILMN]([1-9]|1[012])");
		std::cout << ">> Quali sono le coordinate per la "+ship_name+":\n";
		std::string prow_str, prune_str;
		std::cin >> prow_str;	// memorizza la prima coppia di coordinate
		std::cin >> prune_str;	// e la seconda, saltando lo spazio
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// pulisce eventuali residui nell'input
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
		if(!p.defence.is_valid(prow, prune))
		{
			std::cout << "Le posizioni inserite non sono valide\n";
			continue;
		}
		
		// il +1 compensa abs che non considera la cella finale
		if((prow-prune).abs()+1 != ship_size)
		{
			std::cout << "La "+ship_name+" deve essere lunga "+std::to_string(ship_size)+" caselle\n";
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
