/*
 * Programmering i C
 * HT13
 * Obligatorisk uppgift 4
 *
 * Fil:              game_of_life_io.c
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
#include "game_of_life_io.h"


void printGame(game *g) {

	int i, j;

	for(i = 0; i < (*g).rows ; i++) {
		for(j = 0 ; j < (*g).columns ; j++) {
			printf(" %c", (*g).field[i][j].current);
		}
		printf("\n");
	}
}


void printMenu(void) {

	printf("\nSelect one of the following options:\n");
	printf("\t(enter)\tStep\n");
	printf("\t(any)\tExit\n\n");
}


void printConfigurationMenu(void) {

	printf("\nSelect one of the following configurations:\n\n");
	printf("\t1. Glider\n");
	printf("\t2. Semaphore\n");
}


int readConfiguration(void) {

	int input;

	do {
		printConfigurationMenu();
		printf("\n> ");
		scanf("%d", &input);
	} while (input < 1 || input > 2);

	while(fgetc(stdin) != '\n');
	return input;
}

