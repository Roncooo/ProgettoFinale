// autore: 

#ifndef Grid_H
#define Grid_H

#include <iostream>
#include "Position.h"

class Grid
{
public:
	Grid();
//	~Grid();
	// interne così accedono tranquillamente a matrix
	// statiche così passiamo gli argomenti tra parentesi
	static void print(const Grid& a);	// stampa una sola Grid
	static void print(const Grid& a, const Grid& b);	// stampa due griglie affiancate
	virtual void update()=0;	// virtuale pura perché avviene diversamente per la difesa e l'attacco
	void reset_matrix();
	
	bool is_valid(const Position& pos) const;
	
	char get_char(const Position& pos) const;
	void set_char(const Position& pos, char c);		// non const
	
private:
	static constexpr int cols {12};
	static constexpr int rows {12};
	char matrix[rows][cols];
	char letters[rows] = {'A','B','C','D','E','F','G','H','I','L','M','N'};
};


#endif // Grid_H
