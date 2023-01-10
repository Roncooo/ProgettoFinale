// author: FRANCESCO RONCOLATO


#ifndef Grid_H
#define Grid_H

#include <iostream>
#include "Position.h"
namespace game_board
{
	class Grid
	{
	public:
		//	essendo statiche e costanti quest'ultime possono essere anche pubbliche
		static constexpr int cols {12};
		static constexpr int rows {12};
		static constexpr char letters[rows] = {'A','B','C','D','E','F','G','H','I','L','M','N'};
		static constexpr char empty_char = ' ';
	
		Grid();
		//	~Grid();
	
		//	statiche così passiamo gli argomenti tra parentesi
		//	non const perché i print fanno l'update
		static void print(Grid& a);				//	stampa una sola Grid
		static void print(Grid& a, Grid& b);	//	stampa due griglie affiancate
		static bool is_valid(const Position& pos);
	
		//	virtuale pura perché avviene diversamente per la difesa e l'attacco
		virtual void update()=0;
		void reset_matrix();
	
		char get_char(const Position& pos) const;
		void set_char(const Position& pos, char c);		//	non const
	private:
		char matrix[rows][cols];
	};
}

#endif // Grid_H
