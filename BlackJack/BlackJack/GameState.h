#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "ScreenHandler.h"

// GameState Template class
class GameState{
public:
	virtual ~GameState(){}  
	virtual void Update(){} 
	virtual void Draw(){}
private:

};

#endif