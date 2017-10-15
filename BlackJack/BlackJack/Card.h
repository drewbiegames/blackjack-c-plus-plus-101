#ifndef CARD_H
#define CARD_H

#include <string>

class Card{
public:
	Card(){};
	Card(std::string cardFace, std::string cardSuit, int cardValue);	// Sets card variables
	void setAsciiArt();													// Sets the art for the card
	void drawAscii(int x, int y) const;									// Get's ascii art coordinate
	void drawAsciiHidden(int x, int y);									// Draws hidden card art

	// Get-Set Functions
	int GetValue() const;														// Get's the value of the card
private:
	std::string mFace;
	std::string mSuit;
	int mValue;
	char asciiCard[7][5];
};

#endif