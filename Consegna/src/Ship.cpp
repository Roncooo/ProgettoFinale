//	author: BEATRICE BELLESSO

#include "Ship.h"

using namespace game_board;

Ship::Ship(const Position& prow, const Position& prune, Player& p, char upper, char lower) 
	: player{p}, not_hit{upper}, hit{lower}
{	
	if(!p.is_valid(prow, prune))
		throw std::invalid_argument("Posizioni non valide");
		
	// si ordinano prua e poppa in modo che la prua ordinata sia più vicina all'origine
	Position ordered_prow;
	Position ordered_prune;
	if(prow.abs() < prune.abs())
	{
		ordered_prow = prow;
		ordered_prune = prune;
	}
	else
	{
		ordered_prow = prune;
		ordered_prune = prow;
	}
	
	dimension = (prune-prow).abs() +1;
	
	pos = std::vector<Position>(dimension);
	armor = std::vector<bool>(dimension);
	
	// la corazza è inizialmente integra
	for(int i = 0; i < dimension; i++)
		armor[i] = true;
	
	// inserisco nel vettore di pos le posizioni della nave
	for(int i = 0; i < dimension; i++)
	{
		if(ordered_prow.get_row() == ordered_prune.get_row())
			pos[i] = (ordered_prow + Position(0, i));		
		else // altrimenti hanno per forza colonna uguale
			pos[i] = (ordered_prow + Position(i, 0));
	}
}

int Ship::get_dimension() const
{ 
	return dimension; 
}

int Ship::get_armor() const
{
	int c = 0;
	for(int i=0; i<dimension; i++)
	{
		if(armor[i] == true)
			c++;
	}
	return c;
}

Position Ship::get_center() const
{
	// funziona perché usiamo solo dimensioni dispari
	return pos[dimension/2];
}

int Ship::move(const Position& new_center)
{
	// copio le posizioni in un vector temporaneo
	std::vector<Position> temp = pos;
	Position dislocation = new_center - get_center();
	// rendo invalide le posizioni attuali della nave così non intralciano is_valid
	for(int i=0; i<dimension; i++)
		pos[i] = Position();
	
	// se le posizioni che sarebbero occupate dalla nuova posizione della nave
	// non sono completamente dentro alla griglia o sormontano altre navi
	if(!player.is_valid(temp[0]+dislocation,temp[dimension-1]+dislocation))
	{
		// ripristino le posizioni salvate
		pos = temp;
		return -1;	// non è possibile spostare la nave nella nuova posizione
	}
	
	// se è possibile fare lo spostamento, riscrivo le posizioni giuste in pos
	for(int i=0; i<dimension; i++)
		pos[i] = temp[i] + dislocation;
	
	return 2;	//tutto è andato a buon fine
}

// aggiusta l'armatura di una nave non affondata (chiamato da Support::cure)
void Ship::restore_armor()
{
	for(int i=0; i<dimension; i++)
		armor[i] = true;
}

// ritorna 0 se la nave non è affondata
// ritorna 1 se la nave è affondata ora
// una nave affondata è completamente rimossa quindi non ci sono navi precedentemente affondate
int Ship::is_sunk()
{
	if(get_armor()>0)	//se almeno un armatura è intatta, la nave non è affondata
		return 0;		// funge da false
	
	return 1;
}
