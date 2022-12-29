// autore: 

#ifndef Ship_H
#define Ship_H

#include <vector>
#include "Position.h"
#include "DefenceGrid.h"

class Ship
{
public:
	Ship(const Position& prow, const Position& stern, DefenceGrid& grid);
	bool sunk = false;
	int dimension;
	Position center;
	std::vector<Position> pos;		// sono vector e non array perché a priori (compilazione) non conosco la loro 
									// dimensione (e una Ship generica non ha dimensione specifica)
									// si potrebbe aggirare rendendo Ship una classe template ma è solo un casino credo
	std::vector<bool> armor;		// corazza, memorizza quali pezzi della Ship sono stati colpiti
									// armor[i] è true se il pezzo di corazza è integro (non colpito)
	char hit;
	char not_hit;
	void move(const Position& new_pos);
	int get_armor() const;
	DefenceGrid& my_grid;
	void restore_armor();	// aggiusta l'armatura di una nave non affondata (chiamato da Support::cure)
	
	virtual ~Ship()=0;	// stratagemma per rendere Ship virtuale pura
};

#endif // Ship_H
