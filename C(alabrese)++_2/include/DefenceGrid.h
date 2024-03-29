//	author: BEATRICE BELLESSO

#ifndef DefenceGrid_H
#define DefenceGrid_H

#include <memory>
#include <vector>
#include "Grid.h"

class Ship;	// forward declaration

namespace game_board
{
	class DefenceGrid : public game_board::Grid
	{
	public:
	
		std::vector<std::unique_ptr<Ship>> ships;
	
		DefenceGrid();
		int get_placed_ships() const;
		void update() override;
	
		~DefenceGrid();
	};
}

#include "Ship.h"

#endif // DefenceGrid_H
