// autore: 

#ifndef CORAZZATA_H
#define CORAZZATA_H

#include "Ship.h"
#include "AttackGrid.h"	// solo per chiarezza, in realtà è già inclusa da Ship

class Battleship : public Ship
{
public:
	Battleship(const Position& prow, const Position& stern, Player& p);
	void move() = delete;
	void shoot(const Position& pos) ;
//	int dimension = 5;		// settata dal costruttore di Ship
	~Battleship() override;
};

#endif // CORAZZATA_H
