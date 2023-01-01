#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include <regex>
#include <algorithm>		// per uppercase
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
private:
	static std::regex reg_position;	// inizializzata nel costruttore per comodità, riconosce il comando relativo ad una posizione valida
public:
	Match(const Player& p1, const Player& p2);
	Player player1;
	Player player2;
	void ship_placement(Player& p);
	
	static int command(Position& a, Position& b);
	/* Command restituisce un exit code che identifica il comando inserito da tastiera
	 * Se l'input è compatibile con due posizioni, modifica i parametri
	 * -1: comando non valido
	 *  0: stampa della matrice
	 *  1: una posizione inserita (inserimento del sottomarino), posizioni modificate
	 *  2: due posizioni inserite, posizioni modificate
	 * 3?: cancella i sonar
	 * altro...?
	 */
	// gli exit code servono perché così chi chiama comando sa se è andato a buon fine
};

#endif // MATCH_H
