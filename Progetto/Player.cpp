// author: FRANCESCO RONCOLATO

#include "Player.h"

Player::Player(std::string n)
	: name{n}
{
	// attack e defence inizializzate di default
	std::string temp_name = name;
	std::transform(name.begin(), name.end(), temp_name.begin(), ::toupper);
	if(temp_name.substr(0,3) == "CPU")	
	{
		is_cpu = true;
		auto_placement = true;
	}
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
		for(int pos_index=0; pos_index<defence.ships[ship_index]->get_dimension(); pos_index++)
		{
			if(defence.ships[ship_index]->pos[pos_index] == shot_position)
			{
				// segno che è stato colpito il pezzo
				defence.ships[ship_index]->armor[pos_index] = false;
				// controllo se sono rimaste armature (e in caso affonda)
				if (defence.ships[ship_index]->is_sunk())
					{
						defence.ships[ship_index]->sinking();
					}
				// dico al nemico che ha colpito
				return true;
			}
		}
	}
	// dico al nemico che non ha colpito
	return false;
}


bool Player::is_there_ship(const Position& sonar_request) const
{
	for(int ship_index=0; ship_index<DefenceGrid::SHIP_NUMBER; ship_index++)
	{
		// se la nave è affondata completamente, non verrà vista dal sonar
		if(defence.ships[ship_index]->is_sunk())
			continue;
		
		for(int pos_index=0; pos_index<defence.ships[ship_index]->get_dimension(); pos_index++)
		{
			if(defence.ships[ship_index]->pos[pos_index] == sonar_request)
			{
				return true;
			}
		}
	}
	return false;
}

Player::~Player()
{
}

