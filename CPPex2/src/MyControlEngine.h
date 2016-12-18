#pragma once
#include "Engine.h"
#include "Grid.h"
#include "TurnStorage.h"
#include "MonstreStorage.h"

class MyControlEngine : public ControlEngine {

	Grid * grid;
	TurnStorage * turnStorage;

public:
	MyControlEngine(Grid * grid_, TurnStorage * turnStorage_):
		grid(grid_),
		turnStorage(turnStorage_)
	{};

	virtual void MouseCallback(int button, int state, int x, int y);
	virtual void MotionCallback(int x, int y);

};