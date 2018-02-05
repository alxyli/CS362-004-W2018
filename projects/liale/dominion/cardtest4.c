/*
 * Name: Alex Li
 * CS 362 - W18
 * cardtest4.c
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *		gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
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

	printf("TESTING Great Hall card\n");	

	memset(&testState, 23, sizeof(struct gameState)); // initialize blank game states
	memset(&originalState, 23, sizeof(struct gameState));

	initializeGame(numPlayer, k, seed, &testState);
	memcpy(&originalState, &testState, sizeof(struct gameState)); // save testState to originalState for comparisons

	cardEffect(great_hall, choice1, choice2, choice3, &testState, handPos, bonus);

	printf("TEST 1: Player 1 gains 1 card\n");
#if (NOISY_TEST == 1)	
	printf("[after cardEffect] handCountTest %d\n", testState.handCount[0]);
	printf("[after cardEffect] handCountOG %d\n", originalState.handCount[0]);
#endif
	if (testState.handCount[0] == originalState.handCount[0]) // Village discarded after drawing 1 card
		printf("TEST 1 PASSED\n");

	else
		printf("TEST 1 FAILED\n");

	printf("---------------\n");
#if (NOISY_TEST == 1)	
	printf("[after cardEffect] numActionsTest %d\n", testState.numActions);
	printf("[after cardEffect] numActionsOG %d\n", originalState.numActions);
#endif
	printf("TEST 2: Player 1 gains 1 action\n");
	if (testState.numActions == originalState.numActions + 1)
		printf("TEST 2 PASSED\n");

	else
		printf("TEST 2 FAILED\n");

	return 0;
}