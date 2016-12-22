#pragma once

#include "Engine.h"
#include "TurnStorage.h"
#include "MonstreStorage.h"
#include "Game.h"
#include "GameEventsObserver.h"

class MyGameEngine : public GameEngine {
	
	TurnStorage * turnStorage;
	MonstreStorage * monstreStorage;
	Game * game;
	GameEventsObserver * observer;

public:
	MyGameEngine(TurnStorage * turnStorage_, MonstreStorage * monstreStorage_, Game * game_, GameEventsObserver * observer_):
		turnStorage(turnStorage_),
		monstreStorage(monstreStorage_),
		game(game_),
		observer(observer_)
		{};

	virtual void idle();
};