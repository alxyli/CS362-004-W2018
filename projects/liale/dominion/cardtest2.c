/*
 * Name: Alex Li
 * CS 362 - W18
 * cardtest2.c
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *		gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
 *      
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define NOISY_TEST 1

int main() {

	int seed = 1337;
	int numPlayer = 2;
	int handCount = 5;
	int player = 0;
	int handPos = 0;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int i, card;
	int k[10] = {adventurer, smithy, village, council_room,
					great_hall, baron, gardens, mine, feast, remodel
				};
	struct gameState testState, originalState;

	printf("TESTING Smithy card\n");	

	memset(&testState, 23, sizeof(struct gameState)); // initialize blank game states
	memset(&originalState, 23, sizeof(struct gameState));

	initializeGame(numPlayer, k, seed, &testState);
	memcpy(&originalState, &testState, sizeof(struct gameState)); // save testState to originalState for comparisons
#if (NOISY_TEST == 1)	
	printf("[before cardEffect] handCountTest %d\n", testState.handCount[0]);
	printf("[before cardEffect] handCountOG %d\n", originalState.handCount[0]);
#endif
	cardEffect(smithy, choice1, choice2, choice3, &testState, handPos, bonus);

	printf("TEST: Player 1 gains three cards\n");
#if (NOISY_TEST == 1)
	printf("[after cardEffect] handCountTest %d\n", testState.handCount[0]);
	printf("[after cardEffect] handCountOG %d\n", originalState.handCount[0]);
#endif

	if (testState.handCount[0] == originalState.handCount[0] + 2) // Smithy is discarded after drawing 3 cards
		printf("TEST PASSED\n");

	else
		printf("TEST FAILED\n");

	return 0;
}