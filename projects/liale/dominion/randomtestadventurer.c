/*
 * Name: Alex Li
 * CS 362 - W18
 * randomtestcard1.c
 *
 * randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
 *		gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
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
#include <math.h>

#define NOISY_TEST 0

int main() {
	// seed RNG
	srand(time(NULL));

	// variable setup
	int tests = 10000;
	int test1Passes = 0;
	int test1Fails = 0;
	int test2Passes = 0;
	int test2Fails = 0;
	int test3Passes = 0;
	int test3Fails = 0;
	int player = 0; // check player 1
	int i, m, numPlayer, seed, card;
	int k[10] = {adventurer, smithy, village, council_room,
					great_hall, baron, gardens, mine, feast, remodel
				};
	struct gameState testState, originalState;

	printf("RANDOMLY TESTING Adventurer card\n");
	printf("---------------\n");
	for (i = 0; i < tests; i++) {
#if (NOISY_TEST == 1)
		printf("Test #: %d\n", i + 1);
#endif
		int treasureCount = 0; // reset treasureCount and originalTreasure after every test
		int originalTreasure = 0;
		int drawntreasure = 0;
		int cardDrawn = 0;
		int temphand[MAX_HAND];
		int z = 0;
		numPlayer = rand() % 3 + 2; // randomize number of players 2-4 (initializeGame should return -1 if < 2 or > 4 players)
		seed = rand(); // randomize seed for gameState
		memset(&testState, 23, sizeof(struct gameState)); // initialize blank game states prior to every test
		memset(&originalState, 23, sizeof(struct gameState));
		initializeGame(numPlayer, k, seed, &testState); // initialize test game state with random seed for every test	

		testState.whoseTurn = player;
		// randomly set player's deckCount, handCount, discardCount
		testState.deckCount[player] = rand() % MAX_DECK;
		testState.discardCount[player] = rand() % MAX_DECK;
		testState.handCount[player] = rand() % MAX_HAND;

		// put adventurer card in player hand
		testState.hand[player][0] = adventurer;
		
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

		// play adventure card
		adventurerCard(drawntreasure, player, &testState, cardDrawn, temphand, z);
#if (NOISY_TEST == 1)
		printf("TEST 1: Player 1 gained two cards\n");
#endif
		if (testState.handCount[0] == originalState.handCount[0] + 2)
			test1Passes++;

		else {
			test1Fails++;
			printf("TEST 1 FAILED ON TEST #%d\n", i);
			printf("testState handCount: %d / originalState handCount: %d\n", testState.handCount[0], originalState.handCount[0]);
		}

#if (NOISY_TEST == 1)
		printf("testState handCount: %d / originalState handCount: %d\n", testState.handCount[0], originalState.handCount[0]);

		printf("---------------\n");

		printf("TEST 2: Player 1 gained two treasure cards\n");
#endif

		// get treasure count in original state hand
		for (m = 0; m < originalState.handCount[0]; m++) {
			card = originalState.hand[0][m];
			if (card == copper || card == silver || card == gold)
				originalTreasure++;
		}

		// get treasure count in test state hand (after adventurer is played)
		for (m = 0; m < testState.handCount[0]; m++) {
			card = testState.hand[0][m];
			if (card == copper || card == silver || card == gold)
				treasureCount++;
		}

		if (treasureCount == originalTreasure + 2)
			test2Passes++;

		else {
			test2Fails++;
			printf("TEST 2 FAILED ON TEST #%d\n", i);
			printf("treasure: %d / original treasure: %d\n", treasureCount, originalTreasure);
		}

#if (NOISY_TEST == 1)
		printf("treasure: %d / original treasure: %d\n", treasureCount, originalTreasure);

		printf("---------------\n");

		printf("TEST 3: Other players did not gain cards\n");
#endif
		int otherPlayerCheck = 0;
		// set flag if adventurer changed the handCount of any player besides Player 1
		for (m = 1; m < numPlayer; m++) {
			if (testState.handCount[m] != originalState.handCount[m])
				otherPlayerCheck = 1;
		}

		if (otherPlayerCheck != 0)
			test3Fails++;

		else
			test3Passes++;

#if (NOISY_TEST == 1)
		for (m = 1; m < numPlayer; m++) {
			printf("testState.handCount[%d]: %d / originState.handCount[%d]: %d\n", m, testState.handCount[m], m, originalState.handCount[m]);
		}

		printf("---------------\n");
#endif
	}

	printf("\nAdventurer random tests complete....\n");
	printf("\nADVENTURER RANDOM TEST RESULTS\n");
	printf("---------------\n");
	printf("TEST 1 PASSES: %d\n", test1Passes);
	printf("TEST 1 FAILS: %d\n", test1Fails);
	printf("---------------\n");
	printf("TEST 2 PASSES: %d\n", test2Passes);
	printf("TEST 2 FAILS: %d\n", test2Fails);
	printf("---------------\n");
	printf("TEST 3 PASSES: %d\n", test3Passes);
	printf("TEST 3 FAILS: %d\n", test3Fails);

	return 0;
}