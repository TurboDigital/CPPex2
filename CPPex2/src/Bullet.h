#pragma once
#include "GraphicPrimitives.h"

class Bullet {
	float x, y, vx, vy, size;
	float destX, destY;
public:
	Bullet(float x_, float y_, float vx_, float vy_, float deX_, float deY_, float size_):
		x(x_),	y(y_),
		vx(vx_),	vy(vy_),
		size(size_),
		destX(deX_),	destY(deY_),
		dead(false)
	{};

	bool dead;

	void draw();
	void move();
	
};