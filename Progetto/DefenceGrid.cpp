//	author: BEATRICE BELLESSO

#include "DefenceGrid.h"

using namespace game_board;

DefenceGrid::DefenceGrid()
{
	// intentionally left blank
}

DefenceGrid::~DefenceGrid()
{
	// intentionally left blank
}

// ritorna quante navi sono presenti nella griglia di difesa
int DefenceGrid::get_placed_ships() const
{
	return ships.size();
}

// aggiorna la griglia: se una nave è affondata non la riscrivo, altrimento setto
// il carattere hit o not_hit se la corazza in quel punto è integra o no
void DefenceGrid::update()
{
	reset_matrix();
	for(int i = 0; i < get_placed_ships(); i++)
	{
		for(int j = 0; j < ships[i]->get_dimension(); j++)
		{
			if(ships[i]->armor[j] == true)		// armor[i] è true se il pezzo è integro (non colpito)
				set_char(ships[i]->pos[j], ships[i]->not_hit);
			else
				set_char(ships[i]->pos[j], ships[i]->hit);
		}
	}
}

