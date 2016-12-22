#pragma once
#include "Engine.h"
#include "TurnStorage.h"
#include "MonstreStorage.h"
#include "GameEventsObserver.h"
#include "Game.h"

class MyControlEngine : public ControlEngine {

	TurnStorage * turnStorage;
	GameEventsObserver * observer;
	Game * game;

public:
	MyControlEngine(TurnStorage * turnStorage_, Game * game_, GameEventsObserver * observer_):
		turnStorage(turnStorage_),
		observer(observer_),
		game(game_)
	{};

	virtual void MouseCallback(int button, int state, int x, int y);
	virtual void MotionCallback(int x, int y);
	virtual void KeyboardCallback(unsigned char key, int x, int y);


};