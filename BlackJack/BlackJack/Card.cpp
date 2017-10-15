#include "Card.h"
#include "ScreenHandler.h"

// Set Card Values
Card::Card(std::string cardFace, std::string cardSuit, int cardValue){
	mFace = cardFace;
	mSuit = cardSuit;
	mValue = cardValue;
	setAsciiArt();
}

// Sets art for the card
void Card::setAsciiArt(){

	char suitSymbol; 
	//Spade 2660
	if (mSuit == "Spades")			suitSymbol = 'S';
	//Club 2663
	else if (mSuit == "Clubs")		suitSymbol = 'C';
	//Heart 2665
	else if (mSuit == "Hearts")		suitSymbol = 'H';
	//Diamond 2666
	else if (mSuit == "Diamonds")	suitSymbol = 'D';

	std::string faceSymbol;
	if		(mFace == "Ace")	faceSymbol = "A ";
	else if (mFace == "Two")	faceSymbol = "2 ";
	else if (mFace == "Three")	faceSymbol = "3 ";
	else if (mFace == "Four")	faceSymbol = "4 ";
	else if (mFace == "Five")	faceSymbol = "5 ";
	else if (mFace == "Six")	faceSymbol = "6 ";
	else if (mFace == "Seven")	faceSymbol = "7 ";
	else if (mFace == "Eight")	faceSymbol = "8 ";
	else if (mFace == "Nine")	faceSymbol = "9 ";
	else if (mFace == "Ten")	faceSymbol = "10";
	else if (mFace == "Jack")	faceSymbol = "J ";
	else if (mFace == "Queen")	faceSymbol = "Q ";
	else if (mFace == "King")	faceSymbol = "K ";
	
	asciiCard[0][0] = '/'; 
	asciiCard[0][1] = '-';
	asciiCard[0][2] = '-';
	asciiCard[0][3] = '-';
	asciiCard[0][4] = '\\';
	
	asciiCard[1][0] = '|';
	asciiCard[1][1] = faceSymbol[0];
	asciiCard[1][2] = faceSymbol[1];
	asciiCard[1][3] = ' ';
	asciiCard[1][4] = '|';

	asciiCard[2][0] = '|';
	asciiCard[2][1] = ' ';
	asciiCard[2][2] = ' ';
	asciiCard[2][3] = ' ';
	asciiCard[2][4] = '|';

	asciiCard[3][0] = '|';
	asciiCard[3][1] = ' ';
	asciiCard[3][2] = suitSymbol;
	asciiCard[3][3] = ' ';
	asciiCard[3][4] = '|';

	asciiCard[4][0] = '|';
	asciiCard[4][1] = ' ';
	asciiCard[4][2] = ' ';
	asciiCard[4][3] = ' ';
	asciiCard[4][4] = '|';

	asciiCard[5][0] = '|';
	asciiCard[5][1] = ' ';
	asciiCard[5][2] = faceSymbol[1];
	asciiCard[5][3] = faceSymbol[0];
	asciiCard[5][4] = '|';

	asciiCard[6][0] = '\\';
	asciiCard[6][1] = '-';
	asciiCard[6][2] = '-';
	asciiCard[6][3] = '-';
	asciiCard[6][4] = '/';

}

// Gets ascii art coordinate
void Card::drawAscii(int x, int y) const{
	for (int cardX = 0; cardX < 5; cardX++){
		for (int cardY = 0; cardY < 7; cardY++){
			ScreenHandler::Instance()->SetCharacter(x + cardX, y + cardY, asciiCard[cardY][cardX]);
		}
	}
}

// draws hidden ascii art
void Card::drawAsciiHidden(int x, int y){
	char asciiCardHidden[7][5];
	char art = '#';

	asciiCardHidden[0][0] = '/';
	asciiCardHidden[0][1] = '-';
	asciiCardHidden[0][2] = '-';
	asciiCardHidden[0][3] = '-';
	asciiCardHidden[0][4] = '\\';

	asciiCardHidden[1][0] = '|';
	asciiCardHidden[1][1] = art;
	asciiCardHidden[1][2] = art;
	asciiCardHidden[1][3] = art;
	asciiCardHidden[1][4] = '|';

	asciiCardHidden[2][0] = '|';
	asciiCardHidden[2][1] = art;
	asciiCardHidden[2][2] = art;
	asciiCardHidden[2][3] = art;
	asciiCardHidden[2][4] = '|';

	asciiCardHidden[3][0] = '|';
	asciiCardHidden[3][1] = art;
	asciiCardHidden[3][2] = art;
	asciiCardHidden[3][3] = art;
	asciiCardHidden[3][4] = '|';

	asciiCardHidden[4][0] = '|';
	asciiCardHidden[4][1] = art;
	asciiCardHidden[4][2] = art;
	asciiCardHidden[4][3] = art;
	asciiCardHidden[4][4] = '|';

	asciiCardHidden[5][0] = '|';
	asciiCardHidden[5][1] = art;
	asciiCardHidden[5][2] = art;
	asciiCardHidden[5][3] = art;
	asciiCardHidden[5][4] = '|';

	asciiCardHidden[6][0] = '\\';
	asciiCardHidden[6][1] = '-';
	asciiCardHidden[6][2] = '-';
	asciiCardHidden[6][3] = '-';
	asciiCardHidden[6][4] = '/';

	for (int cardX = 0; cardX < 5; cardX++){
		for (int cardY = 0; cardY < 7; cardY++){
			ScreenHandler::Instance()->SetCharacter(x + cardX, y + cardY, asciiCardHidden[cardY][cardX]);
		}
	}
}

// Get card value
int Card::GetValue() const{
	return mValue;
}