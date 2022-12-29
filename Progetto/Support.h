// autore: 

#ifndef Support_H
#define Support_H

#include "Ship.h"
#include "DefenceGrid.h"

class Support : public Ship
{
	bool check_pos(const Position& p);
public:
	Support(const Position& prow, const Position& stern, DefenceGrid& grid); // il controllo lo fara' is_valid di DefenceGrid
	// cure riceve la posizione dove andare e una nave da analizzare
	void cure(const Position& pos, Ship& s);		// non è const perché muove e poi cura
	~Support() override;
};
#endif // Support_H
