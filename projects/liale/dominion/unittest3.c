/*
 * Name: Alex Li
 * CS 362 - W18
 * unittest3.c
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
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

	int ret;

	printf("TESTING getCost()\n");

	printf("Beginning tests...\n");
	printf("---------------\n");

	printf("TEST 1: Curse\n");
	ret = getCost(0);

	if (ret == 0)
		printf("TEST 1 PASSED\n");

	else
		printf("TEST 1 FAILED\n");

	printf("---------------\n");

	printf("TEST 2: Estate\n");
	ret = getCost(1);

	if (ret == 2)
		printf("TEST 2 PASSED\n");

	else
		printf("TEST 2 FAILED\n");

	printf("---------------\n");

	printf("TEST 3: Duchy\n");
	ret = getCost(2);

	if (ret == 5)
		printf("TEST 3 PASSED\n");

	else
		printf("TEST 3 FAILED\n");

	printf("---------------\n");

	printf("TEST 4: Province\n");
	ret = getCost(3);

	if (ret == 8)
		printf("TEST 4 PASSED\n");

	else
		printf("TEST 4 FAILED\n");

	printf("---------------\n");

	printf("TEST 5: Copper\n");
	ret = getCost(4);

	if (ret == 0)
		printf("TEST 5 PASSED\n");

	else
		printf("TEST 5 FAILED\n");

	printf("---------------\n");

	printf("TEST 6: Silver\n");
	ret = getCost(5);

	if (ret == 3)
		printf("TEST 6 PASSED\n");

	else
		printf("TEST 6 FAILED\n");

	printf("---------------\n");

	printf("TEST 7: Gold\n");
	ret = getCost(6);

	if (ret == 6)
		printf("TEST 7 PASSED\n");

	else
		printf("TEST 7 FAILED\n");

	printf("---------------\n");

	printf("TEST 8: Adventurer\n");
	ret = getCost(7);

	if (ret == 6)
		printf("TEST 8 PASSED\n");

	else
		printf("TEST 8 FAILED\n");

	printf("---------------\n");

	printf("TEST 9: Council Room\n");
	ret = getCost(8);

	if (ret == 5)
		printf("TEST 9 PASSED\n");

	else
		printf("TEST 9 FAILED\n");

	printf("---------------\n");

	printf("TEST 10: Feast\n");
	ret = getCost(9);

	if (ret == 4)
		printf("TEST 10 PASSED\n");

	else
		printf("TEST 10 FAILED\n");

	printf("---------------\n");

	printf("TEST 11: Gardens\n");
	ret = getCost(10);

	if (ret == 4)
		printf("TEST 11 PASSED\n");

	else
		printf("TEST 11 FAILED\n");

	printf("---------------\n");

	printf("TEST 12: Mine\n");
	ret = getCost(11);

	if (ret == 5)
		printf("TEST 12 PASSED\n");

	else
		printf("TEST 12 FAILED\n");

	printf("---------------\n");

	printf("TEST 13: Remodel\n");
	ret = getCost(12);

	if (ret == 4)
		printf("TEST 13 PASSED\n");

	else
		printf("TEST 13 FAILED\n");

	printf("---------------\n");

	printf("TEST 14: Smithy\n");
	ret = getCost(13);

	if (ret == 4)
		printf("TEST 14 PASSED\n");

	else
		printf("TEST 14 FAILED\n");

	printf("---------------\n");

	printf("TEST 15: Village\n");
	ret = getCost(14);

	if (ret == 3)
		printf("TEST 15 PASSED\n");

	else
		printf("TEST 15 FAILED\n");

	printf("---------------\n");

	printf("TEST 16: Baron\n");
	ret = getCost(15);

	if (ret == 4)
		printf("TEST 16 PASSED\n");

	else
		printf("TEST 16 FAILED\n");

	printf("---------------\n");

	printf("TEST 17: Great Hall\n");
	ret = getCost(16);

	if (ret == 3)
		printf("TEST 17 PASSED\n");

	else
		printf("TEST 17 FAILED\n");

	printf("---------------\n");

	printf("TEST 18: Minion\n");
	ret = getCost(17);

	if (ret == 5)
		printf("TEST 18 PASSED\n");

	else
		printf("TEST 18 FAILED\n");

	printf("---------------\n");

	printf("TEST 19: Steward\n");
	ret = getCost(18);

	if (ret == 3)
		printf("TEST 19 PASSED\n");

	else
		printf("TEST 19 FAILED\n");

	printf("---------------\n");

	printf("TEST 20: Tribute\n");
	ret = getCost(19);

	if (ret == 5)
		printf("TEST 20 PASSED\n");

	else
		printf("TEST 20 FAILED\n");

	printf("---------------\n");

	printf("TEST 21: Ambassador\n");
	ret = getCost(20);

	if (ret == 3)
		printf("TEST 21 PASSED\n");

	else
		printf("TEST 21 FAILED\n");

	printf("---------------\n");

	printf("TEST 22: Cutpurse\n");
	ret = getCost(21);

	if (ret == 4)
		printf("TEST 22 PASSED\n");

	else
		printf("TEST 22 FAILED\n");

	printf("---------------\n");

	printf("TEST 23: Embargo\n");
	ret = getCost(22);

	if (ret == 2)
		printf("TEST 23 PASSED\n");

	else
		printf("TEST 23 FAILED\n");

	printf("---------------\n");

	printf("TEST 24: Outpost\n");
	ret = getCost(23);

	if (ret == 5)
		printf("TEST 24 PASSED\n");

	else
		printf("TEST 24 FAILED\n");

	printf("---------------\n");

	printf("TEST 25: Salvager\n");
	ret = getCost(24);

	if (ret == 4)
		printf("TEST 25 PASSED\n");

	else
		printf("TEST 25 FAILED\n");

	printf("---------------\n");

	printf("TEST 26: Sea Hag\n");
	ret = getCost(25);

	if (ret == 4)
		printf("TEST 26 PASSED\n");

	else
		printf("TEST 26 FAILED\n");

	printf("---------------\n");

	printf("TEST 27: Treasure Map\n");
	ret = getCost(26);

	if (ret == 4)
		printf("TEST 27 PASSED\n");

	else
		printf("TEST 27 FAILED\n");

	printf("---------------\n");

	printf("TEST 28: Non-existing card\n");
	ret = getCost(999);

	if (ret == -1)
		printf("TEST 28 PASSED\n");

	else
		printf("TEST 28 FAILED\n");


	return 0;
}