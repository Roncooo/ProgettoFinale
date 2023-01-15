# ProgettoFinale
"This does what you think it does" We believe in our Lord and Saviour Jack

Per una lettura del codice più semplificata e chiara riportiamo brevemente le varie inclusioni di classi:
Le classi di base, Grid e Position, appartengono al namespace game_board. Grid presenta due classi derivate, AttackGrid e DefenceGrid. La classe virtuale pura Ship include DefenceGrid
e Position, mentre ha come classi figlie Submarine, Support e Battleship. La classe Player icnlude le tre tipologie di navi e le due griglie di attacco e difesa. Il file Log include Position
e infine Match include Player e Log.

Comandi per l'utente:

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