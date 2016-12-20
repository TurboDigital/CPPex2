#pragma once
#include "GraphicPrimitives.h"
#include "Path.h"

class Monstre {
	int life, n, m;
	float x, y, vx, vy, r, g, b, speed;
	Path * path;
public:
	Monstre(Path * path_, float xPos, float yPos, int monsterLife, float speed_, int n_, int m_, float r_, float g_, float b_) :
		path(path_),
		x(xPos),	y(yPos),
		vx(0.0f),	vy(0.0f),
		speed(speed_),
		n(n_),	m(m_),
		r(r_),	g(g_),	b(b_),
		life(monsterLife) {};

	virtual ~Monstre() {};

	//int paths = 5;
	//int path[12] = { 0,4,5,4,5,7,12,7,12,2,2,2 };
	int lines = 0;
	bool change = false;


	float squareSizeX = (float)(2.0 / n); //to check later if the frame is not a square
	float squareSizeY = (float)(2.0 / m);

	void takeDamage(int damage);

	void draw();
	void move();
};
