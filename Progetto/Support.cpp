// autore: 

#include "Support.h"

Support::Support(const Position& prune, const Position& stern, DefenceGrid& grid) : Ship(prune, stern, grid)
{
	this->dimension = 3;
	this->not_hit = 'S';
	this->hit = 's';
	for(int j = 0; j < dimension; j++)	// inizializzazione di armor a 1
		armor[j] = 1;
	
	Position ordered_prune;	// ordino prua e poppa e inserisco nel vector pos
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
void Support::cure(const Position& pos)
{
	
}