// autore: 

#include "Posizione.h"

bool Posizione::operator==(const Posizione& pos)
{
	return this->row == pos.row && this->col == pos.col;
}

void Posizione::operator=(const Posizione& pos)
{
	this->row = pos.row;
	this->col = pos.col;
}

void Posizione::operator+=(const Posizione& pos)
{
	this->row += pos.row;
	this->col += pos.col;
}

void Posizione::operator-=(const Posizione& pos)
{
	this->row -= pos.row;
	this->col -= pos.col;
}

Posizione operator-(const Posizione& a, const Posizione& b)
{
	return Posizione(a.row-b.row, a.col-b.col);
}

Posizione operator+(const Posizione& a, const Posizione& b)
{
	return Posizione(a.row+b.row, a.col+b.col);
}
