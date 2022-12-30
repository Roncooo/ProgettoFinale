// autore: 

#include "Submarine.h"

Submarine::Submarine(const Position& pos, DefenceGrid& grid) 
	: Ship(pos, pos, grid)
{
	hit = 'e';
	not_hit = 'E';
}

Submarine::~Submarine(){}