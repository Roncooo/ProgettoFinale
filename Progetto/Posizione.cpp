// autore: 

#include "Posizione.h"

void Posizione::update(int r, int c) 
{ 
	row = r; 
	col = c; 
}


Posizione operator-(const Posizione& a, const Posizione& b)
{
	return Posizione(a.row-b.row, a.col-b.col);
}

Posizione operator+(const Posizione& a, const Posizione& b)
{
	return Posizione(a.row+b.row, a.col+b.col);
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