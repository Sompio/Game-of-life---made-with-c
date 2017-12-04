/*
 * Programmering i C
 * HT13
 * Obligatorisk uppgift 4
 *
 * Fil:              game_of_life_configurations.h
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

#ifndef GAME_OF_LIFE_CONFIGURATIONS_H
#define GAME_OF_LIFE_CONFIGURATIONS_H

#include "game_of_life.h"


/* Funktionsbeskrivningar och -deklarationer */


/* Funktion:    loadGlider
 * Beskrivning: Laddar in en glider-konfiguration i en spelstruktur
 *              om den ryms
 * Input:       En pekare till spelstrukturen
 * Output:      Om det gick bra returneras talet 1, annars 0
 */
int loadGlider(game *g);


/* Funktion:    loadSemaphore
 * Beskrivning: Laddar in en semaphore-konfiguration i en
 *              spelstruktur om den ryms
 * Input:       En pekare till spelstrukturen
 * Output:      Om det gick bra returneras talet 1, annars 0
 */
int loadSemaphore(game *g);

#endif // GAME_OF_LIFE_CONFIGURATIONS_H
