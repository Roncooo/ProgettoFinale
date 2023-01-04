// autore: 

#include "Submarine.h"

bool Submarine::sub_area(Position& p)
{
	if(	this->pos[0].row - p.row <= 2 && this->pos[0].row - p.row >= -2 &&
		this->pos[0].col - p.col <= 2 && this->pos[0].col - p.col >= -2 	) 
			return true;
	return false;
}

Submarine::Submarine(const Position& pos, Player& p) 
	: Ship(pos, pos, p, 'E', 'e')
{
}

int Submarine::search(const Position& pos, const Player& enemy)
{
	// muovo dove chiede l'utente, se questo è possibile
	// altrimenti termina
	if(move(pos)==-1)
		return -1;
	
	player.attack.reset_sonar();
	
	// ciclo sulle 25 posizioni attorno al sottomarino
	for(int r=-2; r<=2; r++)
	{
		for(int c=-1; c<=2; c++)
		{
			// se la posizione è fuori dalla matrice, vado avanti con la posizione successiva
			if(!Grid::is_valid(pos+Position(r,c)))
				continue;
			// chiedo al nemico se nella posizione c'è una nave
			if(enemy.is_there_ship(pos+Position(r,c)))
				player.attack.set_char(pos+Position(r,c), AttackGrid::sonar);
		}
	}
	
	// ^^^ soluzione senza accedere direttamente alle navi nemiche, in questo caso è abbastanza meno efficiente
	// della versione (↓↓↓) che accede però secondo me è comunque meglio così
	
//	//	for per le navi
//	for(int i = 0; i < DefenceGrid::SHIP_NUMBER; i++)
//	{
//		for(int j = 0; j < enemy.defence.ships[i]->dimension; j++)
//		{
//			if(!sub_area(enemy.defence.ships[i]->pos[j])) continue;
//			else
//				player.attack.set_char(enemy.defence.ships[i]->pos[j], AttackGrid::sonar);
//		}
//	}
	return 2;	//tutto è andato a buon fine
}
Submarine::~Submarine(){}