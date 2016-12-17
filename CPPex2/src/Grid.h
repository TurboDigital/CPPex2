#pragma once
#include "GraphicPrimitives.h"
#include "Turn.h"
#include <memory>

class Grid {

public:
	Grid(int n_ = 10, int m_ = 10) :
		n(n_),
		m(m_),
		grid(n, Row(m)),
		squareSize(0.2f),
		turnStorage(),
		selectedXPos(0.0f),
		selectedYPos(0.0f),
		isSelected(false)
	{
		initGrid();
	};

	virtual ~Grid() {};
	
	enum CreatureType {
		NONE,
		TURN,
		ROAD,
		TREE,
		ROCK,
		BUY_TURN
	};

	// NxM matrix
	int n, m;
	float squareSize;

	bool isSelected;
	float selectedXPos;
	float selectedYPos;
	
	//type of Matrix using vectors source::cppref
	typedef std::vector<CreatureType> Row;
	typedef std::vector<Row> Matrix;
	Matrix grid;
	
	typedef std::vector<std::shared_ptr<Turn>> Turns;
	Turns turnStorage;

	void initGrid();

	CreatureType getEl(int i, int j);
	void checkNoneCaseAndAddTurn(int i, int j);
	void addTurnPlaces(int i, int j);
	bool addNewTurn(int i, int j);
	void draw();

	//insert new Turn in TurnStorage
	void storeTurn(std::shared_ptr<Turn> const& turn);

};