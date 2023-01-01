// autore: 

#include "Match.h"

using std::cout, std::cin, std::string;

int main(void)
{
//	DefenceGrid difesa;
//	AttackGrid attacco;
//	Grid::print(attacco, difesa);
	cout <<
" | _ ) __ _| |_| |_ __ _ __ _| (_)__ _    _ _  __ ___ ____ _| |___ \n"<<
" | _ \\/ _` |  _|  _/ _` / _` | | / _` |  | ' \\/ _` \ V / _` | / -_)\n"<<
" |___/\\__,_|\\__|\\__\\__,_\\__, |_|_\\__,_|  |_||_\\__,_|\\_/\\__,_|_\\___|\n"<<
"                        |___/                                      \n";

	cout << "Inserire i nomi dei giocatori";
//	cout << ", per far giocare il computer dare il nome CPU...";
	cout << "\nPer visualizzare la tua griglia, inserisci il comando XX XX";
	cout << "\nNome giocatore 1: ";
	string player1_name;
	cin >> player1_name;
	Player player1(player1_name);
	cout << "Nome giocatore 2: ";
	string player2_name;
	cin >> player2_name;
	Player player2(player2_name);
	
	// pulisce residui nell'input
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	Match partita(player1, player2);
	partita.ship_placement(player1);
	partita.ship_placement(player2);
	return 0;
}
