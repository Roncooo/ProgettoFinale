#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include <regex>
#include <algorithm>	// per uppercase
//#include <limits> 		// per il flush del cin
//#include <ios> 			// per il flush del cin
#include "Player.h"
#include "DefenceGrid.h"
#include "AttackGrid.h"
// basterebbero anche solo queste sotto ma è più chiaro anche con le altre direi
#include "Battleship.h"
#include "Submarine.h"
#include "Support.h"

class Match
{
public:
	Match(const Player& p1, const Player& p2);
	Player player1;
	Player player2;
	void ship_placement(Player& p);
};

#endif // MATCH_H
