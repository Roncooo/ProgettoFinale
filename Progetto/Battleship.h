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
	//	shoot ha come parametro la posizione su cui sparare e l'avversario da colpire
	void shoot(const Position& pos, Player& enemy);
//	int dimension = 5;		// settata dal costruttore di Ship
	~Battleship() override;
};

#endif // CORAZZATA_H
