// autore: 

#ifndef CORAZZATA_H
#define CORAZZATA_H

#include "Nave.h"

class Corazzata : public Nave
{
public:
	void move() = delete;
	void shoot(const Posizione& pos) const;
};

#endif // CORAZZATA_H
