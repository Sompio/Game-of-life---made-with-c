/*
 * Programmering i C
 * HT13
 * Obligatorisk uppgift 4
 *
 * Fil:              game_of_life.h
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

#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#define MAX_ROWS 100
#define MAX_COLUMNS 100


/* Deklarationer av använda strukturer */
typedef struct {
	char current;
	char next;
} cell;

typedef struct {
	cell field[MAX_ROWS][MAX_COLUMNS];
	int rows;
	int columns;
	char aliveChar;
	char deadChar;
} game;

#endif // GAME_OF_LIFE_H
