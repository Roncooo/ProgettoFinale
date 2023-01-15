//	author: FRANCESCO RONCOLATO

#include "Match.h"

using game_board::Position;
using game_board::Grid;

Match::Match(Player& p1, Player& p2, Log& file)
	: player1{p1}, player2{p2}, file_log{file}
{
//	file_log.add(player1.name + "\n" + player2.name + "\n\n");
	file_log.write(player1.name + "\n" + player2.name + "\n\n");
	ship_placement(player1);
	ship_placement(player2);
}

void recap(const Player& player1, const Player& player2)
{
	std::vector<std::string> ship_names{"Battleship", "Support", "Submarine"};
	// gli interi vengono direttamente convertiti in stringhe, rende più agevole le operazioni di stampa
	std::vector<std::string> ship_count1{	std::to_string(player1.how_many_battleships()	),
											std::to_string(player1.how_many_supports()		),
											std::to_string(player1.how_many_submarines()	)
										};
	std::vector<std::string> ship_count2{	std::to_string(player2.how_many_battleships()	),
											std::to_string(player2.how_many_supports()		),
											std::to_string(player2.how_many_submarines()	)
										};
									
	// larghezza interna di ogni colonna, senza contare il padding di uno spazio a destra e uno a sinistra
	int width_0 = 0;
	int width_1 = player1.name.length();
	int width_2 = player2.name.length();
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
	
	std::cout << border << "\n";
	std::cout << first_row << "\n";
	std::cout << border << "\n";
	
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
	std::string input_string;	// tutto l'input (cin invece si ferma allo spazio)
	std::getline(std::cin, input_string);
	// trasformo in uppercase l'input
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
	
	// inizializzazione della regex, non so bene come/dove metterla, potrebbe essere benissimo statica
	// ma non so bene come fare
	std::string reg_rule = "[";
	for(int i=0; i<game_board::rows; i++)
		reg_rule += game_board::letters[i];
	reg_rule+="]([1-9]|1[012])";
	std::regex reg_position(reg_rule);
	
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
		if(!std::regex_match(in1, reg_position))
		{
			// comando non valido
			return -1;
		}
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
	// parto da una nave randomica, se questa è affondata passo alla successiva
	int ship_number = rand()%player.get_placed_ships();
	// queste cose non serovno più dato che ora ships contiene solo navi non affondate
//	for(int i=0; i<DefenceGrid::SHIP_NUMBER; i++)
//	{
//		if(player.get_ship(ship_number).is_sunk())
//		{
//			ship_number = (ship_number+1)%DefenceGrid::SHIP_NUMBER;
//			continue;
//		}
		origin = player.get_ship(ship_number).get_center();
//	}
	// in teoria il ciclo va sempre a buon fine perché random_command viene chiamata dopo aver controllato
	// che il giocatore non abbia perso, e quindi ci sarà almeno una nave non affondata
	
	target = random_position();
	return 20;	// per uniformarsi alle altre funzioni, indica che il comando prevede 2 posizioni valide
}


/* non chiama command così è valida anche per il robot
 * prende un codice ed esegue l'istruzione associata
 * poi restituisce nuovamente un codice per dire se è andato tutto bene
*/
int execute(Player& player, Player& enemy, int code, const Position& origin, const Position& target)
{	
	if(code == -1)
		return -1;	// comando non valido
	
	if(code == 10)	// codice riservato all'inserimento del sottomarino
		return -1;
	
	if(code == 1)	// xx stampa della griglia di difesa
	{
		player.print_defence();
		return 1;
	}
	
	if(code == 2)	// xx xx stampa della griglia di difesa e di attacco
	{
		player.print_defence_attack();
		return 2;
	}
	
	if(code == 3)	// aa aa
	{
		player.attack.reset_sonar();
		return 3;
	}
	
	if(code == 4)	// bb bb
	{
		player.attack.reset_matrix();
		return 4;
	}
	
	
	if(code == 5)	//	cc cc per vedere la griglia nemica utile per il debugging
	{
		enemy.print_defence();
		return 5;
	}
	
	if(code == 6)	//	tt tt per vedere la tabella
	{
		recap(player, enemy);
		return 6;
	}
	
	if(code == 20)	// due posizioni valide inserite
	{
		return player.act_ship(player.get_ship_index(origin), target, enemy);
	}
}

void Match::ship_placement(Player& p)
{
	if(p.auto_placement)
		bot_placement(p, file_log);
	else
		user_placement(p, file_log);
}

void user_placement(Player& p, Log& file_log)
{
	std::cout << "\n" + p.name + " inserisci le tue navi\n\n";
	Position prow, prune;
	
	for(int i=0; i<3; i++)
	{
		user_placement_helper(p, 2, prow, prune, "corazzata "+std::to_string(i+1), 5, i, file_log);
		p.add_ship(new Battleship(prow, prune, p)); 
	}
	for(int i=3; i<6; i++)
	{
		user_placement_helper(p, 2, prow, prune, "nave di supporto "+std::to_string(i+1-3), 3, i, file_log);
		p.add_ship(new Support(prow, prune, p)); 
	}
	for(int i=6; i<8; i++)
	{
		user_placement_helper(p, 1, prow, prune, "sottomarino "+std::to_string(i+1-6), 1, i, file_log);
		p.add_ship(new Submarine(prow, p)); 
	}
	
	std::cout << "\n" + p.name + ", questa e' la disposizione delle tue navi\n";
	p.print_defence();
}

