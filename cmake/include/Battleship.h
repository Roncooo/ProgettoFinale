// author: FRANCESCO RONCOLATO

#ifndef CORAZZATA_H
#define CORAZZATA_H

#include "Ship.h"
#include "AttackGrid.h"	// solo per chiarezza, in realtà è già inclusa da Ship

class Battleship : public Ship
{
public:
	Battleship(const game_board::Position& prow, const game_board::Position& stern, Player& p);
	void move() = delete;
	//	shoot ha come parametro la posizione su cui sparare e l'avversario da colpire
	int action(const game_board::Position& pos, Player& enemy) override;
	int is_sunk() override;		// l'override permette di stampare il messaggio con le informazioni della nave
	std::string ship_type() const override;
//	int dimension = 5;		// settata dal costruttore di Ship
//	~Battleship() override;
};

#endif // CORAZZATA_H
