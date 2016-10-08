#pragma once

#include "Engine.h"
#include "Grid.h"

class MyGameEngine : public GameEngine {
	//to see what should I do for chess table	
	Grid * grid;

public:
	MyGameEngine(Grid * grid_):grid(grid_) {};

	virtual void idle();
};