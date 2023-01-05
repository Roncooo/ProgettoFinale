//	author: FRANCESCO RONCOLATO

#include "Match.h"

void user_placement_helper(Player& p, int n_coordinates, Position& prow, Position& prune, 
							std::string ship_name, int ship_size, int ship_number);
void user_placement(Player& p);
void bot_placement_helper(Player& p, int ship_size, Position& start, Position& end);
void bot_placement(Player& p);
Position random_position();
Position ortogonal_position(const Position& start, int dim, int direction);
int execute(Player& player, Player& enemy, int code, const Position& origin, const Position& target);	// usata solo durante il gioco, non nell'inserimento
void print_code(int code, const Position& origin, const Position& target);
int random_command(Player& player, Position& origin, Position& target);

Match::Match(Player& p1, Player& p2)
	: player1{p1}, player2{p2}
{

	// altro?
}

std::vector<std::string> split(std::string str, char delimiter);

//	non ho capito, così facendo il compilatore non considera una funzione diversa da quella
//	dichiarata nella classe?
int command(Position& a, Position& b)
{
	std::string input_string;	// tutto l'input (cin invece si ferma allo spazio)
	std::getline(std::cin, input_string);
	// trasformo in uppercase l'input
	std::transform(input_string.begin(), input_string.end(), input_string.begin(), ::toupper);
	
	// COMANDI SPECIALI
	if(input_string == "XX")
		return 3;
		
	if(input_string == "XX XX")
		return 4;
	
	if(input_string == "AA AA")
		return 5;
	
	if(input_string == "BB BB")
		return 6;
	
	if(input_string == "CHEAT")
		return 10;
	
	// inizializzazione della regex, non so bene come/dove metterla, potrebbe essere benissimo statica
	// ma non so bene come fare
	std::string reg_rule = "[";
	for(int i=0; i<Grid::rows; i++)
		reg_rule += Grid::letters[i];
	reg_rule+="]([1-9]|1[012])";
	std::regex reg_position = std::regex(reg_rule);
	
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
			return -1;
		}
		else	// inserimento di un sottomarino
		{
			a = Position(in1);
			b = Position(in1);
			return 1;
		}
	}
	
	// a questo punto i comandi sono necessariamente 2 quindi o 2 coordinate o altro
	in2 = vec.at(1);
	if(std::regex_match(in1, reg_position) && std::regex_match(in2, reg_position))
	{
		a = Position(in1);
		b = Position(in2);
		return 2;
	}
	
	// se fin'ora non è stato riconosciuto un comando valido, è invalido
	return -1;
}

int random_command(Player& player, Position& origin, Position& target)
{
	// parto da una nave randomica, se questa è affondata passo alla successiva
	int ship_number = rand()%DefenceGrid::SHIP_NUMBER;
	for(int i=0; i<DefenceGrid::SHIP_NUMBER; i++)
	{
		if(player.defence.ships[ship_number]->is_sunk())
		{
			ship_number = (ship_number+1)%DefenceGrid::SHIP_NUMBER;
			continue;
		}
		origin = player.defence.ships[ship_number]->get_center();
	}
	// in teoria il ciclo va sempre a buon fine perché random_command viene chiamata dopo aver controllato
	// che il giocatore non abbia perso, e quindi ci sarà almeno una nave non affondata (in particolare una corazzata)
	
	target = random_position();
	return 2;	// per uniformarsi alle altre funzioni, indica che il comando prevede 2 posizioni valide
}


