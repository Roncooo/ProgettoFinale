//	autore: FRANCESCO RONCOLATO

#include "Grid.h"

using namespace game_board;

Grid::Grid()
{
	reset_matrix();
}

void Grid::reset_matrix()
{
	for(int r=0; r<rows; r++)
	{
		for(int c=0; c<cols; c++)
			matrix[r][c] = empty_char;
	}
}

bool Grid::is_valid(const Position& pos)
{
	return !(pos.get_row()<0 || pos.get_col()<0 || pos.get_row()>=rows || pos.get_col()>=cols);
}

char Grid::get_char(const Position& pos) const
{
	return matrix[pos.get_row()][pos.get_col()];
}

void Grid::set_char(const Position& pos, char c)		// non const
{
	matrix[pos.get_row()][pos.get_col()] = c;
}

void Grid::print(Grid& a)
{
	// formato in uso:
	//  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12|
	//  +---+---+---+---+---+---+---+---+---+---+---+---+
	//A |   | S | S | S |   |   |   |   |   |   |   |   | 
	//  +---+---+---+---+---+---+---+---+---+---+---+---+
	//B |   |   |   |   |   | C | C | C | C | C |   |   | 
	//  +---+---+---+---+---+---+---+---+---+---+---+---+
	//C |   |   |   |   |   |   |   |   |   |   |   |   | 
	//  +---+---+---+---+---+---+---+---+---+---+---+---+
	//D |   | C |   |   |   | S | S | S |   |   |   |   | 
	//  +---+---+---+---+---+---+---+---+---+---+---+---+
	//E |   | C |   |   |   |   |   |   |   |   |   |   | 
	//  +---+---+---+---+---+---+---+---+---+---+---+---+
	//F |   | C |   |   |   |   |   |   |   |   |   |   | 
	//  +---+---+---+---+---+---+---+---+---+---+---+---+
	//G |   | C |   |   |   |   |   |   |   |   | E |   | 
	//  +---+---+---+---+---+---+---+---+---+---+---+---+
	//H |   | C |   |   |   |   |   |   |   |   |   |   | 
	//  +---+---+---+---+---+---+---+---+---+---+---+---+
	//I |   |   |   |   |   | S | S | S |   |   |   |   | 
	//  +---+---+---+---+---+---+---+---+---+---+---+---+
	//L |   | E |   |   |   |   |   |   |   |   |   |   | 
	//  +---+---+---+---+---+---+---+---+---+---+---+---+
	//M |   |   |   |   |   |   |   |   |   |   |   |   | 
	//  +---+---+---+---+---+---+---+---+---+---+---+---+
	//N |   |   |   |   |   |   |   |   |   |   |   |   | 
	//  +---+---+---+---+---+---+---+---+---+---+---+---+

	std::cout << to_string(a);
}


// stampa due griglie affiancate
void Grid::print(Grid& a, Grid& b)
{
	std::cout << to_string(a, b);
}

std::string Grid::to_string(Grid& a)
{
	std::string grid_string = "";		//necessaria per il replay
	a.update();
	
	std::string delimiter_line = "  +";
	for(int i=0; i<cols; i++)
		delimiter_line += "---+";
	
	// riga di numeri
	grid_string += "  ";	// identazione per le lettere
	
	for(int i=1; i<=cols; i++)
	{
		grid_string += "| "+std::to_string(i);
		if(i<10)
			grid_string += " ";	// padding a destra
	}
	grid_string += "|\n";	// ultimo delimitatore
	
	grid_string += delimiter_line + "\n";
	
	// inizio matrice
	for(int r=0; r<rows; r++)
	{
		grid_string += letters[r];
		grid_string += " |";
		
		for(int c=0; c<cols; c++)
		{
			grid_string += " ";
			grid_string += a.matrix[r][c];
			grid_string += " |";
		}
		
		grid_string += "\n" + delimiter_line + "\n";
	}
	return grid_string;
}


std::string Grid::to_string(Grid& a, Grid& b)
{
	std::string grid_string = "";		//necessaria per il replay
	std::string margin = "\t";

	a.update();
	b.update();
	
	std::string delimiter_line = "  +";
	for(int i=0; i<cols; i++)
		delimiter_line += "---+";
	
	grid_string += "  ";	//indentazione per le lettere
	
	//riga dei numeri a
	for(int i=1; i<=cols; i++)
	{
		grid_string += "| "+std::to_string(i);
		if(i<10)
			grid_string += " ";	// padding a destra
	}
	grid_string += "|";	// ultimo delimitatore
	
	grid_string += margin;
	
	//riga dei numeri b
	grid_string += "  ";	//indentazione per le lettere
	for(int i=1; i<=cols; i++)
	{
		grid_string += "| "+std::to_string(i);
		if(i<10)
			grid_string += " ";	// padding a destra
	}
	grid_string += "|\n";	// ultimo delimitatore
	
	
	grid_string += delimiter_line + margin + delimiter_line + "\n";
	
	// inizio matrice
	for(int r=0; r<rows; r++)
	{
		//riga matrice a
		grid_string += letters[r];
		grid_string += " |";
		for(int c=0; c<cols; c++)
		{
			grid_string += " ";
			grid_string += a.matrix[r][c];
			grid_string += " |";
		}
		
		grid_string += margin;
		
		//riga matrice b
		grid_string += letters[r];
		grid_string += " |";
		for(int c=0; c<cols; c++)
		{
			grid_string += " ";
			grid_string += b.matrix[r][c];
			grid_string += " |";
		}
		
		grid_string += "\n" + delimiter_line + margin + delimiter_line + "\n";
	}
	return grid_string;
}
