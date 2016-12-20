#pragma once

#include "Engine.h"
#include "Grid.h"
#include "TurnStorage.h"
#include "MonstreStorage.h"
#include "Game.h"

class MyGameEngine : public GameEngine {
	
	TurnStorage * turnStorage;
	MonstreStorage * monstreStorage;
	Game * game;

public:
	MyGameEngine(TurnStorage * turnStorage_, MonstreStorage * monstreStorage_, Game * game_):
		turnStorage(turnStorage_),
		monstreStorage(monstreStorage_),
		game(game_)
		{};

	virtual void idle();
};