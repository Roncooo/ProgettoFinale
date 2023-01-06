//	author: BEATRICE BELLESSO

#ifndef DefenceGrid_H
#define DefenceGrid_H

#include <memory>
#include "Grid.h"

class Ship;	// forward declaration

class DefenceGrid : public Grid
{
public:
	static constexpr int SHIP_NUMBER = 8;
	// deve essere aggiornata ogni volta che si costruisce una nuova nave, 
	// per questo non deve per forza essere privata(?)
	int currently_placed_ships = 0;
	// occhio, questo DOVREBBE risolvere i memory leak ma impedisce 
	// la copia (di qualsiasi cosa dato che è tutto intrecciato)
	// e richiede la modifica della creazione delle navi
	// essendo un array di dimensione fissa, non posso aggiungere navi, di conseguenza
	// puo' rimanere pubblico(?)
	std::unique_ptr<Ship> ships[SHIP_NUMBER];
	
	DefenceGrid();
	void update() override;
//	Ship* ships[SHIP_NUMBER];	// array di puntatori a navi generiche
								// non posso fare un array di navi perché ci sarebbe slicing
								// ATTENZIONE: le navi vengono allocate dinamicamente, è necessario il distruttore
	bool is_valid(const Position& prow, const Position& prune) const;
	~DefenceGrid();
};

#include "Ship.h"

#endif // DefenceGrid_H