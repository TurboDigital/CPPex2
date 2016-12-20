#pragma once
#include "GraphicPrimitives.h"
#include "Config.h"
#include "Wave.h"
#include "Path.h"
#include "Monstre.h"
#include "Turn.h"
#include "TurnStorage.h"


class Game {

public:
	Game(Path * path_) :
		window_width(WINDOW_WIDTH),
		window_height(WINDOW_HEIGHT),
		pause(false),	gameOver(false),	gameStarted(false),
		countMonstres(0),
		level(START_LEVEL),
		wave(NULL),	path(path_), 
		n(N),	m(M),
		grid(n, Row(m)),
		virtualTurnStorage(0),
		selectedXPos(0.0f),	selectedYPos(0.0f),
		isSelected(false)
	{}

	Wave * wave;
	Path * path;

	int window_width;
	int window_height;
	int countMonstres;
	int level;
	bool pause;
	bool gameStarted;
	bool gameOver;

	void draw();
	void pauseDraw();
	void startDraw();

	//GRID import

	TurnStorage virtualTurnStorage;

	enum CreatureType {
		NONE,
		TURN,
		ROAD,
		TREE,
		ROCK,
		BUY_TURN,
		MAIN_MENU
	};

	// NxM matrix
	int n, m;

	bool isSelected;
	float selectedXPos;
	float selectedYPos;

	//type of Matrix using vectors source::cppref
	typedef std::vector<CreatureType> Row;
	typedef std::vector<Row> Matrix;
	Matrix grid;

	void initGrid();

	CreatureType getEl(int i, int j);
	void checkNoneCaseAndAddTurn(int i, int j);
	void addTurnPlaces(int i, int j);

	void loadLevel(int level_);
	void setStartMenu();

};