//	author: BEATRICE BELLESSO 

#include "AttackGrid.h"

using namespace game_board;

AttackGrid::AttackGrid()
{
	// intentionally left blank
}

void AttackGrid::set_shot(const Position& pos)
{
	set_char(pos, hit);
}

void AttackGrid::set_missed(const Position& pos)
{
	set_char(pos, water);
}

void AttackGrid::update()
{
	// intentionally left blank
}

// tolgo gli avvistamenti sonar
void AttackGrid::reset_sonar()
{
	for(int r=0; r<rows; r++)
	{
		for(int c=0; c<cols; c++)
		{
			Position pos(r,c);
			if( get_char(pos) == sonar_undamaged ||
				get_char(pos) == sonar_damaged		)
				set_char(pos,empty_char);
		}
	}
}

