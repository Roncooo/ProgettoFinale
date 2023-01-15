//	author: BEATRICE BELLESSO

#include "Ship.h"

using game_board::Position;

Ship::Ship(const Position& prow, const Position& prune, Player& p, char upper, char lower) 
	: player{p}, not_hit{upper}, hit{lower}
{	
	if(!p.is_valid(prow, prune))
		throw std::invalid_argument("Posizioni non valide");
		
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
	
	for(int i = 0; i < dimension; i++)
		armor[i] = true;
	
	for(int i = 0; i < dimension; i++)
	{
		if(ordered_prow.get_row() == ordered_prune.get_row())
			pos[i] = (ordered_prow + Position(0, i));		
		else	// altrimenti hanno per forza colonna uguale
			pos[i] = (ordered_prow + Position(i, 0));
	}
}

//Ship::~Ship(){}

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
	
	// controlla sia che la nave sia completamente dentro alla griglia, sia che non sormonti altre navi
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

void Ship::restore_armor()
{
	if(sunk) return;
	
	for(int i=0; i<dimension; i++)
		armor[i] = true;
}

int Ship::is_sunk()
{
	// se so già che è affondata non devo calcolare niente
	if(sunk == true)
		return 1;	// funge da true
	
	for (int i = 0; i < armor.size(); i++){
		if (armor[i] == true)	//se almeno un armatura è intatta, la nave non è affondata
			return 0;	// funge da false
	}
	
	// se arrivo qui, tutte le armature == false
	// e la nave è affondata ora
	sunk = true;
	return 2;	// indica che la nave è affondata ora 
	
}

// commentata intanto, secondo me può essere direttamente cancellata
/*void Ship::sinking()
{
	std::cout << " ++ LA TUA NAVE E' AFFONDATA ++\n";
	player.defence.currently_placed_ships--;
	
	Position temp = Position();
	for (int i = 0; i < pos.size(); i++) 
	{	
		player.defence.set_char(pos[i], ' ');
		pos[i] = temp;
	}
*/