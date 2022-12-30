// autore: 

#include "Ship.h"

Ship::Ship(const Position& prow, const Position& prune, DefenceGrid& grid) 
	: my_grid{grid}
{	
	if(!grid.is_valid(prow, prune))
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
	
	dimension = ordered_prune.abs() - ordered_prow.abs();
	pos = std::vector<Position>(dimension);
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
	
	armor = std::vector<bool>(dimension);
	for(int i = 0; i < dimension; i++)
		armor[i] = true;
	
	my_grid.currently_placed_ships++;
}

Ship::~Ship(){}

void Ship::move(const Position& new_center)
{
	Position dislocation = new_center - center;
	for(int i=0; i<dimension; i++)
		pos[i] += dislocation;
	// manca controllo sulla nuova Position
	
	// è necessaria una funzione che abbia come parametro la griglia di difesa dell'avversario, tipo quella commentata qui sotto
	// p.s. non so nemmeno se compila, è solo un'idea
	
	
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