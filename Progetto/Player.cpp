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

Player::~Player()
{
}

