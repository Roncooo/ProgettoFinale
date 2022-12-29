// autore: 

#include "Battleship.h"

Battleship::Battleship(const Position& prow, const Position& stern, DefenceGrid& grid)
	: Ship(prow, stern, grid)
	//^^^^^ chiamata al costruttore di Ship che fa i vari controlli e setta posizioni e armor
{
	// credo non ci vada nient'altro
}

Battleship::~Battleship(){}
