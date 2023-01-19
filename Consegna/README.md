author: Beatrice Bellesso

# ProgettoFinale C(alabrese)++

***Suddivisione del lavoro***
A causa del ritardo impiegato da uno dei tre componenti (più volte sollecitato dagli altri) nello sviluppo della sua porzione di progetto, la suddivisione risulta molto poco equilibrata. 
Sempre a causa di questo ritardo, alcune delle features richieste dalla consegna non funzionano in modo ottimale per esempio nel replay stampato sul terminale non avviene nessuna pausa e la formattazione non è completa.

Autore: Beatrice Bellesso
AttackGrid.cpp
AttackGrid.h
DefenceGrid.cpp
DefenceGrid.h
Ship.cpp
Ship.h
Submarine.cpp
Submarine.h
Support.cpp
Support.h
README.md

Autore: Bruzzese Fulvio
Log.cpp
Log.h
replay.cpp

Autore: Roncolato Francesco
Battleship.cpp
Battleship.h
Grid.cpp
Grid.h
Match.cpp
Match.h
Player.cpp
Player.h
Position.cpp
Position.h
main.cpp
CMakeLists.txt


***SCHEMA DI DERIVAZIONE DELLE CLASSI***

namespace game_board
{

Grid		
|
+-- DefenceGrid	
|					
+-- AttackGrid		

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
(Con la convenzione grafica: in alto la classe inclusa dalla classe in basso)

Position
|
+-- Grid
|	|
|	+-- DefenceGrid
|	|	|
|	|	+-- Ship
|	|		|
|	|		+-- Support
|	|		|	|
|	|		|	+-- Player
|	|		|		|
|	|		|		+-- Match
|	|		|
|	|		+-- Submarine	
|	|		|	|
|	|		|	+-- Player
|	|		|		|
|	|		|		+-- Match
|	|		|				
|	|		+-- Battleship	
|	|			|
|	|			+-- Player
|	|				|
|	|				+-- Match
|	|							
|	+-- AttackGrid				
|		|				
|		+-- Battleship
|		|
|		+-- Player
|			|
|			+-- Match
|						
+-- Log				
   |
   +-- Match

***COMANDI PER L'UTENTE***

xx			mostra griglia di difesa
xx xx		mostra griglia di difesa e attacco
aa aa		cancella solo gli avvistamenti sonar
bb bb		cancella tutta la griglia di attacco
cc cc		mostra la griglia avversaria per gli imbroglioni
tt tt		mostra la tabella con il numero di navi ancora in vita

N.B: abbiamo voluto includere il comando cc cc per semplificare la fase di debugging a noi progettisti, la incorporiamo nel codice definitivamente perché può essere utile nel correggere il codice. Il suo utilizzo è puramente a discrezione dell'utente.

***LEGENDA CODICI***	
Alcune delle funzioni sviluppate "parlano" tra di loro attraverso codici che identificano un errore, un comando o l'esito di un'azione e che riportiamo per una maggiore completezza del testo:
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
10 è stata inserita una posizione valida (inserimento del sottomarino)
20 sono state inserite due posizioni valide
30 colpo a vuoto
31 nave colpita
32 sottomarino spostato con successo
33 supporto spostato con successo
40 affondata nave corazzata
41 affondata nave di supporto
42 affondato sottomarino
100 partita terminata

***BREVE DESCRIZIONE***
Il gioco segue il più fedelmente possibile il procedimento della Battaglia Navale classica: i due giocatori (di cui uno necessariamente robot) posizionano le proprie navi automaticamente, o nel caso dell'umano, anche manualmente. I due giocatori devono interagire nelle fasi di attacco per sapere se i target sono stati colpiti, poiché come da gioco classico, non hanno e non devono aver accesso alla tavola di difesa dell'avversario. Le interazioni sono date dalla classe Player e la partita è gestita dalla classe Match. Attraverso l'oggetto Log in Match è poi possibile salvare quanto avvenuto e fare il replay della partita. 

***Funzionamento dell'eseguibile***
Come da consegna, è possibile indicare da riga di comando gli argomenti "pc" o "cc" per identificare una partita "persona-computer" o "computer-computer" (scritti in maiuscolo o a lettere invertite). Se non viene inserito un comando o il comando inserito non è valido, viene comunque avviato il gioco e si chiederà da standard input come si vuole procedere (ovvero se si vuole che sia il computer a giocare). In ogni caso per l'utente umano è possibile scegliere l'inserimento automatico delle navi.

