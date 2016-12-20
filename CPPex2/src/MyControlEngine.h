#pragma once
#include "Engine.h"
#include "Grid.h"
#include "TurnStorage.h"
#include "MonstreStorage.h"
#include "Game.h"

class MyControlEngine : public ControlEngine {

	TurnStorage * turnStorage;
	Game * game;

public:
	MyControlEngine(TurnStorage * turnStorage_, Game * game_):
		turnStorage(turnStorage_),
		game(game_)
	{};

	virtual void MouseCallback(int button, int state, int x, int y);
	virtual void MotionCallback(int x, int y);
	virtual void KeyboardCallback(unsigned char key, int x, int y);


};