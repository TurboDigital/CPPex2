#pragma once
class Turn {
public:
	Turn(int iPos,int jPos) :
		i(iPos),
		j(jPos),
		virtualX(0.0f),
		virtualY(0.0f)
	{};

	virtual ~Turn() {};

	int i, j;
	float virtualX, virtualY;

	int getI();
	int getJ();
	void setXY(float x, float y);

};