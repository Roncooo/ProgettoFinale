//	author: BEATRICE BELLESSO

#ifndef Support_H
#define Support_H

#include "Ship.h"
#include "DefenceGrid.h"


class Support : public Ship
{
	bool is_curable(const game_board::Position& p);
public:
	Support(const game_board::Position& prow, const game_board::Position& stern, Player& p); 
	// il parametro enemy serve solo per uniformità con Ship::action virtuale pura
	int action(const game_board::Position& pos, Player& enemy) override;
	// l'override permette di stampare il messaggio con le informazioni della nave	
	int is_sunk() override;
	int sunk_code() const override;
	std::string ship_type() const override;
};
#endif // Support_H
