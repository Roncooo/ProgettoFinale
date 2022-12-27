// autore: 

#ifndef Player_H
#define Player_H

#include "AttackGrid.h"
#include "DefenceGrid.h"
#include "Battleship.h"
#include "Submarine.h"
#include "Support.h"

class Player
{
public:
	Player(std::string n = "Player");
	
	AttackGrid attack;
	DefenceGrid defence;
	std::string name;
	
	~Player();
};

#endif // Player_H
