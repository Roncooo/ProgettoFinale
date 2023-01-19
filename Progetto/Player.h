//	autore: FRANCESCO RONCOLATO

#ifndef Player_H
#define Player_H

#include <ctime>
#include <cstdlib>		// per la randomicità del giocatore computer
#include <algorithm>	// per uppercase
#include "AttackGrid.h"
#include "DefenceGrid.h"
#include "Battleship.h"
#include "Submarine.h"
#include "Support.h"

class Player
{
public:
	Player(std::string n = "Player");
	std::string name;
	bool is_cpu = false;
	bool auto_placement = false;
	bool operator==(const Player& p) const;
	int receive_shot(const game_board::Position& pos);
	int is_there_ship(const game_board::Position& pos) const;
	
	Ship& get_ship(int index);
	void restore_ship(int index);
	void add_ship(Ship* to_add);
	
	game_board::AttackGrid attack;
	
	void print_defence();	// non const perché le griglie sono aggiornate prima di essere stampate
	void print_defence_attack();
	int act_ship(int index, const game_board::Position& target, Player& enemy);
	bool has_lost() const;
	int get_ship_index(const game_board::Position& pos) const;
	int get_placed_ships() const;
	bool is_valid(const game_board::Position& prow, const game_board::Position& prune) const;
	std::string grids_to_string();
	
	int how_many_battleships() const;
	int how_many_supports() const;
	int how_many_submarines() const;
private:
	game_board::DefenceGrid defence;
};


#endif // Player_H
