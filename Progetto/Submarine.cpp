// autore: 

#include "Submarine.h"

Submarine::Submarine(const Position& pos, Player& p) 
	: Ship(pos, pos, p)
{
	hit = 'e';
	not_hit = 'E';
}

Submarine::~Submarine(){}