// author: FRANCESCO RONCOLATO

#include "Match.h"

using std::cout, std::cin, std::string;

void standard_match()
{
	std::srand(std::time(NULL));

	Log file_log = Log();

	cout << "Come si gioca?\n";
	cout << "Per prima cosa si posizionano 3 navi corazzate, 3 navi di supporto e 2 sottomarini (anche automaticamente)\n";
	cout << "Per compiere l'azione di una nave dovrai indicare la sua cella centrale e dove vuoi compiere l'azione\n";
	cout << "Per i giocatori umani sono disponibili anche i seguenti comandi speciali\n";
	cout << " - XX\t\t per vedere la griglia di difesa\n";
	cout << " - XX XX\t per vedere la griglia di difesa e quella di attacco affiancate\n";
	cout << " - AA AA\t per cancellare gli avvistamenti sonar\n";
	cout << " - BB BB\t per cancellare tutta la griglia di attacco\n";
	cout << " - CC CC\t per imbrogliare\n";
	cout << " - TT TT\t per visualizzare la tabella di resoconto attuale\n";
	cout << "Buon divertimento\n\n";

	cout << "Inserire i nomi dei giocatori\n";
	
	cout << "Nome giocatore 1: ";
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
	
	std::string input_str;
	if(!player1.is_cpu)
	{
		while(input_str != "Y" && input_str != "N")
		{
			cout << player1_name << " vuoi che siano inserite automaticamente le tue navi? (Y/N) ";
			std::getline(std::cin, input_str);
			std::transform(input_str.begin(), input_str.end(), input_str.begin(), ::toupper);
			if(input_str=="Y")
				player1.auto_placement = true;
		}
		input_str = "";
	}
	
	if(!player2.is_cpu)
	{	
		while(input_str != "Y" && input_str != "N")
		{
			cout << player2_name << " vuoi che siano inserite automaticamente le tue navi? (Y/N) ";
			std::getline(std::cin, input_str);
			std::transform(input_str.begin(), input_str.end(), input_str.begin(), ::toupper);
			if(input_str=="Y")
				player2.auto_placement = true;
		}
		input_str = "";
	}
	
	Match partita(player1, player2, file_log);
	partita.play();
//	std::string azioni = file_log.getActions();
//	cout << "\nLe mosse effettuate sono state:\n" + azioni;
	file_log.close();
}

void cpu_vs_cpu(int n)
{
	std::srand(std::time(NULL));
	for(int i=0; i<n; i++)
	{
		Player player1("cpu1");
		Player player2("cpu2");
		Log file_log = Log();
		
//		file_log.add(player1.name + " " + player2.name + "\n");
		Match partita(player1, player2, file_log);
//		partita.ship_placement(player1);
//		partita.ship_placement(player2);
		partita.play();
		std::string azioni = file_log.getActions();
		cout << "\nLe mosse effettuate sono state:\n" + azioni;
		file_log.close();
	}
}

int main(void)
{
//	cpu_vs_cpu(1);
	standard_match();
	return 0;
}
