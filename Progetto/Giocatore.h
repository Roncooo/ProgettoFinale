// autore: 

#ifndef GIOCATORE_H
#define GIOCATORE_H

#include "GrigliaAttacco.h"
#include "GrigliaDifesa.h"

class Giocatore
{
public:
	Giocatore(std::string n = "Player");
	
	GrigliaAttacco attack;
	GrigliaDifesa defence;
	std::string name;
	
	~Giocatore();
};

#endif // GIOCATORE_H
