#include "MainMenu.h"
#include "Game.h"

#include "ScreenHandler.h"


int main(){
	ScreenHandler::Instance()->SetUpScreen();
	
	Game::Instance()->SetState(MainMenu::Instance());
	
	Game::Instance()->GameLoop();

	return 0;
}