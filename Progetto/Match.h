// author: FRANCESCO RONCOLATO

#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>		// per uppercase

#include "Log.h"
#include "Player.h"
#include "DefenceGrid.h"
#include "AttackGrid.h"
// basterebbero anche solo queste sotto ma è più chiaro anche con le altre direi
#include "Battleship.h"
#include "Submarine.h"
#include "Support.h"

class Match
{
private:
	static std::regex reg_position;	// inizializzata nel costruttore per comodità, riconosce il comando relativo ad una posizione valida
public:
	Match(Player& p1, Player& p2/*, Log& input*/);
//	Log& file_log;
	Player& player1;
	Player& player2;
	void ship_placement(Player& p);
	
	static constexpr int MAX_ROUNDS = 2000;	// boh a caso raga
	void play();
	void re_play(std::ifstream input);
	
	/* Command restituisce un exit code che identifica il comando inserito da tastiera
	 * Se l'input è compatibile con due posizioni, modifica i parametri
	 * -1: comando non valido
	 *  1: una posizione inserita (inserimento del sottomarino), posizioni modificate
	 *  2: due posizioni inserite, posizioni modificate
	 *  3: stampa della matrice di difesa
	 *  4: stampa delle matrice di difesa e attacco
	 *  5: cancella i sonar
	 * altro...?
	 */
	// gli exit code servono perché coma comando sa se è andato a buon fine
};
int command(game_board::Position& a, game_board::Position& b);
static Log file_log = Log();

#endif // MATCH_H
