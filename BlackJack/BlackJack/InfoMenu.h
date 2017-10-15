#ifndef INFOMENU_H
#define INFOMENU_H

#include "GameState.h"

enum page {
	RULES,
	CHARLIE
};

// Info Menu Game State - Singleton
class InfoMenu : public GameState{
public:
	
	~InfoMenu(){}

	void Update() override;						// Updates variables in the state
	void Draw() override;						// Draws the state to the screen

	//Singleton Design Pattern Begin
	//Only one exists in the program
	InfoMenu(const InfoMenu&){}					// Copy Constructor
	InfoMenu& operator = (const InfoMenu&){}	// Assginment Operator
	static InfoMenu* Instance(){				// Access Function
		static InfoMenu info;
		return &info;
	}
	//Singleton Design Pattern End

private:
	InfoMenu();									//Constructor private because this is a singleton class

	int mPage = RULES;							//Current Page of the instructions

};

#endif