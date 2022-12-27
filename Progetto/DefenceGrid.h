// autore: 

#ifndef DefenceGrid_H
#define DefenceGrid_H

#include "Grid.h"
class Ship;	// forward declaration

class DefenceGrid : public Grid
{
	static constexpr int SHIP_NUMBER = 8;
public:
	DefenceGrid();
	void update() override;
	Ship* ships[SHIP_NUMBER];	// array di puntatori a navi generiche
								// non posso fare un array di navi perché ci sarebbe slicing
	bool is_valid(const Position& prow, const Position& prune) const;
};

#endif // DefenceGrid_H
