//	author: FRANCESCO RONCOLATO

#include "Match.h"

using namespace game_board;

Match::Match(Player& p1, Player& p2, Log& file)
	: player1{p1}, player2{p2}, file_log{file}
{
	// definizione della regex statica per il riconoscimento di una posizione valida
	// una posizione valida è formata da una lettera compresa tra quelle valide (game_board::letters)
	// e da un numero compreso tra 1 e 12 (sono stati divisi i due casi dove il numero è tra 1-9 e tra 10-12)
	std::string reg_rule = "[";
	for(int i=0; i<game_board::rows; i++)
		reg_rule += game_board::letters[i];
	reg_position = std::regex(reg_rule+"]([1-9]|1[012])");
	
	file_log.write(player1.name + "\n" + player2.name + "\n\n");
	
	ship_placement(player1);
	ship_placement(player2);
}

void recap(const Player& player1, const Player& player2)
{
	std::vector<std::string> ship_names{"Battleship", "Support", "Submarine"};
	// gli interi vengono convertiti in stringhe, rende più agevole le operazioni di stampa
	std::vector<std::string> ship_count1{	std::to_string(player1.how_many_battleships()	),
											std::to_string(player1.how_many_supports()		),
											std::to_string(player1.how_many_submarines()	)
										};
	std::vector<std::string> ship_count2{	std::to_string(player2.how_many_battleships()	),
											std::to_string(player2.how_many_supports()		),
											std::to_string(player2.how_many_submarines()	)
										};
									
	// larghezze interne di ogni colonna, senza contare il padding di uno spazio a destra e uno a sinistra
	int width_0 = 0;
	int width_1 = player1.name.length();
	int width_2 = player2.name.length();
	
	// cerco la massima larghezza di ogni colonna
	for(int i=0; i<ship_names.size(); i++)
	{
		if(ship_names[i].length()>width_0)
			width_0 = ship_names[i].length();
		// controllo gli spazi occupati dai numeri per formattare correttamente anche il caso
		// in cui il nome del giocatore sia più corto del numero (nel nostro caso non succede mai)
		if(ship_count1[i].length()>width_1)
			width_1 = ship_count1[i].length();
		if(ship_count2[i].length()>width_2)
			width_2 = ship_count2[i].length();
	}
	
	std::string border = 	"+"+std::string(width_0+2, '-')+
							"+"+std::string(width_1+2, '-')+
							"+"+std::string(width_2+2, '-')+"+";
	
	std::string first_row = "|"+std::string(width_0+2, ' ');
	// se un numero è più largo del nome dell'utente, aggiungo degli spazi prima del nome
	first_row += "| "+std::string(width_1-player1.name.length(), ' ')+player1.name+" ";
	first_row += "| "+std::string(width_2-player2.name.length(), ' ')+player2.name+" |";
	
	// stampa la prima riga
	std::cout << border << "\n";
	std::cout << first_row << "\n";
	std::cout << border << "\n";
	
	// stampa delle righe con i dati
	for(int i=0; i<ship_names.size(); i++)
	{
		std::string row;
		row += "| " + ship_names[i] + std::string(width_0-ship_names[i].length(), ' ') + " ";
		row += "| " + std::string(width_1-ship_count1[i].length(), ' ') + ship_count1[i] + " ";
		row += "| " + std::string(width_2-ship_count2[i].length(), ' ') + ship_count2[i] + " |";
		std::cout << row << "\n";
	}
	std::cout << border << "\n";
}

int command(Position& a, Position& b)
{
	std::string input_string;
	std::getline(std::cin, input_string);
	std::transform(input_string.begin(), input_string.end(), input_string.begin(), ::toupper);
	
	// COMANDI SPECIALI
	
	if(input_string == "XX")
		return 1;
	if(input_string == "XX XX")
		return 2;
	if(input_string == "AA AA")
		return 3;
	if(input_string == "BB BB")
		return 4;
	if(input_string == "CC CC")
		return 5;
	if(input_string == "TT TT")
		return 6;
	
	
	// COMANDI CON COORDINATE
	
	std::vector<std::string> vec = split(input_string, ' ');
	std::string in1, in2;
	
	// se non c'è neanche un comando o più di due comandi, errore
	if(vec.size()==0 || vec.size()>2)
		return -1;
	
	// memorizzo il primo comando che a questo punto c'è per forza
	in1 = vec.at(0);
	
	// se non c'è un secondo comando, il primo deve essere la coordinata di inserimento di un sottomarino
	if(vec.size()==1)
	{
		if(!std::regex_match(in1, reg_position))	// comando non valido
			return -1;
		else	// inserimento di un sottomarino
		{
			a = Position(in1);
			b = Position(in1);
			return 10;
		}
	}
	
	// a questo punto i comandi sono necessariamente 2 quindi o 2 coordinate o errore
	in2 = vec.at(1);
	if(std::regex_match(in1, reg_position) && std::regex_match(in2, reg_position))
	{
		a = Position(in1);
		b = Position(in2);
		return 20;
	}
	
	// se fin'ora non è stato riconosciuto un comando valido, è invalido
	return -1;
}

