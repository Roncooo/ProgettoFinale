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
	this->dimension = 3;
	this->not_hit = 'S';
	this->hit = 's';
	for(int j = 0; j < dimension; j++)	// inizializzazione di armor a 1
		armor[j] = 1;
	
	Position ordered_prune;	// ordino prua e poppa, inserisco nel vector pos e definisco center
	Position ordered_stern;
	if(prune.abs()<stern.abs())
	{
		ordered_prune = prune;
		ordered_stern = stern;
	}
	else
	{
		ordered_prune = stern;
		ordered_stern = prune;
	}
	if(ordered_prune.row == ordered_stern.row)
	{
		// setto anche il centro se prua.riga == poppa.riga
		this->center = ordered_prune + Position(0, (dimension/2));
		for(int i = 0; i < dimension; i++)
			pos[i] += Position(0,1);
	}
	else
	{
		// setto anche il centro altrimenti
		this->center = ordered_prune + Position((dimension/2), 0);
		for(int i = 0; i < dimension; i++)
			pos[i] += Position(1, 0);
	}
}

Support::~Support(){}

void Support::cure(const Position& pos, Ship& s)
{
	this->move(pos);	// mi muovo dove chiede l'utente
	/*for(int i = 0; i < s.dimension; i++)
	{
		if(!check_pos(s.pos[i]))	continue;	// se la posizione non è valida passo alla prossima
		else
			s.restore_armor();
	}*/
	for(int i = -1; i < 2; i++)
	{	
		for(int j = 0; j < 8; j++)	// nella seconda condizione della for ci va this->my_grid.ships.size() ma non mi compila
			for(int x = 0; x < my_grid.ships[j]->dimension; x++)
				if(this->center+Position(-1, i) != my_grid.ships[j]->pos[x])	continue;
				else
					my_grid.ships[j]->restore_armor();
	}
}