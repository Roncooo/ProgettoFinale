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

