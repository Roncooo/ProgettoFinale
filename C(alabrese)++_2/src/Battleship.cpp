//	author: FRANCESCO RONCOLATO

#include "Battleship.h"

using game_board::Position;

Battleship::Battleship(const Position& prow, const Position& stern, Player& player)
	: Ship(prow, stern, player, 'C', 'c')
	// chiamata al costruttore di Ship che fa i vari controlli e setta posizioni, armor e char
{
	// intentionally left blank
}

std::string Battleship::ship_type() const
{
	return "battleship";
}

int Battleship::action(const Position& pos, Player& enemy) 
{
	// dice se ho colpito nella griglia nemica o no
	int code = enemy.receive_shot(pos);
	if(code == 30)
		player.attack.set_missed(pos);
	else	// colpita (e basta) o affondata
		player.attack.set_shot(pos);
		
	return code;	// se una nave è affondata la identifica ritornando 40 41 42 
}

int Battleship::is_sunk()
{
	if(Ship::is_sunk() == 1)	// la nave non è affondata (necessariamente ora)
		return 40;
	
	return 0;	// non è affondata
}

