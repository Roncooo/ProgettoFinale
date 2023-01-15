// autore: FRANCESCO RONCOLATO

#ifndef Player_H
#define Player_H

#include <ctime>
#include <cstdlib>	// per la randomicità del giocatore computer
#include <algorithm>	// per uppercase
#include "AttackGrid.h"
#include "DefenceGrid.h"
//class Ship;	// fwd declararion
#include "Battleship.h"
#include "Submarine.h"
#include "Support.h"

class Player
{
public:
	Player(std::string n = "Player");
	// si può mettere una variabile statica per dare nomi di default Player1 Player2
	const std::string name;
	bool is_cpu;
	bool auto_placement = false;
	bool operator==(const Player& p) const;
//	Player& operator=(const Player& p);
	bool receive_shot(const game_board::Position& pos);
	int is_there_ship(const game_board::Position& pos) const;
	
	// per la privatizzazione di defence
	Ship& get_ship(int index);
	void restore_ship(int index);
	void add_ship(Ship* to_add);
//	void add_ship(Battleship& to_add);
//	void add_ship(Support& to_add);
//	void add_ship(Sumbarine& to_add);
	
	~Player();
	AttackGrid attack;
	// per il momento sono solo idee di risoluzioni per poter mettere almeno defence grid privata
	// resta un problema l'inserimento delle navi che non può funzionare con get_ship
//	Ship* get_ship(int index); 
	void print_defence();	// non const perché le griglie sono aggiornate prima di essere stampate
	void print_defence_attack();
	int act_ship(int index, const game_board::Position& target, Player& enemy);
	bool has_lost();	// può essere resa const se non deve più usare is_sunk quindi per esempio se usiamo il vector
						// oppure se siamo sicuri che bool sunk sia sempre correttamente aggiornato
	int get_ship_index(const game_board::Position& pos) const;
	bool is_valid(const game_board::Position& prow, const game_board::Position& prune) const;
	// si poteva fare anche un unica funzione che ritorna un vector lungo 3 magari ma vabb nsomma
	int how_many_battleships() const;
	int how_many_supports() const;
	int how_many_submarines() const;
private:
	DefenceGrid defence;
	
};


#endif // Player_H
