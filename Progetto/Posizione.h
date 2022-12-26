// autore: 

#ifndef POSIZIONE_H
#define POSIZIONE_H

class Posizione
{
public:
	Posizione(int r=-1, int c=-1) : row{r}, col{c} {};
	int row;
	int col;
	void operator= (const Posizione& a);
	bool operator==(const Posizione& a);
	void operator+=(const Posizione& a);
	void operator-=(const Posizione& a);
};

Posizione operator-(const Posizione& a, const Posizione& b);
Posizione operator+(const Posizione& a, const Posizione& b);

#endif // POSIZIONE_H
