#include "Game.h"

Game::Game(){
	
}

//runs current states Update and Run function continuosly
void Game::GameLoop(){
	while (mRunning){
		Update();

		Draw();
	}
}

// Changes current state
void Game::SetState(GameState* x){
	
	if (x) mCurrentState = x;
	
	else Game::Instance()->ShutDown();
}

// Updates current state
void Game::Update(){
	mCurrentState->Update();
}

// Draws current state
void Game::Draw(){
	mCurrentState->Draw();
}

// Changes mRunning to false, this will shut the program down
void Game::ShutDown(){
	mRunning = false;
}