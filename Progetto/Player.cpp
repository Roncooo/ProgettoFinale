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
				// aggiorna lo stato di affondamento ed eventualmente lo dice
				defence.ships[ship_index]->is_sunk();
				// dico al nemico che ha colpito
				return true;
			}
		}
	}
	// dico al nemico che non ha colpito
	return false;
}


int Player::is_there_ship(const Position& sonar_request) const
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
				if(defence.ships[ship_index]->armor[pos_index] == true)
					return 2;	// se l'armatura della nave risulta intatta ritorno un codice valido 2
				else
					return 1;	// pezzo di nave colpito
			}
		}
	}
	return -1;	// nella posizione richiesta non c'è una nave
}

Player::~Player()
{
}

//Ship* Player::get_ship(int index)
//{
//	// occhio a possibili dangling pointers
//	return defence.ships[index].get();
//} 

void Player::print_defence()
{
	Grid::print(defence);
}

void Player::print_defence_attack()
{
	Grid::print(defence, attack);
}

// questa è la più rognosetta
//int Player::add_ship(std::unique_ptr<Ship> to_add)
//{
//	defence.ships[defence.currently_placed_ships] = to_add;
//}

int Player::act_ship(int index, const Position& target, Player& enemy)
{
	if(index==-1)	// get_ship_index non ha trovato il centro della nave
		return -4;
	return defence.ships[index]->action(target, enemy);
}

bool Player::has_lost()
{
	// per ciascuna nave nemica, se è una Corazzata e non è affondata, p non ha ancora vinto
	for(int i=0; i<DefenceGrid::SHIP_NUMBER; i++)
	{
		if(!defence.ships[i]->is_sunk())
			return false;
	}
	return true;
}

int Player::get_ship_index(const Position& pos) const
{
	for(int i=0; i<DefenceGrid::SHIP_NUMBER; i++)
	{
		Position ship_center = defence.ships[i]->get_center();
		// come da consegna, una nave si individua dalla sua posizione centrale
		// si potrebbe individuare una nave da una sua qualsiasi posizione modificando questa if
		if(pos==ship_center)
			return i;
	}
	return -1;
}
