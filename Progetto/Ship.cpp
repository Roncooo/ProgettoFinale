// autore: 

#include "Ship.h"

Ship::Ship(const Position& prow, const Position& prune, DefenceGrid& grid) 
	: my_grid{grid}
{	
	if(!grid.is_valid(prow, prune))
		throw std::invalid_argument("Posizioni non valide");	// non dovrebbe essere lanciata dato che facciamo
																// il controllo nella funzione di inserimento
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
	if(ordered_prow.row == ordered_prune.row)
	{
		dimension = (ordered_prune.col - ordered_prow.col)+1;
		//già qui, in entrambi i blocchi, dovremmo controllare che la dimensione non sia maggiore di 5? (perchè minore di 1 è not possible)
		
		pos = std::vector<Position>(dimension);
		for(int i = 0; i < dimension; i++)
			pos[i] = (ordered_prow + Position(0, i));		
		/*Position*/ center = ordered_prow + Position(0, (dimension/2));
		//qui ↑ senza Position
	}
	else	// altrimenti hanno per forza colonna uguale
	{
		dimension = (ordered_prune.row - ordered_prow.row)+1;
		pos = std::vector<Position>(dimension);
		for(int i = 0; i < dimension; i++)
			pos[i] = (ordered_prow + Position(i, 0));
		/*Position*/ center = ordered_prow + Position((dimension/2), 0);
	}
	
	armor = std::vector<bool>(dimension);
	for(int i = 0; i < dimension; i++)
		armor[i] = true;
	
	//	my_grid = grid; // deve essere inizializzata con un'init list altrimenti essendo
	//	una reference il compilatore si incazza	
}

Ship::~Ship(){}

void Ship::move(const Position& new_center)
{
	Position dislocation = new_center - center;
	for(int i=0; i<dimension; i++)
		pos[i] += dislocation;
	// manca controllo sulla nuova Position
	
	// è necessaria una funzione che abbia come parametro la griglia di difesa dell'avversario, tipo quella commentata qui sotto
	// p.s. non so nemmeno se compila, è solo un'idea
	
	
}

//bool Ship::control(DefenceGrid& enemy){
//	for(int i=0; i<dimension; i++){
//		if (pos[i] == enemy.ship[i]->pos[i])
//			return false
//	}
//	return true;
//}

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

void Ship::restore_armor()
{
	if(sunk) return;
	
	for(int i=0; i<dimension; i++)
		armor[i] = true;
}