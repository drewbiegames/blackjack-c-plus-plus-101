#ifndef INPUT_H
#define INPUT_H

#include "KeyType.h"

// Input handler - Singleton
class Input{
public:
	KeyType ReadInput();					// Gets input without making loops wait
	
	//Singleton Design Pattern Begin
	//Only one exists in the program
	Input(const Input&){}					//copy construstor
	Input& operator = (const Input&){}		//assignment operator
	static Input* Instance(){				//Access function
		static Input input;
		return &input;
	}
	//Singleton Design Pattern End

private:
	Input(){};								//Constructor private because this is a singleton class
};



#endif