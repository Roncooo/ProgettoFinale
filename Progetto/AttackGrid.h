// autore: 

#ifndef AttackGrid_H
#define AttackGrid_H

#include "Grid.h"

class AttackGrid : public Grid
{
public:
	AttackGrid();
	void set_shot(const Position& pos);
	void missed_shot(const Position& pos);
	void update() override;
	static constexpr char hit = 'X';	// forse sarebbe meglio un altro nome
	static constexpr char water = 'O';
	static constexpr char sonar = 'Y';
};

#endif // AttackGrid_H
