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
	Match(Player& p1, Player& p2, Log& input);
	Log& file_log;
	Player& player1;
	Player& player2;
	
	// discerne l'utente umano/robotico
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

//static Log file_log = Log();
//
// --- HELPER FUNCTIONS ---

// interagisce con l'utente per ottenere un comando (speciale o non) con un formato valido
int command(game_board::Position& a, game_board::Position& b);
int random_command(Player& player, game_board::Position& origin, game_board::Position& target);
// usata solo durante il gioco, non nell'inserimento, esegue qualsiasi comando (speciale o non) passato
// se l'azione non è valida non viene eseguita e l'errore viene segnalato con exit codes
int execute(Player& player, Player& enemy, int code, const game_board::Position& origin, const game_board::Position& target);
// interagisce con l'utente per fargli inserire tutte le navi, si serve della funzione ausiliaria user_placement_helper
void user_placement(Player& p, Log& file_log);
void user_placement_helper(Player& p, int n_coordinates, game_board::Position& prow, game_board::Position& prune, 
							std::string ship_name, int ship_size, int ship_number, Log& file_log);
// richiede l'inserimento randomico delle navi
void bot_placement(Player& p, Log& file_log);
void bot_placement_helper(Player& p, int ship_size, game_board::Position& start, game_board::Position& end, Log& file_log);
game_board::Position random_position();
// funzione ausiliaria che ritorna la posizione distante dim da start in direzione direction
game_board::Position ortogonal_position(const game_board::Position& start, int dim, int direction);
// stampa il messaggio relativo al comando inserito
void print_code(int code, const game_board::Position& origin, const game_board::Position& target);
// stampa una tabella delle navi non ancora affondate
void recap(const Player& player1, const Player& player2);
// serve per l'inserimento umano
std::vector<std::string> split(std::string str, char delimiter);
#endif // MATCH_H
