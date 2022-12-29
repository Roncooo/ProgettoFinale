#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include <regex>
#include <algorithm>	// per uppercase
//#include <limits> 		// per il flush del cin
//#include <ios> 			// per il flush del cin
#include "DefenceGrid.h"
#include "AttackGrid.h"
#include "Battleship.h"
#include "Submarine.h"
#include "Support.h"
#include "Player.h"

class Match
{
public:
	Match(const Player& p1, const Player& p2);
	Player player1;
	Player player2;
	void ship_placement(const Player& p);
};

#endif // MATCH_H
