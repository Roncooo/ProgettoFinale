// autore: FRANCESCO RONCOLATO

#ifndef Player_H
#define Player_H

#include <ctime>
#include <cstdlib>	// per la randomicità del giocatore computer
#include <algorithm>	// per uppercase
#include "AttackGrid.h"
#include "DefenceGrid.h"
//#include "Battleship.h"
//#include "Submarine.h"
//#include "Support.h"

class Player
{
public:
	Player(std::string n = "Player");
	// si può mettere una variabile statica per dare nomi di default Player1 Player2
	const std::string name;
	bool is_cpu;
	bool auto_placement = false;
	bool operator==(const Player& p) const;
	bool receive_shot(const Position& pos);
	int is_there_ship(const Position& pos) const;
	~Player();
	AttackGrid attack;
	DefenceGrid defence;
	// per il momento sono solo idee di risoluzioni per poter mettere almeno defence grid privata
	// resta un problema l'inserimento delle navi che non può funzionare con get_ship
	Ship* get_ship(int index); 
	void print_defence() const;
	void print_defence_attack() const;
private:
};

#endif // Player_H
