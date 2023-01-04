//	author: BEATRICE BELLESSO

#ifndef Ship_H
#define Ship_H

#include <vector>
#include "Position.h"
#include "DefenceGrid.h"

//#include "Player.h"			 occhio a possibili circular dipendencies
class Player;	// forward declaration



class Ship
{
public:
	
	// throws std::invalid_argument se la griglia non è valida
	Ship(const Position& prow, const Position& stern, Player& p, char upper, char lower);
	Ship(Player& p, char upper, char lower):player{p}, hit{lower}, not_hit {upper}{};
	Player& player;
	// sono vector e non array perché a priori (compilazione) non conosco la loro 
	// dimensione (e una Ship generica non ha dimensione specifica)
	// si potrebbe aggirare rendendo Ship una classe template ma è solo un casino credo
	std::vector<Position> pos;
	// corazza, memorizza quali pezzi della Ship sono stati colpiti: pubblica perché su
	// receive_shot vado a modificarne lo status
	// corazza(armor[i]) integra = true;
	// corazza(armor[i]) colpita = false;
	std::vector<bool> armor;
	char hit;
	char not_hit;
	
	int get_armor() const;
	int get_dimension() const;
	Position get_center() const;
	
	int move(const Position& new_pos);
	void sinking();
	void restore_armor();	// aggiusta l'armatura di una nave non affondata (chiamato da Support::cure)
	bool is_sunk();
	
	bool is_battleship() const;
	bool is_support() const;
	bool is_submarine() const;
	
	virtual ~Ship()=0;	// stratagemma per rendere Ship virtuale pura
private:
	bool sunk = false;
	int dimension;
};

#include "Player.h"

#endif // Ship_H