int random_command(Player& player, Position& origin, Position& target)
{
	// si sceglie una nave randomica (che sicuramente esiste non affondata in quanto il vector ships in DefenceGrid contiene
	// solo navi non affondate e perché prima di un qualsiasi comando viene controllato se il giocatore ha perso)
	int ship_number = rand()%player.get_placed_ships();
	origin = player.get_ship(ship_number).get_center();
	// il target invece è scelto a caso tra le 12x12 posizioni possibili
	target = random_position();
	// il comando così restituito potrebbe non andare a buon fine (spostamento non valido)
	// il controllo di validità viene fatto da round
	return 20;	// per uniformarsi alle altre funzioni, indica che il comando prevede 2 posizioni valide
}

// prende un codice ed esegue l'istruzione associata
// poi restituisce nuovamente un codice per dire se è andato tutto bene e per permettere le stampe
int execute(Player& player, Player& enemy, int code, const Position& origin, const Position& target)
{
	switch(code)
	{
	case 10:	// codice riservato all'inserimento del sottomarino
		return -1;
	case 1:		// xx stampa della griglia di difesa
		player.print_defence();
		return 1;
	case 2:		// xx xx stampa della griglia di difesa e di attacco
		player.print_defence_attack();
		return 2;
	case 3:		// aa aa
		player.attack.reset_sonar();
		return 3;
	case 4:		// bb bb
		player.attack.reset_matrix();
		return 4;
	case 5:		// cc cc per vedere la griglia nemica utile per il debugging
		enemy.print_defence();
		return 5;
	case 6:		// tt tt per vedere la tabella
		recap(player, enemy);
		return 6;
	case 20:	// due posizioni valide inserite
		return player.act_ship(player.get_ship_index(origin), target, enemy);
	default:	// coincide con case -1: comando non valido
		return -1;
	}
}

void Match::ship_placement(Player& player)
{
	if(player.auto_placement)
		bot_placement(player, file_log);
	else
		user_placement(player, file_log);
		
	if(!player.is_cpu)
	{
		std::cout << "\n" + player.name + ", questa e' la disposizione delle tue navi\n" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		player.print_defence();
	}
}

void user_placement(Player& player, Log& file_log)
{
	std::cout << "\n" + player.name + " inserisci le tue navi\n\n";
	Position prow, prune;
	
	// uso una lambda expression per evitare codice duplicato
	auto user_placement_helper = [&player, &prow, &prune](std::string ship_name, int ship_size)
	{
		bool ok = false;
		while(!ok)
		{
			if(ship_size==1)
				std::cout << ">> Qual e' la coordinata per il "+ship_name+":\n";
			else
				std::cout << ">> Quali sono le coordinate per la "+ship_name+":\n";
			
			int code = command(prow, prune);
			
			if(code==-1)
			{
				std::cout << "Il comando inserito non e' valido\n";
				continue;
			}
			
			// comando xx
			if(code==1)
			{
				player.print_defence();
				continue;
			}
			
			// codici relativi ai comandi xx xx, aa aa, bb bb, cc cc, tt tt
			if(code>=2 && code<=6)
			{
				std::cout << "La funzione inserita non e' disponibile in fase di inserimento delle navi\n";
				continue;
			}
			
			// è stata inserita una coordinata ma ne servono due
			if(code == 10 && ship_size > 1)
			{
				std::cout << "Sono necessarie due posizioni\n";
				continue;
			}
			
			// sono state inserite due coordinate ma ne serve una
			if(code == 20 && ship_size == 1)
			{
				std::cout << "E' necessaria una posizione\n";
				continue;
			}
			
			if(!player.is_valid(prow,prune))
			{
				if(ship_size==1)
					std::cout << "La posizione inserita non e' valida\n";
				else
					std::cout << "Le posizioni inserite non sono valide\n";
					
				continue;
			}
			
			// il +1 compensa abs il fatto che non considera la cella finale
			if((prow-prune).abs()+1 != ship_size)
			{
				if(ship_size==1)
					std::cout << "Il "+ship_name+" deve occupare una casella\n";
				else
					std::cout << "La "+ship_name+" deve essere lunga "+std::to_string(ship_size)+" caselle\n";
				
				continue;
			}
			
			// tutti i controlli sono andati a buon fine
			ok = true;
		}
	};
	
	
	for(int i=1; i<=game_board::MAX_BATTLESHIPS; i++)
	{
		user_placement_helper("corazzata "+std::to_string(i), 5);
		player.add_ship(new Battleship(prow, prune, player)); 
		file_log.write(prow, prune);
	}
	for(int i=1; i<=game_board::MAX_SUPPORTS; i++)
	{
		user_placement_helper("nave di supporto "+std::to_string(i), 3);
		player.add_ship(new Support(prow, prune, player)); 
		file_log.write(prow, prune);
	}
	for(int i=1; i<=game_board::MAX_SUBMARINES; i++)
	{
		user_placement_helper("sottomarino "+std::to_string(i), 1);
		player.add_ship(new Submarine(prow, player)); 
		file_log.write(prow, prune);
	}
	
	// la stampa della griglia avviene in ship_placement così da discernere utente umano e computerizzato
}

