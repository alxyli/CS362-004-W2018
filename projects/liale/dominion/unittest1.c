/*
 * Name: Alex Li
 * CS 362 - W18
 * unittest1.c
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
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
	int i;
	int ret;
	int k[10] = {adventurer, smithy, village, council_room,
					great_hall, baron, gardens, mine, feast, remodel
				};
	struct gameState G;

	printf("TESTING isGameOver()\n");

	memset(&G, 23, sizeof(struct gameState));
	ret = initializeGame(numPlayer, k, seed, &G);
	assert(ret == 0);

	printf("Beginning tests...\n");
	printf("---------------\n");

	printf("TEST 1: Empty Province card stack\n");
	G.supplyCount[province] = 0;
	ret = isGameOver(&G);
#if (NOISY_TEST == 1)
	printf("# Province cards: %d\n", G.supplyCount[province]);
#endif
	if (ret == 1)
		printf("TEST 1 PASSED\nisGameOver() returned %d\n", ret);
	
	else
		printf("TEST 1 FAILED\nisGameOver() returned %d\n", ret);

	printf("---------------\n");

	printf("TEST 2: Three empty supply piles\n");
	G.supplyCount[province] = 1;
	G.supplyCount[adventurer] = 0;
	G.supplyCount[council_room] = 0;
	G.supplyCount[gardens] = 0;
	ret = isGameOver(&G);
#if (NOISY_TEST == 1)
	printf("# Province cards: %d / # Adventuer cards: %d / # Council Room cards: %d / # Gardens cards: %d\n", 
			G.supplyCount[province], G.supplyCount[adventurer], G.supplyCount[council_room], G.supplyCount[gardens]);
#endif
	if (ret == 1) 
		printf("TEST 2 PASSED\nisGameOver() returned %d\n", ret);
	
	else 
		printf("TEST 2 FAILED\nisGameOver() returned %d\n", ret);
	

	printf("---------------\n");

	printf("TEST 3: Game still in progress\n");
	for (i = 0; i < 25; i++) {
		G.supplyCount[i] = 1;
	}
	ret = isGameOver(&G);
#if (NOISY_TEST == 1)
	for (i = 0; i < 25; i++) {
		printf("Number of cards in supply pile %d: %d\n", i, G.supplyCount[i]);
	}
#endif
	if (ret == 0)
		printf("TEST 3 PASSED\nisGameOver() returned %d\n", ret);

	else 
		printf("TEST 3 FAILED\nisGameOver() returned %d\n", ret);

	return 0;
}