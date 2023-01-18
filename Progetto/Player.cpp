//	author: FRANCESCO RONCOLATO

#include "Player.h"

using game_board::Position;
using game_board::Grid;

Player::Player(std::string n)
	: name{n}
{
	// intentionally left blank
}

Ship& Player::get_ship(int index)
{
	return *(defence.ships[index]);
}

void Player::add_ship(Ship* to_add)
{
	defence.ships.push_back(std::unique_ptr<Ship>(to_add));
}

void Player::restore_ship(int index)
{
	defence.ships[index]->restore_armor();
}

int Player::how_many_battleships() const
{
	int count=0;
	for(int i=0; i<get_placed_ships(); i++)
	{
		// non serve più il controllo defence.ships[i]->is_sunk()==false perché ships contiene solo navi non affondate
		if(defence.ships[i]->ship_type()=="battleship")
			count++;
	}
	return count;
}

int Player::how_many_supports() const
{
	int count=0;
	for(int i=0; i<get_placed_ships(); i++)
	{
		if(defence.ships[i]->is_sunk()==false && defence.ships[i]->ship_type()=="support")
			count++;
	}
	return count;
}

int Player::how_many_submarines() const
{
	int count=0;
	for(int i=0; i<get_placed_ships(); i++)
	{
		if(defence.ships[i]->is_sunk()==false && defence.ships[i]->ship_type()=="submarine")
			count++;
	}
	return count;
}

bool Player::operator==(const Player& p) const
{
	return p.name==this->name;
}

int Player::receive_shot(const Position& shot_position)
{
	// per ogni nave ancora a galla
	for(int ship_index=0; ship_index<defence.get_placed_ships(); ship_index++)
	{
		// per ogni posizione della nave
		for(int pos_index=0; pos_index<defence.ships[ship_index]->get_dimension(); pos_index++)
		{
			// se non è il pezzo giusto passo al prossimo
			if(defence.ships[ship_index]->pos[pos_index] != shot_position)
				continue;
			
			// segno che è stato colpito il pezzo
			defence.ships[ship_index]->armor[pos_index] = false;
			
			// 0 se non affondata, 40 41 42 per identificare i tipi di nave affondati (necessariamente ora)
			int code = defence.ships[ship_index]->is_sunk();
			
			if(code==0)		// nave non affondata
				return 31;	// colpita nave generica (non diamo informazioni sul tipo di nave colpito)
			else			// nave affondata
			{
				// la nave viene fisicamente rimossa dal vector
				defence.ships.erase(defence.ships.begin()+ship_index);
				return code;	// segnalo che tipo di nave è affondata
			}
		}
	}
	return 30; 		// non colpito
}


int Player::is_there_ship(const Position& sonar_request) const
{
	// per ogni nave a galla
	for(int ship_index=0; ship_index<get_placed_ships(); ship_index++)
	{
		// per ogni posizione della nave
		for(int pos_index=0; pos_index<defence.ships[ship_index]->get_dimension(); pos_index++)
		{
			// se la posizione richiesta dal sonar coincide con il pezzo di nave
			if(defence.ships[ship_index]->pos[pos_index] == sonar_request)
			{
				if(defence.ships[ship_index]->armor[pos_index] == true)
					return 2;	// pezzo di armatura intatta
				else
					return 1;	// pezzo di nave colpito
			}
		}
	}
	return -1;	// nella posizione richiesta non c'è una nave
}

void Player::print_defence()
{
	Grid::print(defence);
}

void Player::print_defence_attack()
{
	Grid::print(defence, attack);
}

int Player::act_ship(int index, const Position& target, Player& enemy)
{
	if(index==-1)	// get_ship_index non ha trovato il centro della nave
		return -4;
	
	return defence.ships[index]->action(target, enemy);		// viene eseguita l'azione e ritornato il codice
}

bool Player::has_lost() const
{
	// get_placed_ships ritorna il numero di navi non affondate
	return get_placed_ships()==0;
}

int Player::get_ship_index(const Position& pos) const
{
	for(int i=0; i<get_placed_ships(); i++)
	{
		Position ship_center = defence.ships[i]->get_center();
		// come da consegna, una nave si individua dalla sua posizione centrale
		// si potrebbe individuare una nave da una sua qualsiasi posizione modificando questa if
		if(pos==ship_center)
			return i;
	}
	return -1;	// pos non è il centro di una nave
}

int Player::get_placed_ships() const
{
	return defence.get_placed_ships();
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
	
	// controllo che non ci siano già navi non affondate nelle posizioni tra prua e poppa (comprese)
	Position vec = (ordered_prune-ordered_prow).norm();
	// per ogni posizione tra prua e poppa
	for(Position current=ordered_prow; current!=ordered_prune+vec; current+=vec)
	{
		// per ogni nave nella griglia
		for(int s=0; s<defence.get_placed_ships(); s++)
		{
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
}

