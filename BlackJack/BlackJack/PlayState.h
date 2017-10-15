#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameState.h"

#include "Deck.h"
#include "Hand.h"
#include "Stage.h"
#include "WinCon.h"

// Play Game State - Singleton
class PlayState : public GameState{
public:

	~PlayState(){}
	void Update() override;					// Updates the current state variables
	void Draw() override;					// Draw the current state to screen

	void DealFirstHand();					//deals two cards to player and dealer
	void DecideHit();						//gives the player options and dealer AI
	void Winner(int cValue, int pValue);	//decides win condition
	void Reset();

	//Singleton Design Pattern Begin
	//Only one exists in the program
	PlayState(const PlayState&){}				// Copy Constructor						
	PlayState& operator = (const PlayState&){}	// Assignment Operator
	static PlayState* Instance(){				// Access Function
		static PlayState play;
		return &play;
	}
	//Singleton Design Pattern End


private:
	PlayState();								// Constructor private because this is a singleton class

	Deck mDeck;									
	Hand mPlayer;								
	Hand mDealer;								
	bool mStarted = false;						// Has the first hand been dealt
	int mStage = DEALFIRST;						// Stage of the game
	int mWinCon;								// Win Condition reached
	bool mPlyrCont = false;						
	bool mCompCont = false;
};

#endif