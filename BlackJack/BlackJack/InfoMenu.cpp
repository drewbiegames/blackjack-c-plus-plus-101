#include "InfoMenu.h"

#include "MainMenu.h"
#include "ScreenHandler.h"
#include "Input.h"
#include "Game.h"

InfoMenu::InfoMenu(){

}

// Updates variables in the state
void InfoMenu::Update(){
	int input = Input::Instance()->ReadInput();

	if (input == QCAP || input == QLOW){		// Q pressed, goes back to main menu
		Game::Instance()->SetState(MainMenu::Instance());
	}
	else if (input == WCAP || input == WLOW){	// W pressed, goes to next page
		if (mPage == RULES) mPage = CHARLIE;
		else if (mPage == CHARLIE) mPage = RULES;
	}
}

// Draws state to screen
void InfoMenu::Draw(){
	ScreenHandler::Instance()->ClearBuffer();

	if (mPage == RULES){						// Displays rules page
		ScreenHandler::Instance()->SetCharacter(6, 1, "The Rules of Blackjack");
		ScreenHandler::Instance()->SetCharacter(0, 2, "The aim of blackjack is to be dealt cards ");
		ScreenHandler::Instance()->SetCharacter(0, 3, "and get the closest to 21 ");
		ScreenHandler::Instance()->SetCharacter(0, 4, "without going over, or BUST.");
		ScreenHandler::Instance()->SetCharacter(0, 6, "At the start you are dealt 2 cards.");
		ScreenHandler::Instance()->SetCharacter(0, 7, "Each turn you will get a choice to ");
		ScreenHandler::Instance()->SetCharacter(0, 8, "HIT; get dealt another card; or ");
		ScreenHandler::Instance()->SetCharacter(0, 9, "STAND; to stay with your current ");
		ScreenHandler::Instance()->SetCharacter(0, 10, "hand.");
		ScreenHandler::Instance()->SetCharacter(5, 12, "The Values of the Cards");
		ScreenHandler::Instance()->SetCharacter(1, 13, "King, Queen and Jack are 10.");
		ScreenHandler::Instance()->SetCharacter(1, 14, "Ace can be either 1 or 11.");
		ScreenHandler::Instance()->SetCharacter(1, 15, "All other cards are face value.");
	}
	if (mPage == CHARLIE){						// Displays Charlie page
		ScreenHandler::Instance()->SetCharacter(6, 1, "The Five Card Charlie.");
		ScreenHandler::Instance()->SetCharacter(0, 3, "If your hand total is less than 21 ");
		ScreenHandler::Instance()->SetCharacter(0, 4, "and you have 5 cards in your hand");
		ScreenHandler::Instance()->SetCharacter(0, 5, "then you have got a Five Card ");
		ScreenHandler::Instance()->SetCharacter(0, 6, "Charlie and win that round.");
	}

	// Displays Info Menu instructions
	ScreenHandler::Instance()->SetCharacter(2, 19, "Main Menu (Q)       Next (W)");

	ScreenHandler::Instance()->SwapToBuffer();
}