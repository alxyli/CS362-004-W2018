/*
 * Name: Alex Li
 * CS 362 - W18
 * cardtest1.c
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 *		gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
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
	int treasure = 0;
	int originalTreasure = 0;
	int i, card;
	int k[10] = {adventurer, smithy, village, council_room,
					great_hall, baron, gardens, mine, feast, remodel
				};
	struct gameState testState, originalState;

	printf("TESTING Adventurer card\n");	

	memset(&testState, 23, sizeof(struct gameState)); // initialize blank game states
	memset(&originalState, 23, sizeof(struct gameState));

	initializeGame(numPlayer, k, seed, &testState);
	memcpy(&originalState, &testState, sizeof(struct gameState)); // save testState to originalState for comparisons

	cardEffect(adventurer, choice1, choice2, choice3, &testState, handPos, bonus);

	printf("TEST: Player 1 gains two treasure cards\n");
	for (i = 0; i < testState.handCount[0]; i++) {
		card = testState.hand[0][i];
		if (card == copper || card == silver || card == gold)
			treasure++;
	}

	for (i = 0; i < originalState.handCount[0]; i++) {
		card = originalState.hand[0][i];
		if (card == copper || card == silver || card == gold)
			originalTreasure++;
	}
	
#if (NOISY_TEST == 1)
	printf("treasure: %d / original treasure: %d\n", treasure, originalTreasure);
#endif
	if (treasure == originalTreasure + 2)
		printf("TEST PASSED\n");

	else
		printf("TEST FAILED\n");

	return 0;
}