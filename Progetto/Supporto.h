// autore: 

#ifndef SUPPORTO_H
#define SUPPORTO_H

#include "Nave.h"

class Supporto : public Nave
{
public:
	void cure(const Posizione& pos);		// non è const perché muove e poi cura
};

#endif // SUPPORTO_H
