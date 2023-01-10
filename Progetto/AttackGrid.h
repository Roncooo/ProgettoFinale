//	author: BEATRICE BELLESSO

#ifndef AttackGrid_H
#define AttackGrid_H

#include "Grid.h"


class Ship;	//forward declaration

class AttackGrid : public game_board::Grid
{
public:
	// variabili costanti statiche che descrivono la classe
	static constexpr char hit = 'X';
	static constexpr char water = 'O';
	static constexpr char sonar_undamaged = 'Y';
	static constexpr char sonar_damaged = 'y';
	
	AttackGrid();
	void set_shot(const game_board::Position& pos);
	void set_missed(const game_board::Position& pos);
	void update() override;
	void reset_sonar();
};

#include "Ship.h"

#endif // AttackGrid_H