void bot_placement(Player& player, Log& file_log)
{
	Position prow, prune;
	
	// uso una lambda per evitare codice duplicato
	auto bot_placement_helper = [&player, &prow, &prune](int ship_size)
	{
		bool ok = false;
		while(!ok)
		{
			// ciclo sulle 4 direzioni partendo da una randomica
			prow = random_position();
			int direction = rand()%4;
			for(int i=1; i<=4; i++)
			{
				prune = ortogonal_position(prow, ship_size, direction);
				if(player.is_valid(prow, prune))
				{
					ok = true;
					break;
				}
				// se la direzione non è valida si sceglie la successiva in modo da non scegliere la stessa due volte 
				direction=(direction+1)%4;
			}
		}
	};
	
	for(int i=1; i<=game_board::MAX_BATTLESHIPS; i++)
	{
		bot_placement_helper(5);
		player.add_ship(new Battleship(prow, prune, player));
		file_log.write(prow, prune);
	}
	for(int i=1; i<=game_board::MAX_SUPPORTS; i++)
	{
		bot_placement_helper(3);
		player.add_ship(new Support(prow, prune, player));
		file_log.write(prow, prune);
	}
	for(int i=1; i<=game_board::MAX_SUBMARINES; i++)
	{
		bot_placement_helper(1);
		player.add_ship(new Submarine(prow, player)); 
		file_log.write(prow, prune);
	}
	
	// la stampa della griglia avviene in ship_placement così da discernere utente umano e computerizzato
}

std::vector<std::string> split(std::string str, char delimiter)
{
	std::vector<std::string> vec;
	std::string temp;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]==delimiter)
		{
			vec.push_back(temp);
			temp="";
		}
		else
		{
			temp += str[i];
		}
	}
	vec.push_back(temp);
	return vec;
}

Position random_position()
{
	int r = rand()%game_board::rows;	// numero tra 0 compreso e rows escluso
	int c = rand()%game_board::cols;	// numero tra 0 compreso e cols escluso
	return Position(r,c);
}

Position ortogonal_position(const Position& start, int dim, int direction)
{
	dim-=1;
	switch(direction)
	{
		case 0:
			return start+Position(0,dim);	// destra
			break;
		case 1:
			return start+Position(0,-dim);	// sinstra
			break;
		case 2:
			return start+Position(dim,0);	// sotto
			break;
		case 3:
			return start+Position(-dim,0);	// sopra
			break;
	}
}

