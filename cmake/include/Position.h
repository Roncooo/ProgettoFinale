// author: FRANCESCO RONCOLATO

#ifndef Position_H
#define Position_H

#include <cmath>
#include <string>
#include <stdexcept>

namespace game_board
{
	class Position
	{
	public:
		Position(int r=-1, int c=-1) : row{r}, col{c} {};
		explicit Position(std::string s);
	
		void operator= (const Position& a);
		bool operator==(const Position& a) const;
		bool operator!=(const Position& a) const;
		void operator+=(const Position& a);
		void operator-=(const Position& a);
		double abs() const;
		Position norm() const;
		int get_row() const;
		int get_col() const;
		std::string toString();
	
	private:
		int row;
		int col;
	};

	std::ostream& operator<<(std::ostream& os, const Position& a);
	Position operator-(const Position& a, const Position& b);
	Position operator+(const Position& a, const Position& b);
}

#endif // Position_H
