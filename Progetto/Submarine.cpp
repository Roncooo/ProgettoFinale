// author: BEATRICE BELLESSO 

#include "Submarine.h"

using game_board::Position;
using game_board::AttackGrid;

Submarine::Submarine(const Position& pos, Player& p) 
	: Ship(pos, pos, p, 'E', 'e')
{
	// intentionally left blank
}

std::string Submarine::ship_type() const
{
	return "submarine";
}

int Submarine::action(const Position& pos, Player& enemy)
{
	// muovo dove chiede l'utente, se questo è possibile
	// altrimenti termina
	if(move(pos)==-1)
		return -3;		// non è possibile spostare il sottomarino
	
	player.attack.reset_sonar();
	
	// ciclo sulle 25 posizioni attorno al sottomarino
	for(int r=-2; r<=2; r++)
	{
		for(int c=-2; c<=2; c++)
		{
			// se la posizione è fuori dalla matrice, vado avanti con la posizione successiva
			if(!game_board::Grid::is_valid(pos+Position(r,c)))
				continue;
			// chiedo al nemico se nella posizione c'è una nave
			int code = enemy.is_there_ship(pos+Position(r,c));
			if(code == -1) continue; // non c'è nessuna nave nella casella in esame
			else if(code == 1)
				player.attack.set_char(pos+Position(r,c), AttackGrid::sonar_damaged);
			else if(code == 2)
				player.attack.set_char(pos+Position(r,c), AttackGrid::sonar_undamaged);
		}
	}
	
	return 32;	//tutto è andato a buon fine
}

int Submarine::is_sunk()
{
	if(Ship::is_sunk() == 1)	// la nave è affondata (necessariamente ora)
		return 42;
	
	return 0;	// non è affondata
}

