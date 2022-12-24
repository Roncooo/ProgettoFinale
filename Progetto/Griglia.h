#ifndef GRIGLIA_H
#define GRIGLIA_H

#include <iostream>

class Griglia
{
public:
	Griglia();
	~Griglia();
	// interne così accedono tranquillamente a matrix
	// statiche così passiamo gli argomenti tra parentesi
	// la prima versione stampa una sola griglia
	// l'altra ne stampa due affiancate
	static void print(const Griglia& a);
	static void print(const Griglia& a, const Griglia& b);
private:
	static constexpr int cols {12};
	static constexpr int rows {12};
	// Se una cella non ha niente, contiene il carattere vuoto cioè '\0' e non spazio ' '
	char matrix[rows][cols];
	char letters[rows] = {'A','B','C','D','E','F','G','H','I','L','M','N'};
};


#endif // GRIGLIA_H
