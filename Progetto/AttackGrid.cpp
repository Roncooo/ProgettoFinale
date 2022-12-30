// autore: 

#include "AttackGrid.h"

AttackGrid::AttackGrid()
{
}

void AttackGrid::set_shot(Position& pos)
{
	set_char(pos, 'X');
}

void AttackGrid::missed_shot(Position& pos)
{
	set_char(pos, 'O');
}