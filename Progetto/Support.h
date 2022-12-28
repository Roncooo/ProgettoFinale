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
	void cure(const Position& pos);		// non è const perché muove e poi cura
	~Support() override;
};
#endif // Support_H
