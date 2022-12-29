// autore: 

#include "Ship.h"

Ship::Ship(const Position& prow, const Position& prune, DefenceGrid& grid) : my_grid{grid}
{
	// MANCANO CONTROLLI DI VALIDITA' DELLA Position CON LE ALTRE NAVI
	
	grid.is_valid(prow, prune);
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
	if(ordered_prow.row == ordered_prune.row)
	{
		dimension = (ordered_prune.col - ordered_prow.col)+1;
		for(int i = 0; i < dimension; i++)
			pos[i] = ordered_prow + Position(0, i);
		Position center = ordered_prow + Position(0, (dimension/2));
	}
	else	// altrimenti hanno per forza colonna uguale
	{
		dimension = (ordered_prune.row - ordered_prow.row)+1;
		for(int i = 0; i < dimension; i++)
			pos[i] = ordered_prow + Position(i, 0);
		Position center = ordered_prow + Position((dimension/2), 0);
	}
	for(int i = 0; i < dimension; i++)
		armor[i] = true;
	//	my_grid = grid; // deve essere inizializzata con un'init list altrimenti essendo
	//	una reference il compilatore si incazza
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