//	author: FRANCESCO RONCOLATO

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Ship.h"
#include "AttackGrid.h"

class Battleship : public Ship
{
public:
	Battleship(const game_board::Position& prow, const game_board::Position& stern, Player& p);
	void move() = delete;
	int action(const game_board::Position& pos, Player& enemy) override;
	// l'override permette di ritornare il codice con le informazioni della nave
	int is_sunk() override;
	std::string ship_type() const override;
};

#endif // CORAZZATA_H
