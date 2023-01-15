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
	// raga qua c'era i<currently_placed_ships ma mi pare sbagliato no?
	// perché ships è ancora array e non vector, le navi non vengono eliminate dall'array
	// quindi se per esempio sono affondate le 3 navi di supporto, currently placed ships vale 5 
	// ma nelle posizioni 6 e 7 dell'array ci sono ancora sottomarini
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

