#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Grid.h"
#include "TurnStorage.h"
#include "MonstreStorage.h"

class MyGraphicEngine:public GraphicEngine {
	
	Grid * grid;
	TurnStorage * turnStorage;
	MonstreStorage * monstreStorage;

public:
	MyGraphicEngine(Grid * grid_, TurnStorage * turnStorage_, MonstreStorage * monstreStorage_):
		grid(grid_),
		turnStorage(turnStorage_),
		monstreStorage(monstreStorage_)
		{}

	virtual void Draw();
};