/* non chiama command così è valida anche per il robot
 * prende un codice ed esegue l'istruzione associata
 * poi restituisce nuovamente un codice per dire se è andato tutto bene
*/
int execute(Player& player, Player& enemy, int code, const Position& origin, const Position& target)
{	
	if(code == -1)
		return -1;	// comando non valido
	
	if(code == 1)	// codice riservato all'inserimento del sottomarino
		return -1;
	
	if(code == 3)	// stampa della griglia di difesa
	{
		Grid::print(player.defence);
		return 3;
	}
	
	if(code == 4)	// stampa della griglia di difesa e di attacco
	{
		Grid::print(player.defence, player.attack);
		return 4;
	}
	
	if(code == 5)
	{
		player.attack.reset_sonar();
		return 5;
	}
	
	if(code == 6)
	{
		player.attack.reset_matrix();
		return 5;
	}
	
	if(code == 10)	// comando "cheat", utile per il debugging
	{
		Grid::print(enemy.defence);
		return 10;
	}
	
	if(code == 2)	// due posizioni valide inserite
	{
		int selected_ship_index = -1;
		for(int i=0; i<DefenceGrid::SHIP_NUMBER; i++)
		{
			int ship_dimension = player.defence.ships[i]->get_dimension();
			Position ship_center = player.defence.ships[i]->pos[ship_dimension/2];
			if(origin==ship_center)
			{
				selected_ship_index = i;
				break;
			}
		}
		
		if(selected_ship_index == -1)
			return -4;		// la prima coordinata non è il centro di una nave
		
		if(player.defence.ships[selected_ship_index]->is_battleship())
		{
			// per ora funziona ma è assolutamente orribile e va sistemato
			// potenzialmente pericoloso perché non so se causa memory leak
			Battleship* selected = dynamic_cast<Battleship*>(&*(player.defence.ships[selected_ship_index]));
			selected->shoot(target, enemy);	// va sempre a buon fine (credo) perché le posizioni sono già valide
		}
			
		if(player.defence.ships[selected_ship_index]->is_support())
		{
			Support* selected = dynamic_cast<Support*>(&*(player.defence.ships[selected_ship_index]));
			// muove (e cura) se è possibile, altrimenti interrompe
			if(selected->cure(target)==-1)
				return -2;
		}
			
		if(player.defence.ships[selected_ship_index]->is_submarine())
		{
			Submarine* selected = dynamic_cast<Submarine*>(&*(player.defence.ships[selected_ship_index]));
			// muove (e cerca) se è possibile, altrimenti interrompe
			if(selected->search(target, enemy)==-1)
				return -3;
		}
		
		// tutto è andato a buon fine
		return 2;
	}
}

void Match::ship_placement(Player& p)
{
	if(p.auto_placement)
		bot_placement(p);
	else
		user_placement(p);
}

void user_placement(Player& p)
{
	std::cout << "\n" + p.name + " inserisci le tue navi\n\n";
	Position prow, prune;
	
	for(int i=0; i<3; i++)
	{
		user_placement_helper(p, 2, prow, prune, "corazzata "+std::to_string(i+1), 5, i);
		p.defence.ships[i] = std::make_unique<Battleship>(Battleship(prow, prune, p));	// qui manca la griglia di attacco
	}
	for(int i=3; i<6; i++)
	{
		user_placement_helper(p, 2, prow, prune, "nave di supporto "+std::to_string(i+1-3), 3, i);
		p.defence.ships[i] = std::make_unique<Support>(Support(prow, prune, p)); 
	}
	for(int i=6; i<8; i++)
	{
		user_placement_helper(p, 1, prow, prune, "sottomarino "+std::to_string(i+1-6), 1, i);
		p.defence.ships[i] = std::make_unique<Submarine>(Submarine(prow, p)); 
	}
	
	std::cout << "\n" + p.name + ", questa e' la disposizione delle tue navi\n";
	Grid::print(p.defence);
}

void user_placement_helper(Player& p, int n_coordinates, Position& prow, Position& prune, 
							std::string ship_name, int ship_size, int ship_number)
{
	bool ok = false;
	while(!ok)
	{
		if(n_coordinates==2)
			std::cout << ">> Quali sono le coordinate per la "+ship_name+":\n";
		else
			std::cout << ">> Qual e' la coordinata per il "+ship_name+":\n";
			
		std::string prow_str, prune_str;
		
		int code = command(prow, prune);
		if(code==-1)
		{
			std::cout << "Il comando inserito non e' valido\n";
			continue;
		}
		if(code==3)
		{
			Grid::print(p.defence);
			continue;
		}
		if(code==4 || code==5)
		{
			std::cout << "La funzione inserita non e' disponibile in fase di inserimento delle navi\n";
			continue;
		}
		
		if(code!=n_coordinates)
		{
			if(n_coordinates==2)
				std::cout << "Sono necessarie due posizioni\n";
			else
				std::cout << "E' necessaria una posizione\n";
			continue;
		}
		
		if(!p.defence.is_valid(prow,prune))
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
	}
}

