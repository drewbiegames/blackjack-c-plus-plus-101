#include "PlayState.h"

#include "Game.h"
#include "MainMenu.h"
#include "Input.h"
#include "ScreenHandler.h"

#include <time.h>
#include <string>

PlayState::PlayState(){
	time_t t;
	srand((unsigned int)time(&t));
}

// Updates the current state variables
void PlayState::Update(){
	switch (mStage){
	case DEALFIRST:			//Deals first hand
		mDeck.ShuffleDeck();
		DealFirstHand();
		mStage = HITSTAND;
		mStarted = true;
		break;
	case HITSTAND:			// Lets player and dealer decide (Hit or Stand)
		DecideHit();
		break;
	case WINNER:			// Waits and then asks game reset?
		Sleep(10000);
		mStage = RESET;
		break;
	case RESET:				
		Reset();
		break;
	}

}

// Draws the current state to screen, uses the Stage enum to decide what to print
void PlayState::Draw(){

	ScreenHandler::Instance()->ClearBuffer();
	if (mStarted){
		if (mStage == HITSTAND){
			mDealer.PrintHiddenHand(2, 2);
			mPlayer.PrintHand(2, 13);
			ScreenHandler::Instance()->SetCharacter(2, 1, "Dealer's Hand:");
			ScreenHandler::Instance()->SetCharacter(2, 12, "Player's Hand:");
			ScreenHandler::Instance()->SetCharacter(5, 10, "Hit (W)");
			ScreenHandler::Instance()->SetCharacter(22, 10, "Stand (S)");
		}
		if (mStage == ACEDECIDE){
			mDealer.PrintHiddenHand(2, 2);
			mPlayer.PrintHand(2, 13);
			ScreenHandler::Instance()->SetCharacter(2, 1, "Dealer's Hand:");
			ScreenHandler::Instance()->SetCharacter(2, 12, "Player's Hand:");
			ScreenHandler::Instance()->SetCharacter(6, 10, "Does your Ace count as");
			ScreenHandler::Instance()->SetCharacter(10, 11, "1 (W) or 11(S)?");
		}
		if (mStage == WINNER){				// uses the WinCon the decide what message to print
			std::string winMessage;
			switch (mWinCon){
			case FIVECARDCHARLIE:
				winMessage = "Five Card Charlie! You are awesome.";
				break;
			case BOTHBUST:
				winMessage = "You have both gone bust!";
				break;
			case YOUBUST:
				winMessage = "You have gone bust!";
				break;
			case DEALERBUST:
				winMessage = "The dealer has gone bust!";
				break;
			case BOTH21YOU:
				winMessage = "Both of you have 21. You win        because you fewer cards.";
				break;
			case BOTH21COMP:
				winMessage = "Both of you have 21. You lose       becasue the dealer has fewer        cards.";
				break;
			case BOTH21TIE:
				winMessage = "You both have 21 and the same       amount of cards. Tie.";
				break;
			case DEALER21:
				winMessage = "The Dealer has got 21!";
				break;
			case YOU21:
				winMessage = "You have 21!";
				break;
			case YOUWIN:
				winMessage = "You have won this hand!";
				break;
			case DEALERWIN:
				winMessage = "The dealer has won this hand.";
				break;
			case YOUTIE:
				winMessage = "You win becasue you have fewer      cards.";
				break;
			case DEALERTIE:
				winMessage = "Dealer wins because they have       fewer cards.";
				break;
			case TIE:
				winMessage = "It's a draw!";
				break;
			}
			mDealer.PrintHand(2, 2);
			mPlayer.PrintHand(2, 13);
			ScreenHandler::Instance()->SetCharacter(2, 1, "Dealer's Hand:");
			ScreenHandler::Instance()->SetCharacter(2, 12, "Player's Hand:");
			ScreenHandler::Instance()->SetCharacter(2, 10, winMessage);
		}
		if (mStage == RESET){
			ScreenHandler::Instance()->SetCharacter(2, 10, "Would you like to play again?");
			ScreenHandler::Instance()->SetCharacter(5, 11, "Yes (W)");
			ScreenHandler::Instance()->SetCharacter(22, 11, "No (S)");

		}
	}
	ScreenHandler::Instance()->SwapToBuffer();
}