void user_placement_helper(Player& p, int n_coordinates, Position& prow, Position& prune, 
							std::string ship_name, int ship_size, int ship_number, Log& file_log)
{
	bool ok = false;
	while(!ok)
	{
		if(n_coordinates==2)
			std::cout << ">> Quali sono le coordinate per la "+ship_name+":\n";
		else
			std::cout << ">> Qual e' la coordinata per il "+ship_name+":\n";
			
		//std::string prow_str, prune_str;		non è usato da nessuna parte
		
		int code = command(prow, prune);
		if(code==-1)
		{
			std::cout << "Il comando inserito non e' valido\n";
			continue;
		}
		
		if(code==1)
		{
			p.print_defence();
			continue;
		}
		
		if(code>=2 && code<=6)
		{
			std::cout << "La funzione inserita non e' disponibile in fase di inserimento delle navi\n";
			continue;
		}
		
		// è stata inserita una coordinata ma ne servono due
		if(code == 10 && n_coordinates == 2)
		{
			std::cout << "Sono necessarie due posizioni\n";
			continue;
		}
		
		// sono state inserite due coordinate ma ne serve una
		if(code == 20 && n_coordinates == 1)
		{
			std::cout << "E' necessaria una posizione\n";
			continue;
		}
		
		if(!p.is_valid(prow,prune))
		{
			if(n_coordinates==2)
				std::cout << "Le posizioni inserite non sono valide\n";
			else
				std::cout << "La posizione inserita non e' valida\n";
				
			continue;
		}
		
		// il +1 compensa abs che non considera la cella finale
		if((prow-prune).abs()+1 != ship_size)
		{
			if(n_coordinates==2)
				std::cout << "La "+ship_name+" deve essere lunga "+std::to_string(ship_size)+" caselle\n";
			else
				std::cout << "Il "+ship_name+" deve occupare una casella\n";
			
			continue;
		}
		
		// tutti i controlli sono andati a buon fine
		ok = true;
		//scrivo la posizione delle navi sul file di log
//		file_log.add(prow.toString() + " " + prune.toString() + "\n");
		file_log.write(prow, prune);
	}
}

void bot_placement_helper(Player& p, int ship_size, Position& prow, Position& prune, Log& file_log)
{
	bool ok = false;
	while(!ok)
	{
		prow = random_position();
		int direction = rand()%4;
		for(int i=1; i<=4; i++)	// ciclo sulle 4 direzioni partendo da una randomica
		{
			prune = ortogonal_position(prow, ship_size, direction);
			if(p.is_valid(prow, prune))
			{
				ok = true;
//				file_log.add(prow.toString() + " " + prune.toString() + "\n");
				file_log.write(prow, prune);
				break;
			}
			direction=(direction+1)%4;
		}
	}
}

void bot_placement(Player& p, Log& file_log)
{
	Position prow, prune;
	for(int i=0; i<3; i++)
	{
		bot_placement_helper(p, 5, prow, prune, file_log);
		p.add_ship(new Battleship(prow, prune, p));
	}
	for(int i=3; i<6; i++)
	{
		bot_placement_helper(p, 3, prow, prune, file_log);
		p.add_ship(new Support(prow, prune, p)); 
	}
	for(int i=6; i<8; i++)
	{
		bot_placement_helper(p, 1, prow, prune, file_log);
		p.add_ship(new Submarine(prow, p)); 
	}
	
	
	std::cout << "\n" + p.name + ", questa e' la disposizione delle tue navi\n";
	p.print_defence();
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
	case -1:
		std::cout << "Comando non valido\n";
		break;
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
	}
}

void round(Player& player, Player& enemy, Log& file_log)
{
	int code = -1;
	Position origin, target;
	
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
//	file_log.add(origin.toString() + " " + target.toString() + "\n");
	file_log.write(origin, target);
//	std::cout << "Comando eseguito\n\n";
}

void print_winner(Player& player)
{
	std::string str = player.name + " hai vinto!";
	std::cout << "\n+" + std::string(str.length()+2, '~') + "+\n";
	std::cout << "| " + str + " |\n";
	std::cout << "+" + std::string(str.length()+2, '~') + "+\n\n";
}

void Match::play()
{
	int n_rounds = 1;
	
	while(n_rounds<MAX_ROUNDS)
	{
		std::cout << "\nTurno: " << n_rounds << "\n";
//		file_log.add("\n>>Turno " + std::to_string(n_rounds) + ":\n" + ">>" + player1.name + "\n");
		file_log.write("\n>>Turno " + std::to_string(n_rounds) + ":\n" + ">>" + player1.name + "\n");
		
		round(player1, player2, file_log);
		if(player2.has_lost())
		{
			print_winner(player1);
			recap(player1, player2);
			
//			file_log.add("\n" + player1.name);
			file_log.write("\n" + player1.name);
			
			return;
		}
		n_rounds++;
		
//		file_log.add(">>" + player2.name + "\n");
		file_log.write(">>" + player2.name + "\n");
		
		round(player2, player1, file_log);
		if(player1.has_lost())
		{
			print_winner(player2);
			recap(player2, player1);
			
//			file_log.add("\n" + player2.name);
			file_log.write("\n" + player2.name);
			
			return;
		}
		n_rounds++;
	}
	std::cout << "*** Numero di turni massimo raggiunto ***\n";
	std::cout << "*** La partita e' finita con un pareggio ***\n";
	recap(player1, player2);
	
//	file_log.add("*** Numero di turni massimo raggiunto ***\n*** La partita e' finita con un pareggio ***\n");
	file_log.write("*** Numero di turni massimo raggiunto ***\n*** La partita e' finita con un pareggio ***\n");
}

void re_play(Player& p1, Player& p2, Log& file)		//lol
{
	file.read(p1.name);
	file.read(p2.name);
}

