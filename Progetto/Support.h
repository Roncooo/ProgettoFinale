// autore: 

#ifndef Support_H
#define Support_H

#include "Ship.h"
#include "DefenceGrid.h"

class Support : public Ship
{
	bool is_curable(const Position& p);
public:
	Support(const Position& prow, const Position& stern, DefenceGrid& grid); 
	//	int dimension = 3;
	char hit = 's';
	char not_hit = 'S';
	
	// cure riceve la posizione dove andare e curare
	void cure(const Position& pos);		// non è const perché muove e poi cura
	~Support() override;
};
#endif // Support_H
