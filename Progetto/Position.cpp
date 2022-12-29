// autore: 

#include "Position.h"

Position::Position(std::string s)
{
	// non dovrebbe mai essere chiamata
	if(s.length()<2 || s.length()>3)
		throw std::invalid_argument("Invalid length for Position(std::string)");
	
	// è orribile ma per il momento funziona, si può certamente migliorare
	switch(s[0])
	{
		case 'A':	row = 1;	break;
		case 'B':	row = 2;	break;
		case 'C':	row = 3;	break;
		case 'D':	row = 4;	break;
		case 'E':	row = 5;	break;
		case 'F':	row = 6;	break;
		case 'G':	row = 7;	break;
		case 'H':	row = 8;	break;
		case 'I':	row = 9;	break;
		case 'L':	row = 10;	break;
		case 'M':	row = 11;	break;
		case 'N':	row = 12;	break;
		default:
			throw std::invalid_argument("Invalid char for Position(std::string)");
	}
	
	// Non faccio ulteriori controlli perché in teoria sono già fatti dalla regex
	col = std::stoi(s.substr(1));
	
}

bool Position::operator!=(const Position& pos) const
{
	return this->row != pos.row || this->col != pos.col;
}

bool Position::operator==(const Position& pos) const
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

// attenzione che (A1-A5).abs() ritorna 4 e non 5
// è un errore?
double Position::abs() const
{
	return std::sqrt(std::pow(row,2)+std::pow(col,2));
}