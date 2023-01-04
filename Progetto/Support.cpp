//	author: BEATRICE BELLESSO

#include "Support.h"

Support::Support(const Position& prune, const Position& stern, Player& p) 
	: Ship(prune, stern, p)
{
	hit = 's';
	not_hit = 'S';
}

Support::~Support(){}

// controlla se, rispetto al center di support, la nave da curare è nella posizione giusta
// dice se la posizione passata è curabile dalla nave di supporto che invoca la funzione
// quindi deve essere sufficentemente vicina e non può essere la nave stessa
bool Support::is_curable(const Position& p)
{
	for(int i = 0; i < dimension; i++)
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

int Support::cure(const Position& pos)
{
	// mi muovo dove chiede l'utente se questo è possibile, altrimenti termina
	if(move(pos)==-1)
		return -1;
	
	for(int j = 0; j < DefenceGrid::SHIP_NUMBER; j++)	// per ogni nave
	{
		for(int x = 0; x < player.defence.ships[j]->dimension; x++)
		{	
			if(!is_curable(player.defence.ships[j]->pos[x]))
				continue;
			else
				player.defence.ships[j]->restore_armor();
		}
	}
	
	return 2;	//tutto è andato a buon fine
}