author: Beatrice Bellesso

# ProgettoFinale C(alabrese)++
"This does what you think it does" 

***SCHEMA DI DERIVAZIONE DELLE CLASSI***

namespace game_board
{

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
+---Grid
|	|
|	+---DefenceGrid
|	|	|
|	|	+-------Ship
|	|			|
|	|			+-------Support
|	|			|		|
|	|			|		+-----Player
|	|			|			  |
|	|			|			  +----- Match
|	|			|
|	|			+-------Submarine	
|	|			|		|
|	|			|		+-----Player
|	|			|			  |
|	|			|			  +----- Match
|	|			|				
|	|			+-------Battleship	
|	|					|
|	|					+----- Player
|	|						   |
|	|						   +----- Match
|	|							
|	+-------- AttackGrid				
|				|				
|				+------- Battleship
|				|
|				+------- Player
|						 |
|						 +----- Match
|						
+--------- Log				
		   |
		   +----- Match

***COMANDI PER L'UTENTE***

xx			mostra griglia di difesa
xx xx		mostra griglia di difesa e attacco
aa aa		cancella solo gli avvistamenti sonar
bb bb		cancella tutta la griglia di attacco
cc cc		mostra la griglia avversaria per gli imbroglioni
tt tt		mostra la tabella con il numero di navi ancora in vita

N.B: abbiamo voluto includere il comando cc cc per semplificare la fase di debugging a noi progettisti, la incorporiamo nel codice definitivamente perché può essere utile
	 nel correggere il codice. Il suo utilizzo è puramente a discrezione dell'utente.

***LEGENDA CODICI***	
all'interno del codice sono stati utilizzati codici che identificano la natura dell'azione, di seguito vengono riportati per una maggiore completezza del testo:
-1 comando non valido
-2 non è possibile spostare la nave di supporto
-3 non è possibile spostare il sottomarino
-4 la prima posizione non è il centro della nave
1 comando xx
2 comando xx xx
3 comando aa aa
4 comando bb bb
5 comando cc cc
6 comando tt tt
30 colpo a vuoto
31 nave colpita
32 sottomarino spostato con successo
33 supporto spostato con successo

***BREVE DESCRIZIONE***
Il gioco segue il più fedelmente possibile il procedimento della Battaglia Navale classica: i due giocatori (di cui uno necessariamente robot) posizionano le proprie navi 
automaticamente, o nel caso dell'umano, anche manualmente. I due giocatori devono interagire nelle fasi di attacco per sapere se i target sono stati colpiti, 
poiché come da gioco classico, non hanno e non devono aver accesso alla tavola di difesa dell'avversario.
 Le interazioni sono date dalla classe Player e la partita è gestita dalla classe Match. Attraverso l'oggetto Log in Match è poi possibile fare il replay della partita. 
