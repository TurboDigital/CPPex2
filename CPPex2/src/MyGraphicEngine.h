#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "TurnStorage.h"
#include "MonstreStorage.h"
#include "Game.h"

class MyGraphicEngine:public GraphicEngine {
	
	TurnStorage * turnStorage;
	MonstreStorage * monstreStorage;
	Game * game;

public:
	MyGraphicEngine(TurnStorage * turnStorage_, MonstreStorage * monstreStorage_, Game * game_):
		turnStorage(turnStorage_),
		monstreStorage(monstreStorage_),
		game(game_)
		{}

	virtual void Draw();
};