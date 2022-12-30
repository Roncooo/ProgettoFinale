// autore: 

#ifndef AttackGrid_H
#define AttackGrid_H

#include "Grid.h"

class AttackGrid : public Grid
{
public:
	AttackGrid();
	void set_shot(Position& pos);
	void missed_shot(Position& pos);
	void update() override {}
};

#endif // AttackGrid_H
