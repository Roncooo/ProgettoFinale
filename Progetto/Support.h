// autore: 

#ifndef Support_H
#define Support_H

#include "Ship.h"

class Support : public Nave
{
public:
	void cure(const Position& pos);		// non è const perché muove e poi cura
};

#endif // Support_H
