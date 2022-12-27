// autore: 

#ifndef CORAZZATA_H
#define CORAZZATA_H

#include "Ship.h"

class Battleship : public Ship
{
public:
	void move() = delete;
	void shoot(const Position& pos) const;
};

#endif // CORAZZATA_H
