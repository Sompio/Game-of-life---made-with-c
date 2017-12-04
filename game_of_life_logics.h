/*
 * Programmering i C
 * HT13
 * Obligatorisk uppgift 4
 *
 * Fil:              game_of_life_logics.h
 * Beskrivning:      Ett program som implementerar Game of Life.
 *                   Användaren kan välja mellan ett antal
 *                   fördefinierade konfigurationer och därefter
 *                   stega igenom hur spelet utvecklas över tiden.
 *                   Programmet består av ett antal filer:
 *                      game_of_life.c
 *                      game_of_life.h
 *                      game_of_life_logics.c
 *                      game_of_life_logics.h
 *                      game_of_life_io.c
 *                      game_of_life_io.h
 *                      game_of_life_configurations.c
 *                      game_of_life_configurations.h
 * Författare:       Jonny Pettersson, Mattias Åsander
 * cs-användare      jonny, mattiasa
 * Datum:            26 oktober 2013
 * Användning:       ou4
 * Input:            Läser in val av handling från användaren.
 *                   Användaren får först välja konfiguration,
 *                   därefter kan användaren utveckla mönstret
 *                   stegvis och själv välja när det ska avslutas.
 * Output:           Skriver ut information till användaren om olika
 *                   val. Skriver ut det aktuella mönstret, samt när
 *                   programmet avslutas skrivs antalet generationer
 *                   ut.
 * Begränsning:      Det finns bara ett antal förprogrammerade
 *                   konfigurationer att välja på.
 */

#ifndef GAME_OF_LIFE_LOGICS_H
#define GAME_OF_LIFE_LOGICS_H

#include "game_of_life.h"


/* Funktionsbeskrivningar och -deklarationer */


/* Funktion:    clearGame
 * Beskrivning: Initierar spelplanen med endast döda celler
 * Input:       En pekare till spelstrukturen
 * Output:      Inget
 */
void clearGame(game *g);


/* Funktion:    chooseConfiguration
 * Beskrivning: Låter användaren välja konfiguration,
 *              representationen för valet från ett heltal till
 *              en sträng
 * Input:       En pekare till en textsträng, innehållet i strängen
 *              kommer att ändras
 * Output:      I textsträngen som nås via pekaren lagras namnet på
 *              användarens val av konfiguration
 */
void chooseConfiguration(char *configuration);


/* Funktion:    createGame
 * Beskrivning: Laddar spelstrukturen med mönstret för den valda
 *              konfigurationen
 * Input:       En pekare till spelstrukturen, samt en pekare till
 *              en textsträng med namnet för den valda
 *              konfigurationen
 * Output:      Om det gick bra returneras talet 1, annars 0
 */
int createGame(game *g, char *configuration);


/* Funktion:    noOfNeighbors
 * Beskrivning: Räknar ut hur många levande grannar en cell har
 * Input:       En pekare till spelstrukturen, samt rad- och kolumn-
 *              nummer för den aktuella cellen
 * Output:      Antalet levande grannar till den aktuella cellen
 */
int noOfNeighbors(game *g, int row, int column);


/* Funktion:    isAlive
 * Beskrivning: Avgör om den aktuella cellen är levande eller ej
 * Input:       En pekare till spelstrukturen, samt rad- och kolumn-
 *              nummer för den aktuella cellen
 * Output:      Returnerar 1 om cellen lever, annars 0
 */
int isAlive(game *g, int row, int column);


/* Funktion:    step
 * Beskrivning: I första steget beräknas tillståndet för varje cell
 *              i nästa generation. I andra steget uppdateras alla
 *              cellers tillstånd. Uppdatering till nästa generation
 *              är alltså synkroniserad
 * Input:       En pekare till spelstrukturen
 * Output:      Inget skrivs ut. Spelet har uppdaterats till nästa
 *              generation
 */
void step(game *g);


#endif // GAME_OF_LIFE_LOGICS_H
