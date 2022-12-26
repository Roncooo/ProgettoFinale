// autore: 

#ifndef NAVE_H
#define NAVE_H

#include <vector>
#include "Posizione.h"

class Nave
{
public:
	Nave(const Posizione& prua, const Posizione& poppa);
	bool sunk = false;
	int dimension;
	Posizione center;
	std::vector<Posizione> pos;		// sono vector e non array perché a priori (compilazione) non conosco la loro 
									// dimensione (e una nave generica non ha dimensione specifica)
									// si potrebbe aggirare rendendo Nave una classe template ma è solo un casino credo
	std::vector<bool> armor;		// corazza, memorizza quali pezzi della nave sono stati colpiti
	
	void move(const Posizione& new_pos);
	int corazza() const;
	
	virtual ~Nave()=0;	// stratagemma per rendere Nave virtuale pura
};

#endif // NAVE_H
