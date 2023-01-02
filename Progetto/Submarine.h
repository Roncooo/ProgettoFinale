// autore: 

#ifndef Submarine_H
#define Submarine_H

#include "Ship.h"

class Submarine : public Ship
{
	bool sub_area(Position& p);
public:
	void search(const Position& pos, Player& pippo);		// non è const perché muove e poi cerca
	Submarine(const Position& pos, Player& p);
//	int dimension = 1;
	~Submarine() override;
};

#endif // Submarine_H
