// autore: 

#include "Support.h"



// controlla se, rispetto al center di support, la nave da curare è nella posizione giusta
bool Support::check_pos(const Position& p)
{
	// nave di supporto cura le navi nel raggio di 3x3 dal centro, non puo' autocurarsi
	for(int i = 0; i < this->dimension; i++)
	{
		if(this->pos[i] == p)		// se p è presente nel vector di posizioni di this ritorno
			return false;			// falso perche' non puo' autocurarsi
	}
	
	if( p != (this->center)+Position(-1,-1) && 	// top left
		p != (this->center)+Position(-1, 0) &&	// top
		p != (this->center)+Position(-1,+1) &&	// top right
		p != (this->center)+Position(0, +1) &&	// right
		p != (this->center)+Position(+1,+1) &&	// bottom right
		p != (this->center)+Position(+1, 0) &&	// bottom
		p != (this->center)+Position(+1,-1) &&	// bottom left
		p != (this->center)+Position(0, -1)  	)	// left
		return false;
	
	return true;
}

Support::Support(const Position& prune, const Position& stern, DefenceGrid& grid) 
	: Ship(prune, stern, grid)
{
}

Support::~Support(){}

void Support::cure(const Position& pos, Ship& s)
{
	this->move(pos);	// mi muovo dove chiede l'utente
	for(int j = 0; j < 8; j++)	// nella seconda condizione della for ci va this->my_grid.ships.size() ma non mi compila
		for(int x = 0; x < my_grid.ships[j]->dimension; x++)
			if(!check_pos(my_grid.ships[j]->pos[x]))	continue;
			else
				my_grid.ships[j]->restore_armor();
}