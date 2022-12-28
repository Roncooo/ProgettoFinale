// autore: 

#include "Position.h"

bool Position::operator!=(const Position& pos)
{
	return this->row != pos.row || this->col != pos.col;
}

bool Position::operator==(const Position& pos)
{
	return this->row == pos.row && this->col == pos.col;
}

void Position::operator=(const Position& pos)
{
	this->row = pos.row;
	this->col = pos.col;
}

void Position::operator+=(const Position& pos)
{
	this->row += pos.row;
	this->col += pos.col;
}

void Position::operator-=(const Position& pos)
{
	this->row -= pos.row;
	this->col -= pos.col;
}

Position operator-(const Position& a, const Position& b)
{
	return Position(a.row-b.row, a.col-b.col);
}

Position operator+(const Position& a, const Position& b)
{
	return Position(a.row+b.row, a.col+b.col);
}

double Position::abs() const
{
	return std::sqrt(std::pow(row,2)+std::pow(col,2));
}