#pragma once
#include "Config.h"

class Path {
public:
	Path(int * path_, int paths_):
		path(path_),
		size(paths_)
	{};

	virtual ~Path() {};

	int size;
	int * path;

	float getStartX();
	float getStartY();

};