void print_code(int code, const Position& origin, const Position& target)
{
	switch(code)
	{
	case -2:
		std::cout << "Non e' possibile spostare la nave di supporto nella posizione " << target << "\n";
		break;
	case -3:
		std::cout << "Non e' possibile spostare il sottomarino nella posizione " << target << "\n";
		break;
	case -4:
		std::cout << origin << " non e' il centro di una nave\n";
	case 1:
		// stampa della griglia di difesa
		break;
	case 2:
		// stampa di difesa e attacco
		break;
	case 3:
		std::cout << "Avvistamenti sonar resettati\n";
		break;
	case 4:
		std::cout << "Griglia di attacco resettata\n";
		break;
	case 5:
		std::cout << "Ecco la griglia dell'avversario, shhh!\n";
		break;
	case 6:
		std::cout << "Ecco le navi ancora a galla\n";
		break;
	case 30:
		std::cout << "Acqua\n";
		break;
	case 31:
		std::cout << "Colpito\n";
		break;
	case 32:
		// sottomarino spostato con successo
		break;
	case 33:
		// supporto spostato con successo
		break;
	case 40:
		//hai colpito e affondato una CORAZZATA
		std::cout << "Colpito\n";
		std::cout << "~~~Hai affondato una corazzata!~~~\n";
		break;
	case 41:
		//hai colpito e affondato una NAVE DI SUPPORTO
		std::cout << "Colpito\n";
		std::cout << "~~~Hai affondato una nave di supporto!~~~\n";
		break;
	case 42:
		//hai colpito e affondato un SOTTOMARINO
		std::cout << "Colpito\n";
		std::cout << "~~~Hai affondato un sottomarino!~~~\n";
		break;
	default:
		// coincide con case -1:
		std::cout << "Comando non valido\n";
		break;
	}
}

int round(Player& player, Player& enemy, Log& file_log)
{
	int code = -1;
	Position origin, target;
	
	// se c'è un (solo) umano, viene fatta una pausa prima della mossa del nemico
	// migliora la leggibilità della partita
	if(!player.is_cpu != !enemy.is_cpu)
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	
	if(player.is_cpu)
		std::cout << player.name + " svolge il suo turno\n";
	else
		std::cout << player.name + " e' il tuo turno\n";
	
	// un turno è valido solo quando sono inserite due posizioni
	while(code < 30)
	{
		if(player.is_cpu)
			code = random_command(player, origin, target);
		else
			code = command(origin, target);
		
		code = execute(player, enemy, code, origin, target);
		
		// solo agli umani comunico il messaggio 
		if(!player.is_cpu)
			print_code(code, origin, target);
	}
	
	// a questo punto è stato eseguito un comando non speciale
	// scrivo nel file
	file_log.write(origin, target);
	
	if(enemy.has_lost())
	{
		std::cout << "\n";
		print_winner(player);
		recap(player, enemy);
		
//		std::string winner = winner_string(player);
		file_log.write("\n" + eof + "Il vincitore e'  " + player.name);
		
		return 100;	// partita terminata
	}
}

std::string winner_string(Player& player)
{
	std::string str = player.name + " hai vinto!";
	std::string winner = "+";
	std::string tilde = std::string(str.length()+2, '~');
	winner += tilde + "+\n";
	winner += "| " + str + " |\n";
	winner += "+" + tilde + "+\n\n";
	
	return winner;
}

void print_winner(Player& player)
{
//	std::string str = player.name + " hai vinto!";
//	std::cout << "\n+" + std::string(str.length()+2, '~') + "+\n";
//	std::cout << "| " + str + " |\n";
//	std::cout << "+" + std::string(str.length()+2, '~') + "+\n\n";
	std::cout << winner_string(player);
}

void Match::play()
{
	int n_rounds = 1;
	
	int active_player = rand()%2;
	if(active_player == 0)
		std::cout << "Iniziera' a giocare: " << player1.name << std::endl;
	else
		std::cout << "Iniziera' a giocare: " << player2.name << std::endl;
	
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	
	while(n_rounds<MAX_ROUNDS)
	{
		std::cout << "\nTurno: " << n_rounds << "\n";
		if(active_player==0)
		{
			file_log.write("\n" + ignore + "Turno " + std::to_string(n_rounds) + ":\n" + ignore + player1.name + "\n");
			if(round(player1, player2, file_log)==100) 
				return;
		}
		else
		{
			file_log.write("\n" + ignore + "Turno " + std::to_string(n_rounds) + ":\n" + ignore + player2.name + "\n");
			if(round(player2, player1, file_log)==100)
				return;
		}
		active_player = !active_player;
		n_rounds++;
	}
	
	std::cout << "\n*** Numero di turni massimo raggiunto ***\n";
	std::cout << "*** La partita e' finita con un pareggio ***\n";
	recap(player1, player2);
	
	file_log.write("\n" + eof + "*** Numero di turni massimo raggiunto ***\n*** La partita e' finita con un pareggio ***\n");
}

