#pragma once
#include "Engine.h"
#include "Grid.h"

class MyControlEngine : public ControlEngine {

	Grid * grid;

public:
	MyControlEngine(Grid * grid_):grid(grid_) {};

	virtual void MouseCallback(int button, int state, int x, int y);
	virtual void MotionCallback(int x, int y);

};