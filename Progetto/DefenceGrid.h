//	author: BEATRICE BELLESSO

#ifndef DefenceGrid_H
#define DefenceGrid_H

#include <memory>
#include <vector>
#include "Grid.h"

class Ship;	// forward declaration

class DefenceGrid : public game_board::Grid
{
public:
	static constexpr int SHIP_NUMBER = 8;
	// deve essere aggiornata ogni volta che si costruisce una nuova nave, 
	// per questo non deve per forza essere privata(?)
	// occhio, questo DOVREBBE risolvere i memory leak ma impedisce 
	// la copia (di qualsiasi cosa dato che è tutto intrecciato)
	// e richiede la modifica della creazione delle navi
	// essendo un array di dimensione fissa, non posso aggiungere navi, di conseguenza
	// puo' rimanere pubblico(?)
	std::vector<std::unique_ptr<Ship>> ships;
	int get_placed_ships() const;
	DefenceGrid();
	void update() override;
//	Ship* ships[SHIP_NUMBER];	// array di puntatori a navi generiche
								// non posso fare un array di navi perché ci sarebbe slicing
								// ATTENZIONE: le navi vengono allocate dinamicamente, è necessario il distruttore

	~DefenceGrid();
};

#include "Ship.h"

#endif // DefenceGrid_H
