#pragma once
#include "GraphicPrimitives.h"

class Bullet {
	float vx, vy;
	float startX, startY, distance, movedX, movedY;
public:
	Bullet(float x_, float y_, float vx_, float vy_, float stX_, float stY_, float distance_, float size_, int damage_):
		x(x_),	y(y_),
		vx(vx_),	vy(vy_),
		size(size_),
		startX(stX_),	startY(stY_),	distance(distance_),	movedX(0.0f),	movedY(0.0f),
		dead(false),
		damage(damage_)
	{};
	float x, y, size;
	int damage;
	bool dead;

	void draw();
	void move();
	
};