// autore: 

#include "Ship.h"

Ship::Ship(const Position& prow, const Position& prune, Player& p) 
	: player{p}
{	
	if(!p.defence.is_valid(prow, prune))
		throw std::invalid_argument("Posizioni non valide");	// non dovrebbe essere lanciata dato che facciamo
																// il controllo nella funzione di inserimento
	Position ordered_prow;
	Position ordered_prune;
	if(prow.abs() < prune.abs())
	{
		ordered_prow = prow;
		ordered_prune = prune;
	}
	else
	{
		ordered_prow = prune;
		ordered_prune = prow;
	}
	
	dimension = (prune-prow).abs() +1;
	pos = std::vector<Position>(dimension);
	armor = std::vector<bool>(dimension);
	for(int i = 0; i < dimension; i++)
		armor[i] = true;
		
	for(int i = 0; i < dimension; i++)
	{
		if(ordered_prow.row == ordered_prune.row)
		{
			pos[i] = (ordered_prow + Position(0, i));		
			center = ordered_prow + Position(0, (dimension/2));
		}
		else	// altrimenti hanno per forza colonna uguale
		{
			pos[i] = (ordered_prow + Position(i, 0));
			center = ordered_prow + Position((dimension/2), 0);
		}
	}
	
	p.defence.currently_placed_ships++;
}

Ship::~Ship(){}

int Ship::move(const Position& new_center)
{
	Position dislocation = new_center - center;
	
	// controlla sia che la nave sia completamente dentro alla griglia, sia che non sormonti altre navi
	if(player.defence.is_valid(pos[0]+dislocation,pos[dimension-1]+dislocation))
	{
		for(int i=0; i<dimension; i++)
			pos[i] += dislocation;
		
		return 2;	//tutto è andato a buon fine
	}
	else
		return -1;	// non è possibile spostare la nave nella nuova posizione
}

//bool Ship::control(DefenceGrid& enemy){
//	for(int i=0; i<dimension; i++){
//		if (pos[i] == enemy.ship[i]->pos[i])
//			return false
//	}
//	return true;
//}

int Ship::get_armor() const
{
	int c = 0;
	for(int i=0; i<dimension; i++)
	{
		if(armor[i] == true)
			c++;
	}
	return c;
}

void Ship::restore_armor()
{
	if(sunk) return;
	
	for(int i=0; i<dimension; i++)
		armor[i] = true;
}

bool Ship::is_battleship()
{ 
	return dimension == 5;
}
bool Ship::is_support()
{ 
	return dimension == 3;
}
bool Ship::is_submarine()
{
	return dimension == 1;
}

bool Ship::is_sunk()
{
	for (int i = 0; i < armor.size(); i++){
		if (armor[i] == true)	//se almeno un armatura è intatta, la nave non è affondata
			return false;
	}
	
	//se arrivo qui, tutte le armature == false
	sunk = true;
	return true;
}