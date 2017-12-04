/*
 * Programmering i C
 * HT13
 * Obligatorisk uppgift 4
 *
 * Fil:              game_of_life_configurations.c
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

#include "game_of_life_configurations.h"


int loadGlider(game *g) {

	if ((*g).rows > 19 && (*g).columns > 2) {
		(*g).field[17][0].current = (*g).aliveChar;
		(*g).field[17][1].current = (*g).aliveChar;
		(*g).field[17][2].current = (*g).aliveChar;
		(*g).field[18][2].current = (*g).aliveChar;
		(*g).field[19][1].current = (*g).aliveChar;
		return 1;
	}
	return 0;
}


int loadSemaphore(game *g) {

	if ((*g).rows > 9 && (*g).columns > 10) {
		(*g).field[9][8].current = (*g).aliveChar;
		(*g).field[9][9].current = (*g).aliveChar;
		(*g).field[9][10].current = (*g).aliveChar;
		return 1;
	}
	return 0;
}
