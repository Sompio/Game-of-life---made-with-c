/*
 * Programmering i C
 * HT13
 * Obligatorisk uppgift 4
 *
 * Fil:              game_of_life.c
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

#include <stdio.h>
#include "game_of_life.h"
#include "game_of_life_logics.h"
#include "game_of_life_io.h"



int main(void) {

	const int rows = 20;
	const int columns = 20;
	const int stringLength = 100;
	const char aliveChar = 'O';
	const char deadChar = '*';
	game g;
	char input;
	int generations = 1;
	char configuration[stringLength];

	/* Initiera spelplanen */
	g.rows = rows;
	g.columns = columns;
	g.aliveChar = aliveChar;
	g.deadChar = deadChar;

	clearGame(&g);

	/* Låt användaren välja konfiguration och ladda den */
	chooseConfiguration(configuration);
	if (!createGame(&g, configuration)) {
		printf("\nFailed to load configuration: %s\n", configuration);
		return 1;
	}

	/* Loopa så länge användaren trycker på enter */
	do {
		printGame(&g);
		printMenu();
		scanf("%c", &input);
		if(input == '\n') {
			step(&g);
			generations++;
		}
	} while(input == '\n');

	/* Skriv ut antalet generationer */
	printf("\nGenerations: %d\n", generations);

	return 0;
}

