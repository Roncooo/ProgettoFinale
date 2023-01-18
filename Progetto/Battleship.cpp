//	author: FRANCESCO RONCOLATO

#include "Battleship.h"

using game_board::Position;

Battleship::Battleship(const Position& prow, const Position& stern, Player& player)
	: Ship(prow, stern, player, 'C', 'c')
	// chiamata al costruttore di Ship che fa i vari controlli e setta posizioni, armor e char
{
}

std::string Battleship::ship_type() const
{
	return "battleship";
}

int Battleship::action(const Position& pos, Player& enemy) 
{
	// la versione precedente era sbagliata perché si basava sulla griglia del nemico che non per forza era aggiornata
	// con receive shot invece, chiedo al nemico se ho colpito (senza accedere direttamente alla sua griglia di difesa)
	// ed è lui ad arrangiarsi per sistemare la sua armatura e le sue navi, io giocatore devo solo segnarmi se ho colpito o no
	
	// dice se ho colpito nella griglia nemica o no
	int code = enemy.receive_shot(pos);
	if(code == 30)
		player.attack.set_missed(pos);
	else	// colpita (e basta) o affondata
		player.attack.set_shot(pos);
		
	return code;	// se una nave è affondata la identifica ritornando 40 41 42 
}

//Battleship::~Battleship(){}


int Battleship::is_sunk()
{
	if(Ship::is_sunk() == 1)	// la nave non è affondata (necessariamente ora)
		return 40;
	
	return 0;	// non è affondata
}


