// autore: 

#include "Battleship.h"

Battleship::Battleship(const Position& prow, const Position& stern, Player& player)
	: Ship(prow, stern, player)
	//^^^^^ chiamata al costruttore di Ship che fa i vari controlli e setta posizioni e armor
{
	// credo non ci vada nient'altro
	
	hit = 'c';
	not_hit = 'C';
}

void Battleship::shoot(const Position& pos) 
{
	//controllo che la posizione sia valida??
	
	// necessito della griglia di difesa dell'avversario
	// (per ora abbozzo così)
	DefenceGrid enemy;
	char target = enemy.get_char(pos);
	
	if (target == ' ')
	{
		//chiamo la funzione di AttackGrid che segnerà O
		player.attack.missed_shot(pos);
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
		player.attack.set_shot(pos);
		
		//diminuisco l'armatura della nave
		for (int i = 0; i < enemy.SHIP_NUMBER; i++)
		{
			for (int j = 0; j < enemy.ships[i]->dimension; j++)
			{
				if (enemy.ships[i]->pos[j] == pos)
					enemy.ships[i]->armor[j] == false;
			}
		}
		
	}
}

Battleship::~Battleship(){}
