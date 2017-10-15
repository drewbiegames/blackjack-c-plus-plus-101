#include "ScreenHandler.h"

#include <stdlib.h>

void ScreenHandler::SetUpScreen(){
	system("Color F0");						//sets colours

	SetConsoleTitle(L"Blackjack");		

	HWND console = GetConsoleWindow();		//Getting handle for window
	RECT ConsoleRect;						//Store window bounds
	GetWindowRect(console, &ConsoleRect);	//Get window bounds and store in ConsoleRect

	handle = GetStdHandle(STD_OUTPUT_HANDLE);	//get input handle

	GetConsoleCursorInfo(handle, &cursor);	//get cursor info
	cursor.bVisible = false;				//sets cursor to invisible
	SetConsoleCursorInfo(handle, &cursor);	//sets the cursor info

	//Resizes window
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 325, 310, TRUE);
	
	
	COORD consoleSize;						//used to set console buffer size
	consoleSize.X = 36;
	consoleSize.Y = 21;

	//sets the buffer size
	SetConsoleScreenBufferSize(handle, consoleSize); 

	SetPreviousScreen();
	SetNextScreen();
}

void ScreenHandler::SwapToBuffer(){		//flipping buffers
	for (int y = 0; y < 20; y++){
		for (int x = 0; x < 36; x++){
			if (mFrontBuffer[y][x] != mBackBuffer[y][x]){
				ChangeCharacter(x, y, mBackBuffer[y][x]);
				mFrontBuffer[y][x] = mBackBuffer[y][x];
			}
		}
	}
}

void ScreenHandler::SetCharacter(int x, int y, char c){		//changes one character in the back buffer
	mBackBuffer[y][x] = c;
}

void ScreenHandler::SetCharacter(int x, int y, std::string s){	//change the characters of the back buffer to include a string
	for (unsigned int d = 0; d < s.size(); d++){
		SetCharacter(x + d, y, s[d]);							//calls the set character function for a single character for each char in the string array
	}
}

void ScreenHandler::ClearBuffer(){	//clear the back buffer for new buffer to be set
	for (int y = 0; y < 20; y++){
		for (int x = 0; x < 36; x++){
			SetCharacter(x, y, ' ');
		}
	}
}

void ScreenHandler::DrawRectangle(RectangleI rect){
	
	char cornerOne = '\\';
	char cornerTwo = '/';
	char horizonal = '-';
	char vertical = '|';

	for (int h = 0; h < rect.Height; h++){			//along height (y axis)
		for (int w = 0; w < rect.Width; w++){		//along width  (x axis)
			if (h == 0){
				if (w == 0){
					//top left corner
					SetCharacter(rect.StartX + w, rect.StartY + h, cornerOne);
				}
				else if (w == (rect.Width-1)){
					//top right corner
					SetCharacter(rect.StartX + w, rect.StartY + h, cornerTwo);
				}
				else{
					//top row
					SetCharacter(rect.StartX + w, rect.StartY, horizonal);
				}
			}
			else if (h == (rect.Height - 1)){
				if (w == 0){
					//bottom left corner
					SetCharacter(rect.StartX + w, rect.StartY + h, cornerTwo);
				}
				else if (w == (rect.Width - 1)){
					//bottom right corner
					SetCharacter(rect.StartX + w, rect.StartY + h, cornerOne);
				}
				else{
					//bottom row
					SetCharacter(rect.StartX + w, rect.StartY + h, horizonal);
				}
			}
			else if ((h >= 1 && h <= (rect.Height - 1)) && (w == 0) || (w == (rect.Width - 1))){
				//side columns
				SetCharacter(rect.StartX + w, rect.StartY + h, vertical);
			}
		}
	}
}

void ScreenHandler::DrawRectangle(int rectX, int rectY, int rectW, int rectH){

	char cornerOne = '\\';
	char cornerTwo = '/';
	char horizonal = '-';
	char vertical = '|';

	for (int h = 0; h < rectH; h++){
		for (int w = 0; w < rectW; w++){
			if (h == 0){
				if (w == 0){
					//top left corner
					SetCharacter(rectX + w, rectY + h, cornerOne);
				}
				else if (w == (rectW - 1)){
					//top right corner
					SetCharacter(rectX + w, rectY + h, cornerTwo);
				}
				else{
					//top row
					SetCharacter(rectX + w, rectY, horizonal);
				}
			}
			else if (h == (rectH - 1)){
				if (w == 0){
					//bottom left corner
					SetCharacter(rectX + w, rectY + h, cornerTwo);
				}
				else if (w == (rectW - 1)){
					//bottom right corner
					SetCharacter(rectX + w, rectY + h, cornerOne);
				}
				else{
					//bottom row
					SetCharacter(rectX + w, rectY + h, horizonal);
				}
			}
			else if ((h >= 1 && h <= (rectH - 1)) && (w == 0) || (w == (rectW - 1))){
				//side columns
				SetCharacter(rectX + w, rectY + h, vertical);
			}
		}
	}
}

void ScreenHandler::ChangeCharacter(int x, int y, char c){		//Prints the character to the screen
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(handle, coord);	//moves cursor to the coordinates
	printf("%c", c);							//prints character to 
}

void ScreenHandler::SetPreviousScreen(){	//sets default front buffer
	for (int y = 0; y < 20; y++){
		for (int x = 0; x < 36; x++){
			mFrontBuffer[y][x] = ' ';
		}
	}
}

void ScreenHandler::SetNextScreen(){		//sets default back buffer
	for (int y = 0; y < 20; y++){
		for (int x = 0; x < 36; x++){
			mBackBuffer[y][x] = ' ';
		}
	}
}


