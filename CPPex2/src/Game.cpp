#include "Game.h"
#include <sstream>
#include <string.h>

void Game::checkNoneCaseAndAddTurn(int i, int j) {
	if (i >= 0 && j <= m && i < 10 && j >= 0) {
		if (grid[i][j] == NONE || grid[i][j] == MAIN_MENU) {
			grid[i][j] = TURN;
			//virtualTurnStorage.addTurn(std::make_shared<Turn>(Turn(j, i, n, m, 0.80f, 0.80f, 0.80f)));
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
	
	if (isSelected) {
		//virtualTurnStorage.forEachDraw();

		float rx = selectedXPos;
		float ry = selectedYPos;
		//std::printf("pos x = %lf pos y = %lf visual size = %d \n", rx, ry, virtualTurnStorage.getSize());
		GraphicPrimitives::drawFillRect2D(rx, ry, squareSizeX, squareSizeY, 1.0f, 0.0f, 1.0f);

	}

	char buffer[30];
	std::sprintf(buffer, "%d lives", lifes);
	GraphicPrimitives::drawText2D(buffer, .7f, .9f, 0.62f, .32f, .17f);


}

void Game::startDraw() {
	GraphicPrimitives::drawFillRect2D(-1.0f, -1.0f, 2.0f, 2.0f, 0.2f, 0.2f, 0.4f, 0.9f);
	GraphicPrimitives::drawText2D("Start Game: Press G", -0.3f, 0.3f, 0.9f, .6f, .1f);
	GraphicPrimitives::drawText2D("(to pause) : Press P", -0.3f, -0.2f, 0.9f, .6f, .1f);
	GraphicPrimitives::drawText2D("(to restart) : Press R", -0.3f, -0.1f, 0.9f, .6f, .1f);
	std::printf("DRAW START\n");
}

void Game::pauseDraw() {
	GraphicPrimitives::drawFillRect2D(-1.0f, -1.0f, 2.0f, 2.0f, 0.2f, 0.2f, 0.4f, 0.6f);
	GraphicPrimitives::drawText2D("PAUSED", -0.2f, 0.3f, 1.0f, .0f, .0f);
	GraphicPrimitives::drawText2D("Resume game: Press P", -0.2f, 0.2f, 0.62f, .32f, .17f);
}

void Game::goToNextLevelDraw() {
	char buffer[20];
	std::sprintf(buffer, "Level %d complete", level - 1);

	GraphicPrimitives::drawFillRect2D(-1.0f, -1.0f, 2.0f, 2.0f, 0.2f, 0.2f, 0.4f, 1.0f);
	GraphicPrimitives::drawText2D(buffer, -0.3f, 0.3f, 0.62f, .32f, .17f);
	GraphicPrimitives::drawText2D("Next Level: Press N", -0.3f, 0.2f, 0.62f, .32f, .17f);
}

void Game::gameOverDraw() {
	GraphicPrimitives::drawFillRect2D(-1.0f, -1.0f, 2.0f, 2.0f, 0.2f, 0.2f, 0.4f, 1.0f);
	GraphicPrimitives::drawText2D("GAME OVER", -0.2f, 0.3f, 1.0f, .0f, .0f);
	GraphicPrimitives::drawText2D("Restart Game: Press R", -0.3f, 0.2f, 0.62f, .32f, .17f);
	GraphicPrimitives::drawText2D("Quit Game: Press Q", -0.3f, 0.1f, 0.62f, .32f, .17f);
}

void Game::setStartMenu() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			grid[i][j] = MAIN_MENU;
		}
	}
	grid[12][5] = BUY_TURN;
	grid[12][6] = BUY_TURN;
	grid[12][7] = BUY_TURN;
}

MonstreStorage::Storage Game::getMonstersAround(int i, int j) {
	if (wave != NULL) {
		float squareSizeX = (float)(2.0 / n); //to check later if the frame is not a square
		float squareSizeY = (float)(2.0 / m);

		float squareX = -1.0f + squareSizeY * (j - 1);
		float squareY = 1.0f - squareSizeX * (i + 2);
		float squareWidth = squareSizeY * 3.0f;
		float squareHeight = squareSizeX * 3.0f;

		MonstreStorage::Storage result;

		for (int k = 0; k < wave->monstreStorage.getSize(); k++) {
			float monstreX = wave->monstreStorage.monstres[k].get()->getX();
			float monstreY = wave->monstreStorage.monstres[k].get()->getY();
			float monstreWidth = wave->monstreStorage.monstres[k].get()->getWidth();
			float monstreHeight = wave->monstreStorage.monstres[k].get()->getHeight();

			if (squareX < monstreX + monstreWidth && squareX + squareWidth > monstreX
				&& squareY < monstreY + monstreHeight && squareY + squareHeight > monstreY) {
				//add the monster
				result.push_back(wave->monstreStorage.monstres[k]);
			}

		}
		return result;
	}
	MonstreStorage::Storage result;
	return result;
	
}

void Game::dealDamageToAnMonsterFromWave(Monstre * monstre_, int damage_){
	wave->setDamage(monstre_, damage_);
}

void Game::levelComplete() {
	level++;
	delete wave;
	wave = NULL;
	std::printf("level complete");
	nextLevelMenu = true;
}

bool Game::loadNextLevel() {
	setStartMenu();
	if (!gameStarted) {
		gameStarted = true;
		chapterEnded = false;
		currentChapter = 0;
		level = 1;
	}
	if (level == 6) {
		chapterEnded = true;
		level = 1;
		currentChapter++;
	}
	if (currentChapter == MAX_CHAPTER) {
		gameOver = true;// you won
	}
	if (currentChapter < MAX_CHAPTER) {
		reloadCurrentPath();
		return true;
	}
	return false;

}

void Game::loadPath(int * path, int paths_) {
	int paths = paths_;
	int lines = 0;
	for (int k = 0; k < paths; k++) {

		int startX = path[lines];
		int startY = path[lines + 1];
		int endX = path[lines + 2];
		int endY = path[lines + 3];

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
	//add virtual turns around
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == ROAD) {
				addTurnPlaces(i, j);
			}
		}
	}

}

void Game::reloadCurrentPath(){
	loadPath(loadGame->loadedPaths[currentChapter].get()->path, loadGame->loadedPaths[currentChapter].get()->paths);
}

Path * Game::currentPath() {
	return loadGame->loadedPaths[currentChapter].get();
}


void Game::restartGame() {
	gameStarted = true;
	pause = false;
	gameOver = false;
	chapterEnded = false;
	level = 1;
	currentChapter = 0;
	lifes = 20;
	setStartMenu();
	reloadCurrentPath();
}