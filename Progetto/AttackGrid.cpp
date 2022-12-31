// autore: 

#include "AttackGrid.h"

AttackGrid::AttackGrid()
{
}

void AttackGrid::set_shot(const Position& pos)
{
	set_char(pos, 'X');
}

void AttackGrid::missed_shot(const Position& pos)
{
	set_char(pos, 'O');
}

void AttackGrid::update()
{

	reset_matrix();
	DefenceGrid enemy;
	for(int i = 0; i < DefenceGrid::SHIP_NUMBER; i++)
	{
		for(int j = 0; j < enemy.ships[i]->armor.size(); j++)
			if(enemy.ships[i]->armor[j] == false)		// se all'indice j armor = 0
				set_char(enemy.ships->pos[j], 'X');		// in quella "posizione" setto X
	}
}