#pragma once
#include "GraphicPrimitives.h"
#include "Bullet.h"
#include <vector>
#include <memory>

class Turn {
public:
	Turn(int iPos,int jPos, int nN, int mM,float r_, float g_, float b_) :
		i(iPos),
		j(jPos),
		n(nN),
		m(mM),
		virtualX(0.0f),
		virtualY(0.0f),
		r(r_),
		g(g_),
		b(b_)
	{};

	virtual ~Turn() {};

	int fire_rate = 70;
	int freq = 0;

	typedef std::vector<std::shared_ptr<Bullet>> Bullets;
	Bullets bullets;

	int i, j, n, m;
	float r, g, b;
	float virtualX, virtualY;

	int getI();
	int getJ();
	void setXY(float x, float y);

	void draw();
	void attack();

};