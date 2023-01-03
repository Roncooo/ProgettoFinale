// autore: clTabCtrl

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
	static void print(Grid& a);	// stampa una sola Grid
	static void print(Grid& a, Grid& b);	// stampa due griglie affiancate
	virtual void update()=0;	// virtuale pura perché avviene diversamente per la difesa e l'attacco
	void reset_matrix();
	
	static bool is_valid(const Position& pos);
	
	char get_char(const Position& pos) const;
	void set_char(const Position& pos, char c);		// non const
	
	static constexpr int cols {12};
	static constexpr int rows {12};
	static constexpr char letters[rows] = {'A','B','C','D','E','F','G','H','I','L','M','N'};
private:
	char matrix[rows][cols];
};


#endif // Grid_H
