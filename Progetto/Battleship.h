// autore: 

#ifndef CORAZZATA_H
#define CORAZZATA_H

#include "Ship.h"
#include "AttackGrid.h"

class Battleship : public Ship
{
public:
	Battleship(const Position& prow, const Position& stern, DefenceGrid& defence, AttackGrid& attack);
	void move() = delete;
	void shoot(const Position& pos) ;
//	int dimension = 5;		// settata dal costruttore di Ship
	AttackGrid& my_attack_grid;
	~Battleship() override;
};

#endif // CORAZZATA_H
