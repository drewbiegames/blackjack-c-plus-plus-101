#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck{
public:
	Deck();					// Populates deck with cards
	int ShuffleDeck();		// Randomises the order of the deck
	Card DealCard();		// Get a card from the deck
private:
	int RandomNumber();		// Generates a random number
	Card mDeck[52];			// The deck
	int mTopCard = 0;		// Keeps track of the top card of the deck
};

#endif