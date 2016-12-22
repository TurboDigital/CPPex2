#pragma once
#include "GraphicPrimitives.h"
#include "Bullet.h"
#include "Game.h"
#include <vector>
#include <memory>


class Turn {

	Game * game;

public:
	Turn(Game * game_, int iPos,int jPos, int nN, int mM,float r_, float g_, float b_, float a_ = 1.0f) :
		game(game_),
		i(iPos),	j(jPos),
		n(nN),		m(mM),
		virtualX(0.0f),		virtualY(0.0f),
		r(r_),		g(g_),		b(b_),		a(a_),
		level(1),	levelMax(4),	freqMax(60),	turnAttack(40)
	{};

	virtual ~Turn() {};

	int fire_rate = 70;
	int freq = 0;
	int freqMax;
	unsigned int level, levelMax;
	int turnAttack;

	typedef std::vector<std::shared_ptr<Bullet>> Bullets;
	Bullets bullets;

	int i, j, n, m;
	float r, g, b, a;
	float virtualX, virtualY;

	int getI();
	int getJ();
	void setXY(float x, float y);

	int getLevel();
	int getAttackRate();
	int getAttack();

	void draw();
	void drawBorder();
	void attack();
	void updateLevel();

};