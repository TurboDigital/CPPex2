#include "Game.h"
#include <sstream>
#include <string.h>

void Game::initGrid() {
	//TO-DO read from a file paths and path[N]
	int paths = 5;
	//int path[12] = { 0,4,5,4,5,7,12,7,12,2,2,2 };
	int lines = 0;
	for (int k = 0; k < paths; k++) {

		int startX = path->path[lines];
		int startY = path->path[lines + 1];
		int endX = path->path[lines + 2];
		int endY = path->path[lines + 3];

		if (startX == endX) {
			if (startX < endY) {
				for (startY; startY <= endY; startY++)
					grid[startY][startX] = ROAD;
			}
			else {
				for (startY; startY >= endY; startY--)
					grid[startY][startX] = ROAD;
			}
		}
		if (startY == endY) {
			if (startX < endX) {
				for (startX; startX <= endX; startX++)
					grid[startY][startX] = ROAD;
			}
			else {
				for (startX; startX >= endX; startX--)
					grid[startY][startX] = ROAD;
			}

		}
		lines += 2;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == ROAD) {
				addTurnPlaces(i, j);
			}
		}
	}

	grid[12][5] = BUY_TURN;

}

void Game::checkNoneCaseAndAddTurn(int i, int j) {
	if (i >= 0 && j <= m && i < 10 && j >= 0) {
		if (grid[i][j] == NONE || grid[i][j] == MAIN_MENU) {
			grid[i][j] = TURN;
			virtualTurnStorage.addTurn(std::make_shared<Turn>(Turn(j, i, n, m, 0.80f, 0.80f, 0.80f)));
		}
	}
}

void Game::addTurnPlaces(int i, int j) {
	checkNoneCaseAndAddTurn(i - 1, j - 1);
	checkNoneCaseAndAddTurn(i - 1, j);
	checkNoneCaseAndAddTurn(i - 1, j + 1);
	checkNoneCaseAndAddTurn(i, j - 1);
	checkNoneCaseAndAddTurn(i, j + 1);
	checkNoneCaseAndAddTurn(i + 1, j - 1);
	checkNoneCaseAndAddTurn(i + 1, j);
	checkNoneCaseAndAddTurn(i + 1, j + 1);
}

Game::CreatureType Game::getEl(int i, int j) {
	return grid[i][j];
}


void Game::draw() {
	
	//draw functions
	float squareSizeX = (float)(2.0 / n); //to check later if the frame is not a square
	float squareSizeY = (float)(2.0 / m);

	float x = -1.0f, y = 1.0f - squareSizeY; //start paint from left top corner
											 // y = 0.8f because GraphicPrimitives draw from left down corner
											 //draw the table
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Game::CreatureType objet = grid[i][j];
			if (objet == ROAD)
				GraphicPrimitives::drawFillRect2D(x + (i*squareSizeX), y - (j*squareSizeY), squareSizeX, squareSizeY, 0.4f, 0.4f, 0.4f);
			if (objet == MAIN_MENU || objet == TURN || objet == NONE)
				GraphicPrimitives::drawFillRect2D(x + (i*squareSizeX), y - (j*squareSizeY), squareSizeX, squareSizeY, 0.2f, 0.2f, 0.4f);
			if (objet == BUY_TURN)
				GraphicPrimitives::drawFillRect2D(x + (i*squareSizeX), y - (j*squareSizeY), squareSizeX, squareSizeY, 0.8f, 0.4f, 0.8f);

		}
	}
	//GraphicPrimitives::drawText2D("TT", 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);


	if (isSelected) {
		virtualTurnStorage.forEachDraw();

		float rx = selectedXPos;
		float ry = selectedYPos;
		std::printf("pos x = %lf pos y = %lf visual size = %d \n", rx, ry, virtualTurnStorage.getSize());
		GraphicPrimitives::drawFillRect2D(rx, ry, squareSizeX, squareSizeY, 1.0f, 0.0f, 1.0f);

	}


}


void Game::loadLevel(int level_) {
	if(level == 1)initGrid();
}

void Game::startDraw() {
	GraphicPrimitives::drawText2D("START GAME", 0.0f, 0.0f, 1.0f, .0f, .0f);
	std::printf("DRAW START\n");
}

void Game::pauseDraw() {
	GraphicPrimitives::drawText2D("PAUSED", 0.0f, 0.0f, 1.0f, .0f, .0f);
}

void Game::setStartMenu() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			grid[i][j] = MAIN_MENU;
		}
	}
}
