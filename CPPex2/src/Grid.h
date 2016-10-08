#pragma once
#include "GraphicPrimitives.h"

class Grid {

public:
	Grid(int n_ = 10, int m_ = 10) :
		n(n_), 
		m(m_),
		grid(n,Row(m))
	{};

	int n, m;
	//std::vector<std::vector<int> >grid;
	typedef std::vector<int> Row;
	typedef std::vector<Row> Matrix;
	Matrix grid;

	int getEl(int i, int j);
	void setEl(int i, int j, int val);

	void draw();

};