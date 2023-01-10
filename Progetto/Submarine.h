// autore: 

#ifndef Submarine_H
#define Submarine_H

#include "Ship.h"

class Submarine : public Ship
{
//	bool sub_area(Position& p);
public:
	Submarine(const game_board::Position& pos, Player& p);
	// enemy potrebbe essere anche const ma non lo è per uniformità con Ships::action virtuale pura
	int action(const game_board::Position& pos, Player& enemy) override;
	int is_sunk() override;		// l'override permette di stampare il messaggio con le informazioni della nave
	std::string ship_type() const override;
//	int dimension = 1;
//	~Submarine() override;
};

#endif // Submarine_H
