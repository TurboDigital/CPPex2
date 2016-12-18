#pragma once

#include "Engine.h"
#include "Grid.h"
#include "TurnStorage.h"
#include "MonstreStorage.h"

class MyGameEngine : public GameEngine {
	
	Grid * grid;
	TurnStorage * turnStorage;
	MonstreStorage * monstreStorage;

public:
	MyGameEngine(Grid * grid_, TurnStorage * turnStorage_, MonstreStorage * monstreStorage_):
		grid(grid_),
		turnStorage(turnStorage_),
		monstreStorage(monstreStorage_)
		{};

	virtual void idle();
};