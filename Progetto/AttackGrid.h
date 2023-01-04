//	author: BEATRICE BELLESSO

#ifndef AttackGrid_H
#define AttackGrid_H

#include "Grid.h"

class Ship;	//forward declaration

class AttackGrid : public Grid
{
public:
	AttackGrid();
	void set_shot(const Position& pos);
	void set_missed(const Position& pos);
	void update() override;
	void reset_sonar();
	static constexpr char hit = 'X';	// forse sarebbe meglio un altro nome
	static constexpr char water = 'O';
	static constexpr char sonar = 'Y';
};

#include "Ship.h"

#endif // AttackGrid_H
