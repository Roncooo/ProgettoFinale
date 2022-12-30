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
	
}