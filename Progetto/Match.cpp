#include "Match.h"

Match::Match(const Player& p1, const Player& p2)
	: player1{p1}, player2{p2}
{
	// altro?
}

void inserisci_prua_e_poppa_che_nome_di_merda(const Player& p, Position prow, Position prune, std::string ship_name, int ship_size, int ship_number)
{
	bool ok = false;
	while(!ok)
	{
		std::regex reg_position("[A-ILMN]([1-9]|1[012])");
		std::cout << "Quali sono le coordinate per la "+ship_name+":\n";
		std::string prow_str;
		std::string prune_str;
		std::cin >> prow_str;
		std::cin >> prune_str;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// pulisce eventuali residui nell'input
		std::transform(prow_str.begin(), prow_str.end(), prow_str.begin(), ::toupper);
		std::transform(prune_str.begin(), prune_str.end(), prune_str.begin(), ::toupper);
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

void user_placement(const Player& p)
{
	std::string ship_name = "corazzata 1";
	int ship_size = 5;
	int ship_number = 0; // da 0 a 7
	Position prow, prune;
	for(int i=0; i<3; i++)
	{
		inserisci_prua_e_poppa_che_nome_di_merda(p, prow, prune, "corazzata "+std::to_string(i+1), 5, i);
		p.defence.ships[i] = Battleship(prow, prune, p.defence); 
	}
	for(int i=0; i<3; i++)
	{
		inserisci_prua_e_poppa_che_nome_di_merda(p, prow, prune, "supporto "+std::to_string(i+1), 5, i);
		p.defence.ships[i] = Support(prow, prune, p.defence); 
	}
	// manca inserimento dei sottomarini che richiede un solo parametro quindi una funzione modificata
}

void bot_placement(const Player& p)
{
	std::cout << "bot";
}


void Match::ship_placement(const Player& p)
{
	if(p.is_cpu)
		bot_placement(p);
	else
		user_placement(p);
}
