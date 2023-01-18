//	author: BEATRICE BELLESSO

#include "Support.h"

using namespace game_board;

Support::Support(const Position& prune, const Position& stern, Player& p) 
	: Ship(prune, stern, p, 'S', 's')
{
	// intentionally left blank
}

std::string Support::ship_type() const
{
	return "support";
}

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
	
	return true;
}

// mi sposto dove chiede l'utente, se la posizione non e' valida ritorno, altrimenti curo
int Support::action(const Position& pos, Player& enemy)
{
	// mi muovo dove chiede l'utente se questo è possibile, altrimenti termina
	if(move(pos)==-1)
		return -2;		// non è possibile spostare la nave di supporto
	
	for(int j = 0; j < player.get_placed_ships(); j++)	// per ogni nave
	{
		for(int x = 0; x < player.get_ship(j).get_dimension(); x++)
		{	
			if(!is_curable(player.get_ship(j).pos[x]))
				continue;
			else
				player.restore_ship(j);
		}
	}
	
	return 33;	//tutto è andato a buon fine
}

int Support::is_sunk()
{
	if(Ship::is_sunk() == 1)	// la nave è affondata (necessariamente ora)
		return 41;
	
	return 0;	// non è affondata
}
