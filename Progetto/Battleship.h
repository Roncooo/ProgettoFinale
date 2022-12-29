// autore: 

#ifndef CORAZZATA_H
#define CORAZZATA_H

#include "Ship.h"

class Battleship : public Ship
{
public:
	Battleship(const Position& prow, const Position& stern, DefenceGrid& grid);
	void move() = delete;
	void shoot(const Position& pos) const;
//	int dimension = 5;		// settata dal costruttore di Ship
	char hit = 'c';
	char not_hit = 'C';
	~Battleship() override;
};

#endif // CORAZZATA_H
