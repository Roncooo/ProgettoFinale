//	author: BEATRICE BELLESSO

#ifndef DefenceGrid_H
#define DefenceGrid_H

#include <memory>
#include "Grid.h"
class Ship;	// forward declaration

class DefenceGrid : public Grid
{
public:
	DefenceGrid();
	void update() override;
	static constexpr int SHIP_NUMBER = 8;
	int currently_placed_ships = 0;	// deve essere aggiornata ogni volta che si costruisce una nuova nave
											// e si potrebbe anche controllare che non superi mai SHIP_NUMBER
//	Ship* ships[SHIP_NUMBER];	// array di puntatori a navi generiche
								// non posso fare un array di navi perché ci sarebbe slicing
								// ATTENZIONE: le navi vengono allocate dinamicamente, è necessario il distruttore
	std::unique_ptr<Ship> ships[SHIP_NUMBER];	// occhio, questo DOVREBBE risolvere i memory leak ma impedisce 
												// la copia (di qualsiasi cosa dato che è tutto intrecciato)
												// e richiede la modifica della creazione delle navi
	bool is_valid(const Position& prow, const Position& prune) const;
	~DefenceGrid();
};

#include "Ship.h"

#endif // DefenceGrid_H
