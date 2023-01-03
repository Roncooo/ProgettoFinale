// autore: 

#ifndef Ship_H
#define Ship_H

#include <vector>
#include "Position.h"
#include "DefenceGrid.h"
//#include "Player.h"			 occhio a possibili circular dipendencies
class Player;	// forward declaration

//using std::invalid_argument;	// bruttooo (e credo anche sbagliato perché negli header non si devono mai usare gli using)

class Ship
{
public:
	// throws std::invalid_argument se la griglia non è valida
		// ^^ no
	Ship(const Position& prow, const Position& stern, Player& p);
	Ship(Player& p):player{p}{};
	Player& player;
	bool sunk = false;
	int dimension;
	std::vector<Position> pos;		// sono vector e non array perché a priori (compilazione) non conosco la loro 
									// dimensione (e una Ship generica non ha dimensione specifica)
									// si potrebbe aggirare rendendo Ship una classe template ma è solo un casino credo
	std::vector<bool> armor;		// corazza, memorizza quali pezzi della Ship sono stati colpiti
									// armor[i] è true se il pezzo di corazza è integro (non colpito)
	char hit;
	char not_hit;
	int move(const Position& new_pos);
	int get_armor() const;
	void restore_armor();	// aggiusta l'armatura di una nave non affondata (chiamato da Support::cure)
	bool is_sunk();
//	bool control(DefenceGrid& enemy);
	
	// tre funzioni comode ma che denotano un errore di design secondo me
	bool is_battleship();
	bool is_support();
	bool is_submarine();
	
	virtual ~Ship()=0;	// stratagemma per rendere Ship virtuale pura
};

#include "Player.h"

#endif // Ship_H
