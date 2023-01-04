//	author: BEATRICE BELLESSO

#ifndef Support_H
#define Support_H

#include "Ship.h"
#include "DefenceGrid.h"

class Support : public Ship
{
	bool is_curable(const Position& p);
public:
	Support(const Position& prow, const Position& stern, Player& p); 
	//	int dimension = 3;
	// cure riceve la posizione dove andare e curare
	int cure(const Position& pos);		// non è const perché muove e poi cura
	~Support() override;
};
#endif // Support_H
