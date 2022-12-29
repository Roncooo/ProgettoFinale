// autore: 

#ifndef DefenceGrid_H
#define DefenceGrid_H

#include "Grid.h"
class Ship;	// forward declaration

class DefenceGrid : public Grid
{
public:
	DefenceGrid();
	void update() override;
	static constexpr int SHIP_NUMBER = 8;
	Ship* ships[SHIP_NUMBER];	// array di puntatori a navi generiche
								// non posso fare un array di navi perché ci sarebbe slicing
								// ATTENZIONE: le navi vengono allocate dinamicamente, è necessario il distruttore
	bool is_valid(const Position& prow, const Position& prune) const;
	~DefenceGrid();
};

#include "Ship.h"

#endif // DefenceGrid_H
