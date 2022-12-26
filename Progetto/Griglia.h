// autore: 

#ifndef GRIGLIA_H
#define GRIGLIA_H

#include <iostream>
#include "Posizione.h"

class Griglia
{
public:
	Griglia();
//	~Griglia();
	// interne così accedono tranquillamente a matrix
	// statiche così passiamo gli argomenti tra parentesi
	static void print(const Griglia& a);	// stampa una sola griglia
	static void print(const Griglia& a, const Griglia& b);	// stampa due griglie affiancate
	virtual void update()=0;	// virtuale pura perché avviene diversamente per la difesa e l'attacco
	
	virtual bool is_valid(const Posizione& pos) const;
	
private:
	static constexpr int cols {12};
	static constexpr int rows {12};
	// Se una cella non ha niente, contiene il carattere vuoto cioè '\0' e non spazio ' '
	char matrix[rows][cols];
	char letters[rows] = {'A','B','C','D','E','F','G','H','I','L','M','N'};
};


#endif // GRIGLIA_H
