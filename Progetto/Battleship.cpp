// autore: 

#include "Battleship.h"

Battleship::Battleship(const Position& prow, const Position& stern, DefenceGrid& grid)
	: Ship(prow, stern, grid)
	//^^^^^ chiamata al costruttore di Ship che fa i vari controlli e setta posizioni e armor
{
	// credo non ci vada nient'altro
	hit = 'c';
	not_hit = 'C';
}

void Battleship::shoot(const Position& pos) const
{
	//controllo che la posizione sia valida??
	
	// necessito della griglia di difesa dell'avversario
	// (per ora abbozzo così)
	DefenceGrid enemy;
	char target = enemy.get_char(pos);
	
	if (target == ' ')
	{
		//chiamo la funzione di AttackGrid che segnerà O
	}
	else
	{
		switch(target)
		{
			case 'C':	enemy.set_char(pos, 'c');	break;
			case 'S':	enemy.set_char(pos, 's');	break;
			case 'E':	enemy.set_char(pos, 'e');	break;
		}
		
		//chiamo la funzione di AttackGrid che segnerà X
	}
}

Battleship::~Battleship(){}
