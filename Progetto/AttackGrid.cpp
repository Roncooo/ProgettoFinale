//	author: BEATRICE BELLESSO 

#include "AttackGrid.h"

AttackGrid::AttackGrid()
{
}

void AttackGrid::set_shot(const Position& pos)
{
	set_char(pos, hit);
}

void AttackGrid::set_missed(const Position& pos)
{
	set_char(pos, water);
}

void AttackGrid::update()
{
/*	temporaneamente commentato perché dobbiamo prima capire/decidere come passare la griglia del nemico
 * (se lo facciamo), e per il momento non compila
 * Inoltre così è sbagliato perché vediamo "in diretta" le navi nemiche ma se si spostano non dovremmo
 * essere in grado di vedere le nuove posizioni ma solo quelle vecchie che abbiamo colpito o visualizzato con il sonar

	reset_matrix();
	DefenceGrid enemy;
	for(int i = 0; i < DefenceGrid::SHIP_NUMBER; i++)
	{
		for(int j = 0; j < enemy.ships[i]->armor.size(); j++)
			if(enemy.ships[i]->armor[j] == false)		// se all'indice j armor = 0
				set_char(enemy.ships[i]->pos[j], AttackGrid::hit);		// in quella "posizione" setto X
			// poi ^^^ questo non è quello che fa set_shot?
	}
*/
	
//	reset_matrix();
	
	
}

void AttackGrid::reset_sonar()
{
	for(int r=0; r<rows; r++)
	{
		for(int c=0; c<cols; c++)
		{
			Position pos(r,c);
			if( get_char(pos) == sonar_undamaged ||
				get_char(pos) == sonar_damaged		)
				set_char(pos,empty_char);
		}
	}
}