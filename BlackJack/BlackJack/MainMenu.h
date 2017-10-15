#ifndef MAINMENU_H
#define MAINMENU_H

#include "Game.h"
#include "GameState.h"

#include <string>

// Main Menu Game State - Singleton
class MainMenu : public GameState{
public:
	
	virtual ~MainMenu(){}

	void Update() override;							// Updates variables in the state
	void Draw() override;							// Draws the state to the screen

	void PlaceMenuPointer();						// Resets the menu option pointer
	unsigned int NumLoop(int x, int top, int btm);	// Loops a number round, used for menu selection loop 

	//Singleton Design Pattern Begin
	//Only one exists in the program
	MainMenu(const MainMenu&){}						// Copy Constructor	
	MainMenu& operator = (const MainMenu&){}		// Assginment Operator
	static MainMenu* Instance(){					// Access Function
		static MainMenu menu;
		return &menu;
	}
	//Singleton Design Pattern End

private:
	
	MainMenu();										//Constructor private because this is a singleton class

	std::string mMenuOption[3];						// The output for each menu option
	int mSelected = 0;								// The currently selected object
};


#endif