#pragma once
#include "GraphicPrimitives.h"
#include "Config.h"
#include "Wave.h"
#include "Path.h"
#include "Monstre.h"
#include "LoadGame.h"
#include <cstdio>

class Game {
public:
	Game(LoadGame * load_) :
		window_width(WINDOW_WIDTH),
		window_height(WINDOW_HEIGHT),
		pause(false), gameOver(false), gameStarted(false), nextLevelMenu(false), chapterEnded(false), gameWin(false),
		countMonstres(0),
		level(START_LEVEL), currentChapter(START_CHAPTER),
		wave(NULL), loadGame(load_),
		n(N), m(M),
		grid(n, Row(m)),
		selectedXPos(0.0f), selectedYPos(0.0f),
		isSelected(false), lifes(GAME_LIVES),
		clickTowerI(-1), clickTowerJ(-1), clicked(false),
		gold(START_GOLD)
	{}

	Wave * wave;
	LoadGame * loadGame;

	int window_width, window_height;
	int countMonstres, lifes;
	unsigned int currentChapter, level, gold;
	bool pause, gameStarted, chapterEnded, gameOver, nextLevelMenu, gameWin;

	int clickTowerI, clickTowerJ;
	bool clicked;

	void draw();
	void pauseDraw();
	void startDraw();
	void gameOverDraw();
	void gameWinDraw();
	void drawSelected();
	void drawSelectedInfo(int level_, int attack_, int attackRate_);

	void levelComplete();

	//GRID imports

	enum CreatureType {
		NONE,
		TURN,
		ROAD,
		BUY_TURN,
		MAIN_MENU,
		BOOST_UP,
		BOOST_DOWN
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

	//void initGrid();

	CreatureType getEl(int i, int j);
	void checkNoneCaseAndAddTurn(int i, int j);
	void addTurnPlaces(int i, int j);

	//void loadLevel(int level_);
	void setStartMenu();

	MonstreStorage::Storage getMonstersAround(int i, int j);
	void dealDamageToAnMonsterFromWave(Monstre * monstre_, int damage_);

	void goToNextLevelDraw();
	bool loadNextLevel();
	void loadPath(int * path, int pahts_);
	Path * currentPath();
	void restartGame();
	void reloadCurrentPath();
};