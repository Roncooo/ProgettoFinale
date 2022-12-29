// autore: 

#include "Submarine.h"

Submarine::Submarine(const Position& pos, DefenceGrid& grid) 
	: Ship(pos, pos, grid)
{
}

Submarine::~Submarine(){}