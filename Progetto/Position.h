// autore: 

#ifndef Position_H
#define Position_H

class Position
{
public:
	Position(int r=-1, int c=-1) : row{r}, col{c} {};
	int row;
	int col;
	void operator= (const Position& a);
	bool operator==(const Position& a);
	void operator+=(const Position& a);
	void operator-=(const Position& a);
};

Position operator-(const Position& a, const Position& b);
Position operator+(const Position& a, const Position& b);

#endif // Position_H
