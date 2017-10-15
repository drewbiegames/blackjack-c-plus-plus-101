#ifndef SCREENHANDLER_H
#define SCREENHANDLER_H

#include <string>
#include <windows.h>
#include "Rectangle.h"

// Screen Handler, using double buffers - Singleton
class ScreenHandler {
public:
	void SetUpScreen();									//initialise the screen settings
	
	void SwapToBuffer();								//Changes the characters on the screen
	void SetCharacter(int x, int y, char c);			//changes characters in the buffer, character
	void SetCharacter(int x, int y, std::string s);		//Changes characters in the buffer, strings
	void ClearBuffer();

	void DrawRectangle(RectangleI rect);				//Changes the character in the back buffer to draw a rectangle
	void DrawRectangle(int RectX, int RectY, int RectW, int RectH);
	
	//Singleton Design Pattern Begin
	//Only one exists in the program
	ScreenHandler(const ScreenHandler&);				//copy construstor
	ScreenHandler& operator = (const ScreenHandler&);	//assignment operator
	static ScreenHandler* Instance(){					//Access function
		static ScreenHandler screen;
		return &screen;
	}
	//Singleton Design Pattern End

private:
	ScreenHandler(){};									//Constructor private because this is a singleton class
	void ChangeCharacter(int x, int y, char c);

	void SetPreviousScreen();
	void SetNextScreen();
	
	char mFrontBuffer[20][36];							//Used for double buffering
	char mBackBuffer[20][36];

	

	HANDLE handle;
	CONSOLE_CURSOR_INFO cursor;
	COORD coord;

};

#endif