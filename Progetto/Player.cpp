#include "Player.h"

Player::Player(std::string n)
	: name{n}
{
	// attack e defence inizializzate di default
	if(n.substr(0,3) == "CPU")
		is_cpu = true;
	else
		is_cpu = false;
}

bool Player::operator==(const Player& p) const
{
	return p.name==this->name;
}

bool Player::receive_shot(const Position& shot_position)
{
	for(int ship_index=0; ship_index<DefenceGrid::SHIP_NUMBER; ship_index++)
	{
		for(int pos_index=0; pos_index<defence.ships[ship_index]->dimension; pos_index++)
		{
			if(defence.ships[ship_index]->pos[pos_index] == shot_position)
			{
				// segno che è stato colpito il pezzo
				defence.ships[ship_index]->armor[pos_index] = false;
				// controllo se è affondata
				if(defence.ships[ship_index]->get_armor() == 0)
					defence.ships[ship_index]->sunk = true;
				// dico al nemico che ha colpito
				return true;
			}
		}
	}
	// dico al nemico che non ha colpito
	return false;
}

Player::~Player()
{
}

