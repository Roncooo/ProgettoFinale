// autore: 

#ifndef Position_H
#define Position_H

#include <cmath>
#include <string>
#include <stdexcept>

class Position
{
public:
	Position(int r=-1, int c=-1) : row{r}, col{c} {};
	Position(std::string s);
	int row;
	int col;
	void operator= (const Position& a);
	bool operator==(const Position& a) const;
	bool operator!=(const Position& a) const;
	void operator+=(const Position& a);
	void operator-=(const Position& a);
	double abs() const;
};

Position operator-(const Position& a, const Position& b);
Position operator+(const Position& a, const Position& b);

#endif // Position_H
