#include <stdio.h>
#include "game_of_life_logics.h"
#include "game_of_life_configurations.c"
#include "game_of_life_io.c"
#include "game_of_life.c"

/* Funktion:    clearGame
 * Beskrivning: Initierar spelplanen med endast döda celler
 * Input:       En pekare till spelstrukturen
 * Output:      Inget
 */

 /* clears the board. every cell on the board are dead.
 pointing to the game structure.*/
void clearGame(game *g)
{
	int i, j;

	for(i = 0; i < g->rows; i++){
		for(j = 0; j < g->columns; j++){
			g->field[i][j].current = g->deadChar;
		}
	}
}

/* Funktion:    chooseConfiguration
 * Beskrivning: Låter användaren välja konfiguration,
 *              representationen för valet från ett heltal till
 *              en sträng
 * Input:       En pekare till en textsträng, innehållet i strängen
 *              kommer att ändras
 * Output:      I textsträngen som nås via pekaren lagras namnet på
 *              användarens val av konfiguration
 */
 //try to convert an int to a string
void chooseConfiguration(char *configuration)
{
	int choice;
	choice = readConfiguration();

	switch(choice)
	{
		case 1:
			*configuration = 'G';
			break;
		case 2:
			*configuration = 'S';
			break;
		default:
			chooseConfiguration(configuration);
			break;	
	}

}


/* Funktion:    createGame
 * Beskrivning: Laddar spelstrukturen med mönstret för den valda
 *              konfigurationen
 * Input:       En pekare till spelstrukturen, samt en pekare till
 *              en textsträng med namnet för den valda
 *              konfigurationen
 * Output:      Om det gick bra returneras talet 1, annars 0
 */
int createGame(game *g, char *configuration)
{
	if(*configuration == 'G'){
		loadGlider(g);
		return 1;
	}
	else if(*configuration == 'S'){
		loadSemaphore(g);
		return 1;
	}
	else return 0;
}

/* Funktion:    noOfNeighbors
 * Beskrivning: Räknar ut hur många levande grannar en cell har
 * Input:       En pekare till spelstrukturen, samt rad- och kolumn-
 *              nummer för den aktuella cellen
 * Output:      Antalet levande grannar till den aktuella cellen
 */
int noOfNeighbors(game *g, int row, int column)
{
	int alive = 0;

	/*int i, j;
	for(i = -1; i <= 1; i++){
		for(j = -1; j <= 1; j++){
			if(g->field[i][j].current == g->aliveChar){
				alive++;
			}
		}
	}*/


	if(g->field[row-1][column-1].current == g->aliveChar){
		alive += 1;
	}
	if(g->field[row+1][column+1].current == g->aliveChar){
		alive += 1;
	}
	if(g->field[row-1][column].current == g->aliveChar){
		alive += 1;
	}
	if(g->field[row+1][column].current == g->aliveChar){
		alive += 1;
	}
	if(g->field[row][column+1].current == g->aliveChar){
		alive += 1;
	}
	if(g->field[row][column-1].current == g->aliveChar){
		alive += 1;
	}
	if(g->field[row+1][column-1].current == g->aliveChar){
		alive += 1;
	}
	if(g->field[row-1][column+1].current == g->aliveChar){
		alive += 1;
	}

	return alive;


}


/* Funktion:    isAlive
 * Beskrivning: Avgör om den aktuella cellen är levande eller ej
 * Input:       En pekare till spelstrukturen, samt rad- och kolumn-
 *              nummer för den aktuella cellen
 * Output:      Returnerar 1 om cellen lever, annars 0
 */
int isAlive(game *g, int row, int column)
{
	if(g->field[row][column].current == g->aliveChar){
		return 1;
	}
	else{
		return 0;
	}
}

/* Funktion:    step
 * Beskrivning: I första steget beräknas tillståndet för varje cell
 *              i nästa generation. I andra steget uppdateras alla
 *              cellers tillstånd. Uppdatering till nästa generation
 *              är alltså synkroniserad
 * Input:       En pekare till spelstrukturen
 * Output:      Inget skrivs ut. Spelet har uppdaterats till nästa
 *              generation
 */
void step(game *g)
{
	int i, j;
	int nrOfAlive;

	for(i = 0; i < g->rows; i++){
		for(j = 0; j < g->columns; j++){
			nrOfAlive = noOfNeighbors(g, i ,j);
			if(g->field[i][j].current == g->deadChar && nrOfAlive != 3){
				g->field[i][j].next = g->deadChar;
			}
			if(g->field[i][j].current == g->aliveChar){
				if(nrOfAlive < 2 || nrOfAlive > 3){
					g->field[i][j].next = g->deadChar;
				}
				else if(nrOfAlive == 2 || nrOfAlive == 3){
					g->field[i][j].next = g->aliveChar;
				}
			}
			if(g->field[i][j].current == g->deadChar && nrOfAlive == 3){
				g->field[i][j].next = g->aliveChar;
			}
		}
	}
	for(i = 0; i < g->rows; i++){
		for(j = 0; j < g->columns; j++){
			g->field[i][j].current = g->field[i][j].next;
		}
	}
}

