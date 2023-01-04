// autore: FRANCESCO RONCOLATO

#ifndef Player_H
#define Player_H

#include <ctime>
#include <cstdlib>	// per la randomicità del giocatore computer
#include <algorithm>	// per uppercase
#include "AttackGrid.h"
#include "DefenceGrid.h"
//#include "Battleship.h"
//#include "Submarine.h"
//#include "Support.h"

class Player
{
public:
	Player(std::string n = "Player");
	// si può mettere una variabile statica per dare nomi di default Player1 Player2
	AttackGrid attack;
	DefenceGrid defence;
	const std::string name;
	bool is_cpu;
	bool auto_placement = false;
	bool operator==(const Player& p) const;
	bool receive_shot(const Position& pos);
	bool is_there_ship(const Position& pos) const;
	~Player();
};

#endif // Player_H
