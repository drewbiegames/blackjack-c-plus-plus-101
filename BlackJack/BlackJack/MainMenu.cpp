#include "MainMenu.h"

#include "ScreenHandler.h"
#include "PlayState.h"
#include "InfoMenu.h"
#include "Input.h"
#include "Card.h"

// sets menu options
MainMenu::MainMenu(){
	mMenuOption[0] = "-  Play  -";
	mMenuOption[1] = "-  Info  -";
	mMenuOption[2] = "-  Exit  -";
}

// Updates variables in MainMenu state
void MainMenu::Update(){

	// Ensures selected menu item is highlighted with Arrows
	PlaceMenuPointer();
	
	// Lets loop continue but waits for input
	KeyType input = Input::Instance()->ReadInput();

	if (input == WCAP || input == WLOW){		// Key Input W, move selection up
		mSelected--;
		mSelected = NumLoop(mSelected, 0, 2);
	}
	else if (input == SCAP || input == SLOW){	// Key Input S, move selection down
		mSelected++;
		mSelected = NumLoop(mSelected, 0, 2);
	}
	else if (input == ENTER) {					// Key Input Enter, actions selected option
		switch (mSelected){
			case 0:								// Switches to Play state 
				Game::Instance()->SetState(PlayState::Instance());
				break;
			case 1:								// Switches to Info state.
				Game::Instance()->SetState(InfoMenu::Instance());
				break;
			case 2:								// Exits Program
				Game::Instance()->ShutDown();
				break;
		}
	}
}

// Draws state to screen
void MainMenu::Draw(){
	ScreenHandler::Instance()->ClearBuffer();

	// Draw Menu
	ScreenHandler::Instance()->SetCharacter(12, 4, "Blackjack!");
	ScreenHandler::Instance()->SetCharacter(12, 7, mMenuOption[0]);
	ScreenHandler::Instance()->SetCharacter(12, 9, mMenuOption[1]);
	ScreenHandler::Instance()->SetCharacter(12, 11, mMenuOption[2]);
	ScreenHandler::Instance()->SetCharacter(8, 14, "by ShadaySyntaxGames");

	// Draw Menu Instructions
	ScreenHandler::Instance()->SetCharacter(9, 17, "Up (W)   Down (S)");

	// Draw Rectangle
	RectangleI rect;
	rect.Height = 20;
	rect.Width = 36;
	rect.StartX = 0;
	rect.StartY = 0;
	ScreenHandler::Instance()->DrawRectangle(rect);

	ScreenHandler::Instance()->SwapToBuffer();
}

// Place the menu option pointer
void MainMenu::PlaceMenuPointer(){
	for (int n = 0; n < 3; n++){
		mMenuOption[n][1] = ' ';
		mMenuOption[n][8] = ' ';
	}
	mMenuOption[mSelected][1] = '>';
	mMenuOption[mSelected][8] = '<';
}

// Loops Number round, used for menu selection
unsigned int MainMenu::NumLoop(int x, int top, int btm){
	if (x > btm){
		x = top;
	} 
	else if (x < top){
		x = btm;
	}
	else {
		x = x;
	}
	return x;
}