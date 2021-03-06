#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3, 
	       struct gameState *state, int handPos, int *bonus);

// Assignment 2 - card implementations refactor
void adventurerCard(int drawntreasure, int currentPlayer, struct gameState *state, int cardDrawn, int temphand[], int z);
void smithyCard(int currentPlayer, struct gameState *state, int handPos);
void villageCard(int currentPlayer, struct gameState *state, int handPos);
void councilRoomCard(int currentPlayer, struct gameState *state, int handPos);
void greatHallCard(int currentPlayer, struct gameState *state, int handPos);

#endif
