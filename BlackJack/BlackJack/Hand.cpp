#include "Hand.h"
#include "PlayState.h"
#include "Input.h"

// Add card to hand
void Hand::AddCard(Card c){
	mCards.push_back(c);
};

// Clear hand
void Hand::ClearHand(){
	mCards.clear();
}

// Get amount of cards in hand
int Hand::GetCardCount(){
	return (mCards.size());
};

// Get a card from the hand
Card Hand::GetCard(int no) const{
	return (mCards.at(no));
};

// Get the whole hand
std::vector<Card> Hand::GetHand(){
	return mCards;
}

// Values player hand
int Hand::PlayerValueHand(){
	int hValue = 0;
	int hSize = GetCardCount();
	for (int no = 0; no < hSize; no++){
		int	cValue = GetCard(no).GetValue();
		
		if (cValue == 1){			//check for ace and if it has not been checked previously
			PlayState::Instance()->Draw();
			while (true){
				char chc = Input::Instance()->ReadInput();
				if (chc == 119 || chc == 87){							//check for W or w input
					hValue += 1;
					break;
				}
				else if (chc == 115 || chc == 83){						//check for S or s input
					hValue += 11;
					break;
				}
				else if (chc == 0){
					continue;
				}
			}
		}
		else{
			hValue += cValue;
		}
	}
	return hValue;
}

// Values Dealer Hand
int Hand::DealerValueHand(){
	int hValue = 0;
	int hSize = GetCardCount();
	bool acePresent = false;

	for (int no = 0; no < hSize; no++){
		int cValue = GetCard(no).GetValue();
		if (cValue == 1){ //check for ace
			acePresent = true;
			hValue += 11;
		}
		else{
			hValue += cValue;
		}
	}
	if (hValue > 21 && acePresent)
	{
		hValue -= 10;
	}
	return hValue;
}

// Print whole hand
void Hand::PrintHand(int x, int y){
	int hSize = GetCardCount();

	for (int no = 0; no < hSize; no++){
		mCards.at(no).drawAscii(x + (no * 6), y);
	}
}

// Print hidden card from hand
void Hand::PrintHiddenHand(int x, int y){
	int hSize = GetCardCount();

	for (int no = 0; no < hSize; no++){
		mCards.at(no).drawAsciiHidden(x + (no * 6), y);
	}
}