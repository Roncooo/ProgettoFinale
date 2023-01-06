//	author: BEATRICE BELLESSO

#include "DefenceGrid.h"

DefenceGrid::DefenceGrid()
{
}

DefenceGrid::~DefenceGrid()
{
//	delete[] ships;
//	for(int i=0; i<SHIP_NUMBER; i++)
//	{
//		delete ships[i];
//	}
}

void DefenceGrid::update()
{
	reset_matrix();
	for(int i = 0; i < currently_placed_ships; i++)
	{
		if(ships[i]->is_sunk() == true) continue;	// se la nave è affondata vado alla prossima
		
		for(int j = 0; j < ships[i]->get_dimension(); j++)
		{
			if(ships[i]->armor[j] == true)		// armor[i] è true se il pezzo è integro (non colpito)
				set_char(ships[i]->pos[j], ships[i]->not_hit);
			else
				set_char(ships[i]->pos[j], ships[i]->hit);
		}
	}
}

bool DefenceGrid::is_valid(const Position& prow, const Position& prune) const
{
	// controllo <0 e >12
	if(!Grid::is_valid(prune) || !Grid::is_valid(prow))
		return false;
		
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
	
	// la nave deve essere orizzontale o verticale
	if(ordered_prow.get_row() != ordered_prune.get_row() && ordered_prow.get_col() != ordered_prune.get_col())
		return false;
	
	// controllo che non ci siano già navi NON AFFONDATE nelle posizioni tra prua e poppa (comprese)
	Position vec = (ordered_prune-ordered_prow).norm();
			// se funziona tutto non dovrebbe essere un ciclo infinito
			// "ma diciamocelo, il rischio c'è"
	for(Position current=ordered_prow; current!=ordered_prune+vec; current+=vec)		// per ogni posizione tra prua e poppa
	{
		for(int s=0; s<currently_placed_ships; s++)				// per ogni nave nella griglia
		{
			// se la nave è affondata non crea problemi e ci si può passare sopra quindi passo alla prossima nave
			if(ships[s]->is_sunk())
				continue;
			
			// per ogni posizione della nave
			for(int p=0; p<ships[s]->get_dimension(); p++)
			{
				// se la posizione che voglio controllare appartiene ad una nave
				if(ships[s]->pos[p] == current)
					return false;
			}
		}
	}
	return true;
	
	// questa versione controlla attraverso la matrice che quindi dovrebbe essere sempre aggiornata ma non lo è
//	for(int i=0; i<(ordered_prow-ordered_prune).abs(); i++)
//	{
//		if(ordered_prow.row == ordered_prune.row)	// se sono in riga
//		{
//			if(get_char(ordered_prune+(i,0)) != ' ')	// scorro verso destra
//				return false;
//		}
//		
//		if(ordered_prow.col == ordered_prune.col)	// se sono in colonna
//		{
//			if(get_char(ordered_prune+(0,i)) != ' ')	// scorro verso il basso
//				return false;
//		}
//	}
}