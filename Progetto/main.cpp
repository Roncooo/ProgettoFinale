//	author: FRANCESCO RONCOLATO

#include "Match.h"
#include <cstring>

using std::cout, std::cin, std::endl, std::string;

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
	cout << "Buon divertimento\n" << endl;
	
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	
	cout << "Inserire i nomi dei giocatori" << endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	
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
			cout << "\"" + player2_name + "\" va bene, grazie" << endl;
	}
	
	Player player1(player1_name);
	Player player2(player2_name);
	
	std::string input_str;
	
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	
	while(input_str != "Y" && input_str != "N")
	{
		cout << player1_name << " vuoi che sia il computer a giocare al posto tuo? (Y/N) ";
		std::getline(std::cin, input_str);
		std::transform(input_str.begin(), input_str.end(), input_str.begin(), ::toupper);
		if(input_str=="Y")
		{
			player1.is_cpu = true;
			player1.auto_placement = true;
		}
	}
	input_str = "";
	
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
		
		player2.is_cpu = true;
		player2.auto_placement = true;
		cout << "Almeno un giocatore deve essere computerizzato. " + player2_name + ", il computer giochera' al posto tuo" << endl;
	}
	else
	{
		while(input_str != "Y" && input_str != "N")
		{
			cout << player2_name << " vuoi che sia il computer a giocare al posto tuo? (Y/N) ";
			std::getline(std::cin, input_str);
			std::transform(input_str.begin(), input_str.end(), input_str.begin(), ::toupper);
			if(input_str=="Y")
			{
				player2.is_cpu = true;
				player2.auto_placement = true;
			}
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
	
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	
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
		
		//setto le impostazioni CPU
		player1.is_cpu = true;
		player1.auto_placement = true;
		
		player2.is_cpu = true;
		player2.auto_placement = true;
		
		Match partita(player1, player2, file_log);
		partita.play();
//		std::string azioni = file_log.getActions();
//		cout << "\nLe mosse effettuate sono state:\n" + azioni;
		file_log.close();
	}
}

int main(int argc, char* argv[])
{
	// argc vale 2 se c'è un argomento (perché argv[0] contiene nome e percorso dell'eseguibile)
	// se c'è un solo argomento ed è lungo 2, lo trasformo in uppercase e lo confronto con i comandi
	std::string match_type;
	
	if(argc==1)
		match_type = "UNASSIGNED";
	if(argc>2)
		match_type = "TOO_MANY_ARGS";
	if(argc==2)
	{
		// trasformo in uppercase un carattere alla volta
		for(int i=0; i<strlen(argv[1]); i++)
			argv[1][i] = toupper(argv[1][i]);
		if(strcmp(argv[1], "CC")==0)
			match_type = "CC";
		else if(strcmp(argv[1], "PC")==0)
			match_type = "PC";
		else
			match_type = "INVALID";
	}
	
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	
	
	cout << "BENVENUT* NELLA BATTAGLIA NAVALE\n" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout << "Come si gioca?" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	cout << "Per prima cosa si posizionano 3 navi corazzate, 3 navi di supporto e 2 sottomarini (anche automaticamente)" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	cout << "Per compiere l'azione di una nave dovrai indicare la sua cella centrale e dove vuoi compiere l'azione" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	cout << "Per i giocatori umani sono disponibili anche i seguenti comandi speciali" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	cout << " - XX\t\t per vedere la griglia di difesa" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	cout << " - XX XX\t per vedere la griglia di difesa e quella di attacco affiancate" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	cout << " - AA AA\t per cancellare gli avvistamenti sonar" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	cout << " - BB BB\t per cancellare tutta la griglia di attacco" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	cout << " - CC CC\t per imbrogliare" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	cout << " - TT TT\t per visualizzare la tabella di resoconto attuale" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	cout << "Buon divertimento\n" << endl;
	
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	
	
	std::srand(std::time(NULL));
	Log file_log = Log();
	
	Player player1;
	Player player2;
	
	if(match_type == "CC")
	{
		cout << "E' stata selezionata da riga di comando la modalita' computer vs computer\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		
		player1.name = "CPU1";
		player2.name = "CPU2";
		player1.is_cpu = true;
		player1.auto_placement = true;
		player2.is_cpu = true;
		player2.auto_placement = true;
	}
	if(match_type == "PC")
	{
		cout << "E' stata selezionata da riga di comando la modalita' umano vs computer\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		
		cout << "Umano, qual e' il tuo nome?" << endl;
		string player1_name;
		std::getline(std::cin, player1_name);
		player1.name = player1_name;
		player2.name = "CPU";
		player2.is_cpu = true;
		player2.auto_placement = true;
		
		std::string input_str;
		
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		
		while(input_str != "Y" && input_str != "N")
		{
			cout << player1_name << " vuoi che siano inserite automaticamente le tue navi? (Y/N) ";
			std::getline(std::cin, input_str);
			std::transform(input_str.begin(), input_str.end(), input_str.begin(), ::toupper);
			if(input_str=="Y")
				player1.auto_placement = true;
		}
	}
	// se non è stato inserito un comando valido
	else
	{
		if(match_type=="UNASSIGNED")
			cout << "Non e' stato inserito nulla nella riga di comando" << endl;
		if(match_type=="TOO_MANY_ARGS")
			cout << "Sono stati inseriti troppi elementi nella riga di comando" << endl;
		if(match_type=="INVALID")
			cout << "Il comando inserito da riga di comando non e' valido" << endl;
		
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		
		player2.name = "CPU";
		player2.is_cpu = true;
		player2.auto_placement = true;
		
		cout << "Giocatore 1, qual e' il tuo nome? ";
		string player1_name;
		std::getline(std::cin, player1_name);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		
		// garantisco che i due nomi siano diversi
		if(player1.name == player2.name)
			player2.name += "_1";
		
		// non è stato inserita la modalità di gioco da riga di comando
		// do comunque la possibilità all'utente di far giocare computer vs computer
		std::string input_str;
		while(input_str != "Y" && input_str != "N")
		{
			cout << player1_name << " vuoi che sia il computer a giocare al posto tuo? (Y/N) ";
			std::getline(std::cin, input_str);
			std::transform(input_str.begin(), input_str.end(), input_str.begin(), ::toupper);
			if(input_str=="Y")
			{
				player1.is_cpu = true;
				player1.auto_placement = true;
			}
		}
		input_str = "";
		
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
	}
	
	
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	
	Match partita(player1, player2, file_log);
	partita.play();
	file_log.close();
	
	
	return 0;
}
