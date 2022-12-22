#ifndef GRIGLIA_H
#define GRIGLIA_H

#include <iostream>

class Griglia
{
public:
	Griglia();
	~Griglia();
	void print() const;
private:
	static constexpr int cols {12};
	static constexpr int rows {12};
	char matrix[rows][cols];
	char letters[rows] = {'A','B','C','D','E','F','G','H','I','L','M','N'};
};


#endif // GRIGLIA_H
