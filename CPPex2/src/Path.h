#pragma once
#include "Config.h"

class Path {
public:
	Path()
	{};

	virtual ~Path() {};

	//TODO read from file
	int paths = 5;
	int path[12] = { 0,4,5,4,5,7,12,7,12,2,2,2 };

	float getStartX();
	float getStartY();

};