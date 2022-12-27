// autore: 

#include "DefenceGrid.h"

DefenceGrid::DefenceGrid()
{
}

void DefenceGrid::update()
{
	reset_matrix();
	for(int i = 0; i < SHIP_NUMBER; i++)
	{
		if(ships[i]->sunk == true) continue; // se la nave e'affondata vado alla prossima
		
		for(int j = 0; j < ships[i]->dimension; j++)
		{
			if(ships[i]->armor[j] == false) // corazza a 1 se non e'stata colpita
				set_char(ships[i]->pos[j], ships[i]->hit);
			else
				set_char(ships[i]->pos[j], ships[i]->not_hit);
		}
	}
}

bool DefenceGrid::is_valid(const Position& prow, const Position& prune) const
{
	Position ordered_prow;		// è la Position più vicina all'origine
	Position ordered_prune;
	if(prow.abs()<prune.abs())
	{
		ordered_prow = prow;
		ordered_prune = prune;
	}
	else
	{
		ordered_prow = prune;
		ordered_prune = prow;
	}
	
	// controllo <0 e >12
	if(!Grid::is_valid(ordered_prune) || !Grid::is_valid(ordered_prow))
		return false;
	
	if(ordered_prow.row != ordered_prune.row && ordered_prow.col != ordered_prune.col)	// nè orizzontale nè verticale
		return false;
	
	for(int i=0; i<(ordered_prow-ordered_prune).abs(); i++)
	{
		if(ordered_prow.row == ordered_prune.row)	// se sono in riga
		{
			if(get_char(ordered_prune+(i,0)) != ' ')	// scorro verso destra
				return false;
		}
		
		if(ordered_prow.col == ordered_prune.col)	// se sono in colonna
		{
			if(get_char(ordered_prune+(0,i)) != ' ')	// scorro verso il basso
				return false;
		}
	}
	
	return true;
}