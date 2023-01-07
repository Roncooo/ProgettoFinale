// author: FRANCESCO RONCOLATO
#include "Battleship.h"

Battleship::Battleship(const Position& prow, const Position& stern, Player& player)
	: Ship(prow, stern, player, 'C', 'c')
	// chiamata al costruttore di Ship che fa i vari controlli e setta posizioni, armor e char
{
}

int Battleship::action(const Position& pos, Player& enemy) 
{
	// la versione precedente era sbagliata perché si basava sulla griglia del nemico che non per forza era aggiornata
	// con receive shot invece, chiedo al nemico se ho colpito (senza accedere direttamente alla sua griglia di difesa)
	// ed è lui ad arrangiarsi per sistemare la sua armatura e le sue navi, io giocatore devo solo segnarmi se ho colpito o no
	
	// dice se ho colpito nella griglia nemica o no	
	if(enemy.receive_shot(pos))
		player.attack.set_shot(pos);
	else
		player.attack.set_missed(pos);
		
	return 2;	// va sempre a buon fine
}

//Battleship::~Battleship(){}


int Battleship::is_sunk()
{
	int code = Ship::is_sunk();
	if(code == 2)	// la nave è affondata ora
	{
		std::cout << "~~~Hai affondato una corazzata!~~~\n";
		return 1;	// è affondata (codice compatibile con true)
	}
	return code;
}

