/*
 * Name: Alex Li
 * CS 362 - W18
 * unittest4.c
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {

	struct gameState G;

	printf("TESTING whoseTurn()\n");	
	printf("Beginning tests...\n");
	printf("---------------\n");
	
	G.whoseTurn = 0;

	printf("TEST 1: Player 1's turn\n");
	if (whoseTurn(&G) == 0)
		printf("TEST 1 PASSED\n");

	else
		printf("TEST 1 FAILED\n");

	printf("---------------\n");

	printf("TEST 2: Player 2's turn\n");
	G.whoseTurn = 1;

	if (whoseTurn(&G) == 1)
		printf("TEST 2 PASSED\n");

	else
		printf("TEST 2 FAILED\n");

	return 0;
}