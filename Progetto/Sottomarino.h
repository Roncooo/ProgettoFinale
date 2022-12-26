// autore: 

#ifndef SOTTOMARINO_H
#define SOTTOMARINO_H

#include "Nave.h"

class Sottomarino : public Nave
{
public:
	void search(const Posizione& pos);		// non è const perché muove e poi cerca
};

#endif // SOTTOMARINO_H
