//	author: BEATRICE BELLESSO

#include "Support.h"

using game_board::Position;

Support::Support(const Position& prune, const Position& stern, Player& p) 
	: Ship(prune, stern, p, 'S', 's')
{
}

std::string Support::ship_type() const
{
	return "support";
}

//Support::~Support(){}

// controlla se, rispetto al center di support, la nave da curare è nella posizione giusta
// dice se la posizione passata è curabile dalla nave di supporto che invoca la funzione
// quindi deve essere sufficentemente vicina e non può essere la nave stessa
bool Support::is_curable(const Position& p)
{
	for(int i = 0; i < get_dimension(); i++)
	{
		if(p == pos[i])			// se p è presente nel vector di posizioni di this ritorno
			return false;		// falso perche' non puo' autocurarsi
	}
	
	Position center = get_center();
	if( p != center+Position(-1,-1) && 	// top left
		p != center+Position(-1, 0) &&	// top
		p != center+Position(-1,+1) &&	// top right
		p != center+Position( 0,+1) &&	// right
		p != center+Position(+1,+1) &&	// bottom right
		p != center+Position(+1, 0) &&	// bottom
		p != center+Position(+1,-1) &&	// bottom left
		p != center+Position( 0,-1)  	)	// left
		return false;
	
	//	al posto di tutta la if scriverei così ma è da controllare
	//	return (p-center).abs()<2;
	//	ci sta, esce più compatto
	
	return true;
}

int Support::action(const Position& pos, Player& enemy)
{
	// mi muovo dove chiede l'utente se questo è possibile, altrimenti termina
	if(move(pos)==-1)
		return -2;		// non è possibile spostare la nave di supporto
	
	for(int j = 0; j < DefenceGrid::SHIP_NUMBER; j++)	// per ogni nave
	{
		for(int x = 0; x < player.defence.ships[j]->get_dimension(); x++)
		{	
			if(!is_curable(player.defence.ships[j]->pos[x]))
				continue;
			else
				player.defence.ships[j]->restore_armor();
		}
	}
	
	return 2;	//tutto è andato a buon fine
}

int Support::is_sunk()
{
	int code = Ship::is_sunk();
	if(code == 2)	// la nave è affondata ora
	{
		std::cout << "~~~Hai affondato una nave di supporto!~~~\n";
		return 1;	// è affondata (codice compatibile con true)
	}
	return code;
}
