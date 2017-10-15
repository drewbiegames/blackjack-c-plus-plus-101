#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand{
public:
	void AddCard(Card c);					// Adds a card to hand		
	void ClearHand();						// Empty hand

	int GetCardCount();						// Get ammount of cards in hand
	Card GetCard(int no) const;				// Get a card in the hand
	std::vector<Card> GetHand();	

	int PlayerValueHand();					// Values hands	
	int DealerValueHand();

	void PrintHand(int x, int y);			// Print each card in the hand
	void PrintHiddenHand(int x, int y);		// Print hand hidden hand
	
private:
	std::vector<Card> mCards;
};

#endif