void bot_placement_helper(Player& p, int ship_size, Position& prow, Position& prune)
{
	bool ok = false;
	while(!ok)
	{
		prow = random_position();
		int direction = rand()%4;
		for(int i=1; i<=4; i++)	// ciclo sulle 4 direzioni partendo da una randomica
		{
			prune = ortogonal_position(prow, ship_size, direction);
			if(p.defence.is_valid(prow, prune))
			{
				ok = true;
				break;
			}
			direction=(direction+1)%4;
		}
	}
}

void bot_placement(Player& p)
{
	Position prow, prune;
	for(int i=0; i<3; i++)
	{
		bot_placement_helper(p, 5, prow, prune);
		p.defence.ships[i] = std::make_unique<Battleship>(Battleship(prow, prune, p));
	}
	for(int i=3; i<6; i++)
	{
		bot_placement_helper(p, 3, prow, prune);
		p.defence.ships[i] = std::make_unique<Support>(Support(prow, prune, p)); 
	}
	for(int i=6; i<8; i++)
	{
		bot_placement_helper(p, 1, prow, prune);
		p.defence.ships[i] = std::make_unique<Submarine>(Submarine(prow, p)); 
	}
	
	
	std::cout << "\n" + p.name + ", questa e' la disposizione delle tue navi\n";
	Grid::print(p.defence);
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
	int r = 1 + rand()%Grid::rows;	// numero tra 1 e rows compresi
	int c = 1 + rand()%Grid::cols;	// numero tra 1 e cols compresi
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

bool has_lost(const Player& player)
{
	// per ciascuna nave nemica, se è una Corazzata e non è affondata, p non ha ancora vinto
	for(int i=0; i<DefenceGrid::SHIP_NUMBER; i++)
	{
		if(!player.defence.ships[i]->is_sunk())
			return false;
	}
	return true;
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
	case 3:
		// stampa della griglia di difesa
		break;
	case 4:
		// stampa di difesa e attacco
		break;
	case 5:
		std::cout << "Avvistamenti sonar resettati\n";
		break;
	}
}

void Match::play()
{
	int n_rounds = 0;
	int code;
	Position origin, target;
	
	while(n_rounds<MAX_ROUNDS)
	{
		// turno giocatore 1
		std::cout << player1.name + " e' il tuo turno\n";
		if(player1.is_cpu)
			code = random_command(player1,origin, target);
		else
			code = command(origin, target);
		code = execute(player1, player2, code, origin, target);
		
		while(code != 2)
		{
			if(player1.is_cpu)
				code = random_command(player1,origin, target);
			else
			{
				print_code(code, origin, target);
				code = command(origin, target);
			}
			code = execute(player1, player2, code, origin, target);
		}
		
		std::cout << "Comando eseguito\n";
		
		if(has_lost(player2))
		{
			std::cout << "\n-----------------------------\n" + player1.name + " hai vinto!";
			break;
		}
		
		
		// turno giocatore 2
		std::cout << player2.name + " e' il tuo turno\n";
		if(player2.is_cpu)
			code = random_command(player2,origin, target);
		else
			code = command(origin, target);
		code = execute(player2, player1, code, origin, target);
		
		while(code != 2)
		{
			if(player2.is_cpu)
				code = random_command(player2,origin, target);
			else
			{
				print_code(code, origin, target);
				code = command(origin, target);
			}
			code = execute(player2, player1, code, origin, target);
		}
		
		std::cout << "Comando eseguito " + std::to_string(n_rounds) +"\n";
		
		if(has_lost(player1))
		{
			std::cout << "\n-----------------------------\n" + player2.name + " hai vinto!";
			break;
		}
		
		n_rounds++;
	}
}

