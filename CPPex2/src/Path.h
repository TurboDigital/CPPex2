#pragma once
#include "Config.h"

class Path {
public:
	Path(int * path_, int paths_):
		path(path_),
		paths(paths_)
	{};

	virtual ~Path() {};

	int paths;
	int * path;

	float getStartX();
	float getStartY();

};