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

void Battleship::shoot(const Position& pos, Player& enemy) 
{
	//controllo che la posizione sia valida??
	
	// necessito della griglia di difesa dell'avversario
	// (per ora abbozzo così)
	//	DefenceGrid enemy;
	//	** ora con l'inclusione di Player posso accedere alla griglia del mio avversario
	char target = (enemy.defence).get_char(pos);
	
	if (target == ' ')
	{
		//chiamo la funzione di AttackGrid che segnerà O
		player.attack.missed_shot(pos);
	}
	else
	{
		switch(target)
		{
			case 'C':	enemy.defence.set_char(pos, 'c');	break;
			case 'S':	enemy.defence.set_char(pos, 's');	break;
			case 'E':	enemy.defence.set_char(pos, 'e');	break;
		}
		//chiamo la funzione di AttackGrid che segnerà X
		player.attack.set_shot(pos);
		
		//diminuisco l'armatura della nave
		for (int i = 0; i < DefenceGrid::SHIP_NUMBER; i++)
		{
			for (int j = 0; j < enemy.defence.ships[i]->dimension; j++)
			{
				if (enemy.defence.ships[i]->pos[j] == pos){
					enemy.defence.ships[i]->armor[j] = false;
					
					//controllo se la nave è affondata
					if (enemy.defence.ships[i]->is_sunk()){
						currently_placed_ships--;
					}
					
				}
				}
			}
		}
		
		/
		
	}
}

Battleship::~Battleship(){}
