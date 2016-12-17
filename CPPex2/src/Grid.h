#pragma once
#include "GraphicPrimitives.h"
#include "Turn.h"

class Grid {

public:
	Grid(int n_ = 10, int m_ = 10) :
		n(n_),
		m(m_),
		grid(n, Row(m)),
		squareSize(0.2f),
		turnArray(turnLimit)
	{
		initGrid();
	};
	// NxM matrix
	int n, m;
	float squareSize;
	int turnLimit = 10;

	enum CreatureType {
		NONE,
		TURN,
		ROAD,
		TREE,
		ROCK
	};
	//type of Matrix using vectors source::cppref
	typedef std::vector<CreatureType> Row;
	typedef std::vector<Row> Matrix;
	Matrix grid;

	std::vector<Turn> turnArray;

	void initGrid();

	CreatureType getEl(int i, int j);
	bool checkNoneCase(int i, int j);
	void addTurnPlaces(int i, int j);
	bool addNewTurn(int i, int j);
	void draw();

};