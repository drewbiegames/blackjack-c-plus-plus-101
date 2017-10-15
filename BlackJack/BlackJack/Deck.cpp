#include "Deck.h"
#include <string>

// Popluates deck with cards
Deck::Deck(){
	std::string suit[4] = { "Spades", "Diamonds", "Hearts", "Clubs" };
	std::string face[13] = { "Ace", "Two", "Three", "Four", "Five", "Six",
		"Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	int value[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

	for (int c = 0; c < 52; c++){
		mDeck[c] = Card(face[c % 13], suit[c / 13], value[c % 13]);
	}
}

// Randomises the order of the deck
int Deck::ShuffleDeck(){
	for (int i = 0; i < 52; i++){
		int n = RandomNumber();
		Card temp = mDeck[i];
		mDeck[i] = mDeck[n];
		mDeck[n] = temp;
	}
	return 0;
}

// Get the top card of the deck
Card Deck::DealCard(){
	if (mTopCard >= 52){
		ShuffleDeck();
		mTopCard = 0;
		Card tempCard = mDeck[mTopCard];
		mTopCard++;
		return tempCard;
	}
	else if (mTopCard < 52){
		Card tempCard = mDeck[mTopCard];
		mTopCard++;
		return tempCard;
	}
	else{
		return (mDeck[0]);
	}
}

// Generates a random number
int Deck::RandomNumber(){
	int r = rand();
	int randomNumber = r % 52;
	return randomNumber;
}