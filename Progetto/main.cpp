// autore: 

#include "Match.h"

using std::cout, std::cin, std::string;

int main(void)
{
//	DefenceGrid difesa;
//	AttackGrid attacco;
//	Grid::print(attacco, difesa);

	// da quello che ho capito su stackOverflow, è meglio mettere nel main lo srand
	// così l'eseguibile è anche riproducibile settando lo stesso seed (non con time NULL)
	std::srand(123456);
	//  al posto di 123456 std::time(NULL)

	cout << "Inserire i nomi dei giocatori";
//	cout << ", per far giocare il computer dare il nome CPU...";
	cout << "\nPer visualizzare la tua griglia di difesa, inserisci il comando XX";
	cout << "\nNome giocatore 1: ";
	string player1_name;
	std::getline(std::cin, player1_name);
	Player player1(player1_name);
	cout << "Nome giocatore 2: ";
	string player2_name;
	std::getline(std::cin, player2_name);
	Player player2(player2_name);
	// pulisce residui nell'input
//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	Match partita(player1, player2);
	partita.ship_placement(player1);
	partita.ship_placement(player2);
	return 0;
}
