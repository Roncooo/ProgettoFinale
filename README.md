# ProgettoFinale
"This does what you think it does" 

***SCHEMA DI DERIVAZIONE DELLE CLASSI***

namespace game_board{

Grid		
  |
  +-------- DefenceGrid
  |					
  |					
  +-------- AttackGrid		
							
Position						

}

Ship		
|
+-- Submarine
|
+-- Support
|
+-- Battleship

***SCHEMA DI INCLUSIONE DELLE CLASSI***

Position
|
+--------Grid
|	|
|	+--------	DefenceGrid
|	|	|
|	|	+--------	Ship
|	|			|
|	|			+------- Support
|	|			|		|
|	|			|		+----- Player
|	|			|				|
|	|			+------- Submarine	+----- Match
|	|			|		|
|	|			|		+----- Player
|	|			|				|
|	|			+------- Battleship	+----- Match
|	|					|
|	|					+----- Player
|	+-------- AttackGrid				|
|				|				+----- Match
|				+------- Battleship
|				|
|				+------- Player
|						|
+--------- Log				+----- Match
		 |
		 +----- Match

***COMANDI PER L'UTENTE***

xx		mostra griglia di difesa
xx xx		mostra griglia di difesa e attacco
aa aa		cancella solo gli avvistamenti sonar
bb bb		cancella tutta la griglia di attacco
cc cc		(da rimuovere?) mostra la griglia avversaria per gli imbroglioni
tt tt		mostra la tabella con il numero di navi ancora in vita


Il gioco segue il più fedelmente possibile il procedimento della Battaglia Navale classica: i due giocatori (di cui uno necessariamente robot) posizionano le proprie navi automaticamente, o nel caso dell'umano,
anche manualmente. I due giocatori devono interagire nelle fasi di attacco per sapere se i target sono stati colpiti, poiché come da gioco classico, non hanno e non devono aver accesso alla plancia di difesa
dell'avversario. Le interazioni sono date dalla classe Player e la partita è gestita dalla classe Match.
Attraverso l'oggetto Log in Match è poi possibile fare il replay della partita. 

author: Beatrice Bellesso