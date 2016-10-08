#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Grid.h"

class MyGraphicEngine:public GraphicEngine {
	
	Grid * grid;

public:

	MyGraphicEngine(Grid * grid_):grid(grid_){}

	virtual void Draw();
};