// Deals two card to each hand
void PlayState::DealFirstHand(){
	mPlayer.AddCard(mDeck.DealCard());
	mDealer.AddCard(mDeck.DealCard());
	mPlayer.AddCard(mDeck.DealCard());
	mDealer.AddCard(mDeck.DealCard());
}

// Gets the player and dealers choice to get more cards
void PlayState::DecideHit(){
	int compValue;
	int plyrValue;

	//Player Decides
	char input = Input::Instance()->ReadInput();
	if (mPlyrCont == false && (input == WCAP || input == WLOW)){
		
		mPlayer.AddCard(mDeck.DealCard());
	}
	else if (mPlyrCont == false && (input == SCAP || input == SLOW)){
		// Changing this varible means that the player does not want to continue
		mPlyrCont = true;
	}
	else if (mPlyrCont == true){
		//do nothing, expicitly defining this means
		//that the computer can keep dealing cards
	}

	if (input != 0){
		//Dealer Decides
		int dlrValue = mDealer.DealerValueHand();
		if (mCompCont == false && dlrValue < 17){
			mDealer.AddCard(mDeck.DealCard());
		}
		else if (mCompCont = false && dlrValue >= 17){
			// Changing this varible means that the dealer does not want to continue
			mCompCont = true;
		}
		else if (mCompCont == true){
			//do nothing
		}
	}

	if (mCompCont || mPlyrCont){		// Ends round
		mStage = ACEDECIDE;
		plyrValue = mPlayer.PlayerValueHand();
		compValue = mDealer.DealerValueHand();
		Winner(compValue, plyrValue);
		mStage = WINNER;
	}

}

// Decides the win condition
void PlayState::Winner(int cValue, int pValue){

	// Get Hand values and sizes
	int compValue = cValue;
	int plyrValue = pValue;
	int plyrSize = mPlayer.GetCardCount();
	int compSize = mDealer.GetCardCount();
	
	if (plyrValue <= 21 && plyrSize == 5){
		mWinCon = FIVECARDCHARLIE;
	}
	else if (plyrValue > 21 && compValue > 21){
		mWinCon = BOTHBUST;
	}
	else if (plyrValue > 21 && compValue <= 21){				
		mWinCon = YOUBUST;
	}
	else if (plyrValue <= 21 && compValue > 21){
		mWinCon = DEALERBUST;
	}
	else if (plyrValue == 21 && compValue == 21){
		if (plyrSize < compSize){
			mWinCon = BOTH21YOU;
		}
		else if (plyrSize > compSize){
			mWinCon = BOTH21COMP;
		}
		else {
			mWinCon = BOTH21TIE;
		}
	}
	else if (plyrValue < 21 && compValue == 21 ){	
		mWinCon = DEALER21;
	}
	else if (compValue < 21 && plyrValue == 21){
		mWinCon = YOU21;
	}
	else if (compValue < plyrValue){
		mWinCon = YOUWIN;
	}
	else if (compValue > plyrValue){
		mWinCon = DEALERWIN;
	}
	else if (compValue == plyrValue){
		if (plyrSize < compSize){
			mWinCon = YOUTIE;
		}
		else if(plyrSize > compSize) {
			mWinCon = DEALERTIE;
		}
		else{
			mWinCon = TIE;
		}
	}
}

// Resets the game
void PlayState::Reset(){

	//Reset hands and continue decisions
	mPlayer.ClearHand();
	mDealer.ClearHand();
	mPlyrCont = false;
	mCompCont = false;
	

	int input = Input::Instance()->ReadInput();
	if (input == WCAP || input == WLOW){		// Resets game
		mStarted = false;
		mStage = DEALFIRST;
	}
	else if(input == SCAP || input == SLOW){	// Changes state to main menu
		mStage = DEALFIRST;
		Game::Instance()->SetState(MainMenu::Instance());
	}
	else if (input == 0){
		//do nothing
	}
}