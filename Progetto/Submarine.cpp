// autore: 

#include "Submarine.h"

bool Submarine::sub_area(Position& p)
{
	if(	this->pos[0].row - p.row <= 2 && this->pos[0].row - p.row >= -2 &&
		this->pos[0].col - p.col <= 2 && this->pos[0].col - p.col >= -2 	) 
			return true;
	return false;
}

Submarine::Submarine(const Position& pos, Player& p) 
	: Ship(pos, pos, p)
{
	hit = 'e';
	not_hit = 'E';
}

int Submarine::search(const Position& pos, Player& enemy)
{
	// muovo dove chiede l'utente, se questo è possibile
	// altrimenti termina
	if(move(pos)==-1)
		return -1;
	
	player.attack.reset_sonar();
	//	for per le navi
	for(int i = 0; i < DefenceGrid::SHIP_NUMBER; i++)
	{
		for(int j = 0; j < enemy.defence.ships[i]->dimension; j++)
		{
			if(!sub_area(enemy.defence.ships[i]->pos[j])) continue;
			else
				player.attack.set_char(enemy.defence.ships[i]->pos[j], AttackGrid::sonar);
		}
	}
}
Submarine::~Submarine(){}