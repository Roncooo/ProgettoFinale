// autore: 

#include "Nave.h"

Nave::Nave(const Posizione& prua, const Posizione& poppa)
{
	// MANCANO CONTROLLI DI VALIDITA' DELLA POSIZIONE CON LE ALTRE NAVI
	
//	if(griglia.is_valid(poppa) && griglia.is_valid(prua))
	
}

void Nave::move(const Posizione& new_center)
{
	Posizione dislocation = new_center - center;
	for(int i=0; i<dimension; i++)
		pos[i] += dislocation;
	// manca controllo sulla nuova posizione
}

int Nave::corazza() const
{
	int corazza = 0;
	for(int i=0; i<dimension; i++)
	{
		if(armor[i] == true)
			corazza++;
	}
	return corazza;
}