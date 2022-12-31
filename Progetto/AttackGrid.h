// autore: 

#ifndef AttackGrid_H
#define AttackGrid_H

#include "Grid.h"
#include "Ship.h"

class AttackGrid : public Grid
{
public:
	AttackGrid();
	void set_shot(const Position& pos);
	void missed_shot(const Position& pos);
	void update() override;
};

#endif // AttackGrid_H
