//	author: FRANCESCO RONCOLATO

#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>	// per uppercase
#include <chrono>		// per le pause dopo l'interazione dell'utente
#include <thread>

#include "Log.h"
#include "Player.h"
#include "DefenceGrid.h"
#include "AttackGrid.h"
#include "Battleship.h"
#include "Submarine.h"
#include "Support.h"

// definita nel costruttore di Match per migliore efficienza, riconosce il comando relativo ad una posizione valida
static std::regex reg_position;

class Match
{
private:
public:
	Match(Player& p1, Player& p2, Log& file);
	Log& file_log;
	Player& player1;
	Player& player2;
	
	// discerne l'utente umano/robotico
	void ship_placement(Player& p);
	
	static constexpr int MAX_ROUNDS = 4000;	// boh a caso raga
	void play();
	
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

//
// --- HELPER FUNCTIONS ---

// interagisce con l'utente per ottenere un comando (speciale o non) con un formato valido
int command(game_board::Position& a, game_board::Position& b);
int random_command(Player& player, game_board::Position& origin, game_board::Position& target);
// usata solo durante il gioco, non nell'inserimento, esegue qualsiasi comando (speciale o non) passato
// se l'azione non è valida non viene eseguita e l'errore viene segnalato con exit codes
int execute(Player& player, Player& enemy, int code, const game_board::Position& origin, const game_board::Position& target);
// interagisce con l'utente per fargli inserire tutte le navi
void user_placement(Player& p, Log& file_log);
// inserisce automaticamente le navi
void bot_placement(Player& p, Log& file_log);
game_board::Position random_position();
// funzione ausiliaria che ritorna la posizione distante dim da start in direzione direction
game_board::Position ortogonal_position(const game_board::Position& start, int dim, int direction);
// stampa il messaggio relativo al comando inserito
void print_code(int code, const game_board::Position& origin, const game_board::Position& target);
// stampa una tabella delle navi non ancora affondate
void recap(const Player& player1, const Player& player2);
// serve per l'inserimento umano
std::vector<std::string> split(std::string str, char delimiter);
//esegue il replay dell'ultima partita giocata
void re_play(std::ifstream& input);
//
//void perchè non serve che ritorni codici di usciti, visto che saranno tutti validi
//void command_for_replay(game_board::Position& a, game_board::Position& b, std::ifstream& input);
//
//void replay_placement(Player& p, std::ifstream& input);
#endif // MATCH_H
