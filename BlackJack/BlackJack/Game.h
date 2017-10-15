#ifndef GAME_H
#define GAME_H

#include "GameState.h"

class Game {
public:	
	void GameLoop();						//loops current states Update and Run functions
	void SetState(GameState* x);			//changes the state
	void ShutDown();						//Sets running to false, this will end the game loop

	//Singleton Design Pattern Begin
	//Only one exists in the program
	Game(const Game&){}						//copy constructor
	Game& operator = (const Game&){}		//assignment operator
	static Game* Instance(){ 
		static Game game; 
		return &game; 
	}
	//Singleton Design Pattern End

protected:
	GameState* mCurrentState;				
	bool mRunning = true;
private:
	Game();									//Constructor private because this is a singleton class
	void Update();							//Runs the current states update function
	void Draw();							//Runs the current states draw function
};

#endif