// author: FRANCESCO RONCOLATO

#include "Player.h"

using game_board::Position;
using game_board::Grid;

Player::Player(std::string n)
	: name{n}
{
	// attack e defence inizializzate di default
	std::string temp_name = name;
	std::transform(name.begin(), name.end(), temp_name.begin(), ::toupper);
	if(temp_name.substr(0,3) == "CPU")	
	{
		is_cpu = true;
		auto_placement = true;
	}
	else
		is_cpu = false;
}

Ship& Player::get_ship(int index)
{
	return *(defence.ships[index]);
}

void Player::restore_ship(int index)
{
	defence.ships[index]->restore_armor();
}

int Player::how_many_battleships() const
{
	int count=0;
	for(int i=0; i<defence.SHIP_NUMBER; i++)
	{
		if(defence.ships[i]->is_sunk()==false && defence.ships[i]->ship_type()=="battleship")
			count++;
	}
	return count++;
}

int Player::how_many_supports() const
{
	int count=0;
	for(int i=0; i<defence.SHIP_NUMBER; i++)
	{
		if(defence.ships[i]->is_sunk()==false && defence.ships[i]->ship_type()=="support")
			count++;
	}
	return count++;
}

int Player::how_many_submarines() const
{
	int count=0;
	for(int i=0; i<defence.SHIP_NUMBER; i++)
	{
		if(defence.ships[i]->is_sunk()==false && defence.ships[i]->ship_type()=="submarine")
			count++;
	}
	return count++;
}

bool Player::operator==(const Player& p) const
{
	return p.name==this->name;
}

bool Player::receive_shot(const Position& shot_position)
{
	for(int ship_index=0; ship_index<DefenceGrid::SHIP_NUMBER; ship_index++)
	{
		for(int pos_index=0; pos_index<defence.ships[ship_index]->get_dimension(); pos_index++)
		{
			if(defence.ships[ship_index]->pos[pos_index] == shot_position)
			{
				// segno che è stato colpito il pezzo
				defence.ships[ship_index]->armor[pos_index] = false;
				// controllo se sono rimaste armature (e in caso affonda)
				// aggiorna lo stato di affondamento ed eventualmente lo dice
				defence.ships[ship_index]->is_sunk();
				// dico al nemico che ha colpito
				return true;
			}
		}
	}
	// dico al nemico che non ha colpito
	return false;
}


int Player::is_there_ship(const Position& sonar_request) const
{
	for(int ship_index=0; ship_index<DefenceGrid::SHIP_NUMBER; ship_index++)
	{
		// se la nave è affondata completamente, non verrà vista dal sonar
		if(defence.ships[ship_index]->is_sunk())
			continue;
		
		for(int pos_index=0; pos_index<defence.ships[ship_index]->get_dimension(); pos_index++)
		{
			if(defence.ships[ship_index]->pos[pos_index] == sonar_request)
			{
				if(defence.ships[ship_index]->armor[pos_index] == true)
					return 2;	// se l'armatura della nave risulta intatta ritorno un codice valido 2
				else
					return 1;	// pezzo di nave colpito
			}
		}
	}
	return -1;	// nella posizione richiesta non c'è una nave
}

Player::~Player()
{
}

void Player::print_defence()
{
	Grid::print(defence);
}

void Player::print_defence_attack()
{
	Grid::print(defence, attack);
}

//void Player::add_ship(Battleship& to_add)
//{
//	defence.ships[defence.currently_placed_ships++] = std::make_unique<Battleship>(&to_add);
//}
//
//void Player::add_ship(Support& to_add)
//{
//	defence.ships[defence.currently_placed_ships++] = std::make_unique<Support>(&to_add);
//}
//
//void Player::add_ship(Sumbarine& to_add)
//{
//	defence.ships[defence.currently_placed_ships++] = std::make_unique<Sumbarine>(&to_add);
//}

int Player::act_ship(int index, const Position& target, Player& enemy)
{
	if(index==-1)	// get_ship_index non ha trovato il centro della nave
		return -4;
	return defence.ships[index]->action(target, enemy);
}

bool Player::has_lost()
{
	// per ciascuna nave nemica, se è una Corazzata e non è affondata, p non ha ancora vinto
	for(int i=0; i<DefenceGrid::SHIP_NUMBER; i++)
	{
		if(!defence.ships[i]->is_sunk())
			return false;
	}
	return true;
}

int Player::get_ship_index(const Position& pos) const
{
	for(int i=0; i<DefenceGrid::SHIP_NUMBER; i++)
	{
		Position ship_center = defence.ships[i]->get_center();
		// come da consegna, una nave si individua dalla sua posizione centrale
		// si potrebbe individuare una nave da una sua qualsiasi posizione modificando questa if
		if(pos==ship_center)
			return i;
	}
	return -1;
}


bool Player::is_valid(const Position& prow, const Position& prune) const
{
	// controllo <0 e >12
	if(!Grid::is_valid(prune) || !Grid::is_valid(prow))
		return false;
		
	Position ordered_prow;		// è la Position più vicina all'origine
	Position ordered_prune;
	if(prow.abs()<prune.abs())
	{
		ordered_prow = prow;
		ordered_prune = prune;
	}
	else
	{
		ordered_prow = prune;
		ordered_prune = prow;
	}
	
	// la nave deve essere orizzontale o verticale
	if(ordered_prow.get_row() != ordered_prune.get_row() && ordered_prow.get_col() != ordered_prune.get_col())
		return false;
	
	// controllo che non ci siano già navi NON AFFONDATE nelle posizioni tra prua e poppa (comprese)
	Position vec = (ordered_prune-ordered_prow).norm();
			// se funziona tutto non dovrebbe essere un ciclo infinito
			// "ma diciamocelo, il rischio c'è"
	for(Position current=ordered_prow; current!=ordered_prune+vec; current+=vec)		// per ogni posizione tra prua e poppa
	{
		for(int s=0; s<defence.currently_placed_ships; s++)				// per ogni nave nella griglia
		{
			// se la nave è affondata non crea problemi e ci si può passare sopra quindi passo alla prossima nave
			if(defence.ships[s]->is_sunk())
				continue;
			
			// per ogni posizione della nave
			for(int p=0; p<defence.ships[s]->get_dimension(); p++)
			{
				// se la posizione che voglio controllare appartiene ad una nave
				if(defence.ships[s]->pos[p] == current)
					return false;
			}
		}
	}
	return true;
	
	// questa versione controlla attraverso la matrice che quindi dovrebbe essere sempre aggiornata ma non lo è
//	for(int i=0; i<(ordered_prow-ordered_prune).abs(); i++)
//	{
//		if(ordered_prow.row == ordered_prune.row)	// se sono in riga
//		{
//			if(get_char(ordered_prune+(i,0)) != ' ')	// scorro verso destra
//				return false;
//		}
//		
//		if(ordered_prow.col == ordered_prune.col)	// se sono in colonna
//		{
//			if(get_char(ordered_prune+(0,i)) != ' ')	// scorro verso il basso
//				return false;
//		}
//	}
}

