/*
 * Name: Alex Li
 * CS 362 - W18
 * unittest2.c
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// NOISY_TEST = 0 -> remove extra printf statements from test output
#define NOISY_TEST 1

int main() {

	int seed = 1337;
	int numPlayer = 2;
	int handCount = 5;
	int player = 0;
	int i;
	int bonus;
	int ret;
	int k[10] = {adventurer, smithy, village, council_room,
					great_hall, baron, gardens, mine, feast, remodel
				};
	struct gameState G;

	int coppers[MAX_HAND];
	int silvers[MAX_HAND];
	int golds[MAX_HAND];
	// create arrays of treasure cards
	for (i = 0; i < MAX_HAND; i++) {
		coppers[i] = copper;
		silvers[i] = silver;
		golds[i] = gold;
	}

	printf("TESTING updateCoins()\n");

	memset(&G, 23, sizeof(struct gameState));
	ret = initializeGame(numPlayer, k, seed, &G);
	assert(ret == 0);

	G.handCount[player] = handCount; // set player 1 handCount to 5

	printf("Beginning tests...\n");
	printf("---------------\n");

	printf("TEST 1: 5 Copper hand / no bonus\n");
	memcpy(G.hand[player], coppers, sizeof(int) * handCount); // fill player 1 hand with 5 Coppers
	bonus = 0; // no bonus test
	updateCoins(player, &G, bonus);
#if (NOISY_TEST == 1)
	printf("G.coins value: %d / Hand value (5 coppers, no bonus): %d\n", G.coins, handCount * 1 + bonus);
#endif
	if (G.coins == handCount * 1 + bonus) 
		printf("TEST 1 PASSED\n");

	else
		printf("TEST 1 FAILED\n");

	printf("---------------\n");

	printf("TEST 2: 5 Copper hand / +2 bonus\n");
	memcpy(G.hand[player], coppers, sizeof(int) * handCount); // fill player 1 hand with 5 Coppers
	bonus = 2; // +2 bonus test
	updateCoins(player, &G, bonus);
#if (NOISY_TEST == 1)
	printf("G.coins value: %d / Hand value (5 coppers, +2 bonus): %d\n", G.coins, handCount * 1 + bonus);
#endif
	if (G.coins == handCount * 1 + bonus) 
		printf("TEST 2 PASSED\n");

	else
		printf("TEST 2 FAILED\n");

	printf("---------------\n");

	printf("TEST 3: 5 Silver hand / no bonuses\n");
	memcpy(G.hand[player], silvers, sizeof(int) * handCount); // fill player 1 hand with 5 Silvers
	bonus = 0; // no bonus test
	updateCoins(player, &G, bonus);
#if (NOISY_TEST == 1)
	printf("G.coins value: %d / Hand value (5 silvers, no bonus): %d\n", G.coins, handCount * 2 + bonus);
#endif
	if (G.coins == handCount * 2 + bonus) 
		printf("TEST 3 PASSED\n");

	else
		printf("TEST 3 FAILED\n");

	printf("---------------\n");

	printf("TEST 4: 5 Silver hand / +2 bonus\n");
	memcpy(G.hand[player], silvers, sizeof(int) * handCount); // fill player 1 hand with 5 Silvers
	bonus = 2; // +2 bonus test
	updateCoins(player, &G, bonus);
#if (NOISY_TEST == 1)
	printf("G.coins value: %d / Hand value (5 silvers, +2 bonus): %d\n", G.coins, handCount * 2 + bonus);
#endif
	if (G.coins == handCount * 2 + bonus) 
		printf("TEST 4 PASSED\n");

	else
		printf("TEST 4 FAILED\n");

	printf("---------------\n");

	printf("TEST 5: 5 Gold hand / no bonus\n");	
	memcpy(G.hand[player], golds, sizeof(int) * handCount); // fill player 1 hand with 5 Golds
	bonus = 0; // no bonus test
	updateCoins(player, &G, bonus);
#if (NOISY_TEST == 1)
	printf("G.coins value: %d / Hand value (5 golds, no bonus): %d\n", G.coins, handCount * 3 + bonus);
#endif
	if (G.coins == handCount * 3 + bonus) 
		printf("TEST 5 PASSED\n");

	else
		printf("TEST 5 FAILED\n");

	printf("---------------\n");

	printf("TEST 6: 5 Gold hand / +2 bonus\n");	
	memcpy(G.hand[player], golds, sizeof(int) * handCount); // fill player 1 hand with 5 Golds
	bonus = 2; // +2 bonus test
	updateCoins(player, &G, bonus);
#if (NOISY_TEST == 1)
	printf("G.coins value: %d / Hand value (5 golds, no bonus): %d\n", G.coins, handCount * 3 + bonus);
#endif
	if (G.coins == handCount * 3 + bonus) 
		printf("TEST 6 PASSED\n");

	else
		printf("TEST 6 FAILED\n");



	return 0;
}