//	author: FRANCESCO RONCOLATO 

#include "Position.h"

using namespace game_board;

Position::Position(std::string s)
{
	// non dovrebbe mai essere chiamata
	if(s.length()<2 || s.length()>3)
		throw std::invalid_argument("Invalid length for Position(std::string)");
	
	// è orribile ma per il momento funziona, si può certamente migliorare
	switch(s[0])
	{
		case 'A':	row = 0;	break;
		case 'B':	row = 1;	break;
		case 'C':	row = 2;	break;
		case 'D':	row = 3;	break;
		case 'E':	row = 4;	break;
		case 'F':	row = 5;	break;
		case 'G':	row = 6;	break;
		case 'H':	row = 7;	break;
		case 'I':	row = 8;	break;
		case 'L':	row = 9;	break;
		case 'M':	row = 10;	break;
		case 'N':	row = 11;	break;
		default:
			throw std::invalid_argument("Invalid char for Position(std::string)");
	}
	
	// Non faccio ulteriori controlli perché in teoria sono già fatti dalla regex
	col = std::stoi(s.substr(1)) -1;
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

std::ostream& operator<<(std::ostream& os, const Position& a)
{
	std::string letter;
	switch(a.get_row())
	{
		case 0:		letter = "A";	break;
		case 1:		letter = "B";	break;
		case 2:		letter = "C";	break;
		case 3:		letter = "D";	break;
		case 4:		letter = "E";	break;
		case 5:		letter = "F";	break;
		case 6:		letter = "G";	break;
		case 7:		letter = "H";	break;
		case 8:		letter = "I";	break;
		case 9:		letter = "L";	break;
		case 10:	letter = "M";	break;
		case 11:	letter = "N";	break;
	}
	os << letter << std::to_string(a.get_col()+1);
	return os;
}

Position operator-(const Position& a, const Position& b)
{
	return Position(a.get_row()-b.get_row(), a.get_col()-b.get_col());
}

Position operator+(const Position& a, const Position& b)
{
	return Position(a.get_row()+b.get_row(), a.get_col()+b.get_col());
}

// attenzione che (A1-A5).abs() ritorna 4 e non 5
// è un errore?
double Position::abs() const
{
	return std::sqrt(std::pow(row,2)+std::pow(col,2));
}

// DA CONTROLLARE SE I CONTI SONO GIUSTI O BISOGNA FARE +1 O ALTRI ARROTONDAMENTI
Position Position::norm() const
{
	return Position(row/abs(), col/abs());
}

int Position::get_row() const { return row; }

int Position::get_col() const { return col; }

std::string Position::toString()
{
	std::string letter;
	switch(this->row)
	{
		case 0:		letter = "A";	break;
		case 1:		letter = "B";	break;
		case 2:		letter = "C";	break;
		case 3:		letter = "D";	break;
		case 4:		letter = "E";	break;
		case 5:		letter = "F";	break;
		case 6:		letter = "G";	break;
		case 7:		letter = "H";	break;
		case 8:		letter = "I";	break;
		case 9:		letter = "L";	break;
		case 10:	letter = "M";	break;
		case 11:	letter = "N";	break;
	}
	letter += std::to_string(this->col+1);
	return letter;
}

