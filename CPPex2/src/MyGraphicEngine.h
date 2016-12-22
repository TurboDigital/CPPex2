#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "TurnStorage.h"
#include "MonstreStorage.h"
#include "Game.h"
#include "GameEventsObserver.h"

class MyGraphicEngine:public GraphicEngine {
	
	TurnStorage * turnStorage;
	MonstreStorage * monstreStorage;
	GameEventsObserver * observer;
	Game * game;

public:
	MyGraphicEngine(TurnStorage * turnStorage_, MonstreStorage * monstreStorage_, Game * game_, GameEventsObserver * observer_):
		turnStorage(turnStorage_),
		monstreStorage(monstreStorage_),
		game(game_),
		observer(observer_)
		{}

	virtual void Draw();
};