// author: FRANCESCO RONCOLATO

#include "Match.h"

using std::cout, std::cin, std::string;

void standard_match()
{
	std::srand(123456);

	Log file_log = Log();

	cout << "Inserire i nomi dei giocatori";
	cout << "\nPer visualizzare la tua griglia di difesa, inserisci il comando XX";
	
	cout << "\nNome giocatore 1: ";
	string player1_name;
	std::getline(std::cin, player1_name);
	
	cout << "Nome giocatore 2: ";
	string player2_name;
	std::getline(std::cin, player2_name);
	
	while(player2_name == player1_name)
	{
		cout << "Per favore inserisci un nome diverso da " + player1_name + "\n"; 
		std::getline(std::cin, player2_name);
		if(player2_name != player1_name)
			cout << "\"" + player2_name + "\" va bene, grazie\n";
	}
	
	Player player1(player1_name);
	Player player2(player2_name);
	file_log.write(player1_name + " " +player2_name);
	file_log.write("\n");
	
	if(!player1.is_cpu)
	{
		cout << player1_name << " vuoi che siano inserite automaticamente le tue navi? (Y/N)";
		std::string auto_placement;
		std::getline(std::cin, auto_placement);
		if(auto_placement=="Y")
			player1.auto_placement = true;
	}
	if(!player2.is_cpu)
	{
		cout << player2_name << " vuoi che siano inserite automaticamente le tue navi? (Y/N)";
		std::string auto_placement;
		std::getline(std::cin, auto_placement);
		if(auto_placement=="Y")
			player2.auto_placement = true;
	}
	
	
	Match partita(player1, player2, file_log);
	partita.ship_placement(player1);
	partita.ship_placement(player2);
	partita.play();
}

void cpu_vs_cpu(int n)
{
	std::srand(std::time(NULL));
	for(int i=0; i<n; i++)
	{
		Player player1("cpu1");
		Player player2("cpu2");	
		Log file_log = Log();
		Match partita(player1, player2, file_log);
		partita.ship_placement(player1);
		partita.ship_placement(player2);
		partita.play();
	}
}

int main(void)
{
//	cpu_vs_cpu(100);
	standard_match();
	return 0;
}
