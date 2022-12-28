// autore: 

#include "Ship.h"

Ship::Ship(const Position& prow, const Position& prune, DefenceGrid& grid)
{
	// MANCANO CONTROLLI DI VALIDITA' DELLA Position CON LE ALTRE NAVI
	
	grid.is_valid(prow, prune);
	
//	if(griglia.is_valid(poppa) && griglia.is_valid(prua))
	
}

Ship::~Ship(){}

void Ship::move(const Position& new_center)
{
	Position dislocation = new_center - center;
	for(int i=0; i<dimension; i++)
		pos[i] += dislocation;
	// manca controllo sulla nuova Position
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

void Ship::restore_armor()
{
	if(sunk) return;
	
	for(int i=0; i<dimension; i++)
		armor[i] = true;
}