// autore: 

#ifndef Submarine_H
#define Submarine_H

#include "Ship.h"

class Submarine : public Ship
{
public:
	void search(const Position& pos);		// non è const perché muove e poi cerca
	~Submarine() override;
};

#endif // Submarine_H
