//	author: BEATRICE BELLESSO

#include "Ship.h"

Ship::Ship(const Position& prow, const Position& prune, Player& p, char upper, char lower) 
	: player{p}, not_hit{upper}, hit{lower}
{	
	if(!p.defence.is_valid(prow, prune))
		throw std::invalid_argument("Posizioni non valide");
		
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
			pos[i] = (ordered_prow + Position(0, i));		
		else	// altrimenti hanno per forza colonna uguale
			pos[i] = (ordered_prow + Position(i, 0));
	}
	p.defence.currently_placed_ships++;
}

Ship::~Ship(){}

int Ship::get_dimension() const
{ 
	return dimension; 
}

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

Position Ship::get_center() const
{
	// funziona perché usiamo solo dimensioni dispari
	return pos[dimension/2];
}

int Ship::move(const Position& new_center)
{
	Position dislocation = new_center - get_center();
	
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

void Ship::restore_armor()
{
	if(sunk) return;
	
	for(int i=0; i<dimension; i++)
		armor[i] = true;
}

bool Ship::is_battleship() const
{ 
	return dimension == 5;
}

bool Ship::is_support() const
{ 
	return dimension == 3;
}

bool Ship::is_submarine() const
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
