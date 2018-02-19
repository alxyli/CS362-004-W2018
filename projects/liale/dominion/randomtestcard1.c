/*
 * Name: Alex Li
 * CS 362 - W18
 * randomtestcard1.c
 *
 * randomtestcard1: randomtestcard1.c dominion.o rngs.o
 *		gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
 *      
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define NOISY_TEST 0

int main() {
	// variable setup
	int tests = 10000;
	int test1Passes = 0;
	int test1Fails = 0;
	int handPos = 0;
	int player = 0; // will be checking player 1
	int i, m, numPlayer, seed;
	int k[10] = {adventurer, smithy, village, council_room,
					great_hall, baron, gardens, mine, feast, remodel
				};
	struct gameState testState, originalState;

	printf("RANDOMLY TESTING Smithy card\n");
	printf("---------------\n");
	for (i = 0; i < tests; i++) {
#if (NOISY_TEST == 1)
		printf("Test #: %d\n", i + 1);
#endif	


		numPlayer = rand() % 3 + 2; // randomize number of players 2-4 (initializeGame should return -1 if < 2 or > 4 players)
		seed = rand(); // randomize seed for gameState
		memset(&testState, 23, sizeof(struct gameState)); // initialize blank game states prior to every test
		memset(&originalState, 23, sizeof(struct gameState));
		initializeGame(numPlayer, k, seed, &testState); // initialize test game state with random parameters	

		testState.whoseTurn = player;
		// randomly set player's deckCount, handCount, discardCount
		testState.deckCount[player] = rand() % MAX_DECK;
		testState.discardCount[player] = rand() % MAX_DECK;
		testState.handCount[player] = rand() % MAX_HAND;

		// put smithy card in player hand
		testState.hand[player][0] = smithy;

		// randomly fill player 1 deck with cards
		for (m = 0; m < testState.deckCount[0]; m++) {
			enum CARD temp = rand() % 27;
			testState.deck[player][m] = temp;
		}

		// randomly fill player 1 discard deck with cards
		for (m = 0; m < testState.discardCount[0]; m++) {
			enum CARD temp = rand() % 27;
			testState.discard[player][m] = temp;
		}

		memcpy(&originalState, &testState, sizeof(struct gameState)); // save testState to originalState for comparisons

		// play smithy card
		smithyCard(player, &testState, handPos);

#if (NOISY_TEST == 1)
		printf("TEST: Player 1 gains three cards\n");
#endif

		if (testState.handCount[0] == originalState.handCount[0] + 2) // Smithy is discarded after drawing 3 cards
			test1Passes++;

		else {
			test1Fails++;
			printf("TEST FAILED ON TEST #%d\n", i);
			printf("testState handCount: %d / originalState handCount: %d\n", testState.handCount[0], originalState.handCount[0]);	
		}
	}


	printf("\nSmithy random test complete....\n");
	printf("\nSMITHY RANDOM TEST RESULTS\n");
	printf("---------------\n");
	printf("TEST PASSES: %d\n", test1Passes);
	printf("TEST FAILS: %d\n", test1Fails);

	return 0;
}