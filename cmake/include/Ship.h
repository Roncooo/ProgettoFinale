//	author: BEATRICE BELLESSO

#ifndef Ship_H
#define Ship_H

#include <vector>
#include "Position.h"
#include "DefenceGrid.h"

class Player;	// forward declaration

class Ship
{
public:
	
	// throws std::invalid_argument se la griglia non è valida
	Ship(const game_board::Position& prow, const game_board::Position& stern, Player& p, char upper, char lower);
	Ship(Player& p, char upper, char lower):player{p}, hit{lower}, not_hit {upper}{};
	Player& player;
	// sono vector e non array perché a priori (compilazione) non conosco la loro 
	// dimensione (e una Ship generica non ha dimensione specifica)
	std::vector<game_board::Position> pos;
	// corazza, memorizza quali pezzi della Ship sono stati colpiti: pubblica perché su
	// receive_shot di Player vado a modificarne lo status
	// corazza(armor[i]) integra = true;
	// corazza(armor[i]) colpita = false;
	std::vector<bool> armor;
	char hit;
	char not_hit;
	
	int get_armor() const;
	int get_dimension() const;
	game_board::Position get_center() const;
	
	int move(const game_board::Position& new_pos);
	void restore_armor();
	virtual int is_sunk()=0;
	virtual std::string ship_type() const =0;
	// non è const perché può muovere e poi agire
	virtual int action(const game_board::Position& target, Player& enemy)=0;
	
private:
	bool sunk = false;
	int dimension;
};

#include "Player.h"

#endif // Ship_H
