#include "Game.h"
#include <sstream>
#include <string.h>

void Game::checkNoneCaseAndAddTurn(int i, int j) {
	if (i >= 0 && j <= m && i < 10 && j >= 0) {
		if (grid[i][j] == NONE || grid[i][j] == MAIN_MENU) {
			grid[i][j] = TURN;
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
			if (objet == MAIN_MENU || objet == TURN)
				GraphicPrimitives::drawFillRect2D(x + (i*squareSizeX), y - (j*squareSizeY), squareSizeX, squareSizeY, 0.2f, 0.2f, 0.4f);
			if (objet == BUY_TURN)
				GraphicPrimitives::drawFillRect2D(x + (i*squareSizeX), y - (j*squareSizeY), squareSizeX, squareSizeY, 0.8f, 0.4f, 0.8f);
			if (objet == NONE || (objet == BOOST_UP && !clicked))
				GraphicPrimitives::drawFillRect2D(x + (i*squareSizeX), y - (j*squareSizeY), squareSizeX, squareSizeY, 0.21f, 0.55f, 0.55f);
			if (objet == BOOST_UP && clicked)
				GraphicPrimitives::drawFillRect2D(x + (i*squareSizeX), y - (j*squareSizeY), squareSizeX, squareSizeY, 0.60f, 0.80f, 0.19f);
		}
	}
	char pickGold[20];
	sprintf_s(pickGold, "Gold %d", gold);
	
	GraphicPrimitives::drawText2D(pickGold, .45f, .6f, 1.0f, .84f, .0f);
	GraphicPrimitives::drawText2D("BUY TURN (50g)", .45f, .3f, 1.0f, .96f, .93f);
	

	char buffer[30], chapter[30];
	sprintf_s(buffer, "%d lives", lifes);
	sprintf_s(chapter, "Chapter %d Wave %d", currentChapter + 1, level);
	GraphicPrimitives::drawText2D(buffer, .7f, .8f, 0.33f, .33f, .33f);
	GraphicPrimitives::drawText2D(chapter, .45f, .9f, 0.69f, .13f, .13f);


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
	char buffer[20], buffer1[20], buffer2[30];
	if (level <= 5) {
		sprintf_s(buffer, "Wave %d complete", level);
		sprintf_s(buffer1, "CHAPTER %d ", currentChapter + 1);
		sprintf_s(buffer2, "Next Wave: Press N ");
	}
	else{
		sprintf_s(buffer, "CHAPTER %d complete", currentChapter + 1);
		sprintf_s(buffer1, "");
		sprintf_s(buffer2, "Continue: Press N");
	}
	GraphicPrimitives::drawFillRect2D(-1.0f, -1.0f, 2.0f, 2.0f, 0.2f, 0.2f, 0.4f, 1.0f);
	GraphicPrimitives::drawText2D(buffer1, -0.3f, 0.4f, .66f, .66f, .66f);
	GraphicPrimitives::drawText2D(buffer, -0.3f, 0.3f, .66f, .66f, .66f);
	GraphicPrimitives::drawText2D(buffer2, -0.3f, 0.2f, 0.62f, .32f, .17f);
}

void Game::gameOverDraw() {
	GraphicPrimitives::drawFillRect2D(-1.0f, -1.0f, 2.0f, 2.0f, 0.2f, 0.2f, 0.4f, 1.0f);
	GraphicPrimitives::drawText2D("GAME OVER", -0.2f, 0.3f, 1.0f, .0f, .0f);
	GraphicPrimitives::drawText2D("Restart Game: Press R", -0.3f, 0.2f, 0.62f, .32f, .17f);
	GraphicPrimitives::drawText2D("Quit Game: Press Q", -0.3f, 0.1f, 0.62f, .32f, .17f);
}
void Game::gameWinDraw() {
	char buffer[20], buffer1[20], buffer2[30];
	sprintf_s(buffer, "Dev: Cociu Victor");
	sprintf_s(buffer1, "Congrats you won!");
	sprintf_s(buffer2, "Main menu: Press R");
	GraphicPrimitives::drawFillRect2D(-1.0f, -1.0f, 2.0f, 2.0f, 0.2f, 0.2f, 0.4f, 1.0f);
	GraphicPrimitives::drawText2D(buffer1, -0.3f, 0.4f, .66f, .66f, .66f);
	GraphicPrimitives::drawText2D(buffer, -0.3f, 0.3f, .66f, .66f, .66f);
	GraphicPrimitives::drawText2D(buffer2, -0.3f, 0.2f, 0.62f, .32f, .17f);
}

void Game::drawSelectedInfo(int level_, int attack_, int attackRate_) {
	char level[20];
	char attack[20];
	char rate[20];
	sprintf_s(level, "Level %d", level_);
	sprintf_s(attack, "Attack %d", attack_);
	sprintf_s(rate, "Rate %d", attackRate_);
	GraphicPrimitives::drawText2D("UPGRADE (30g)", .45f, -0.1f, 1.0f, .96f, .93f);
	GraphicPrimitives::drawText2D(level, .65f, -0.2f, 1.0f, .96f, .93f);
	GraphicPrimitives::drawText2D(attack, .65f, -0.3f, 1.0f, .96f, .93f);
	GraphicPrimitives::drawText2D(rate, .65f, -0.4f, 1.0f, .96f, .93f);
}

void Game::drawSelected() {
	float rx = selectedXPos;
	float ry = selectedYPos;
	GraphicPrimitives::drawFillRect2D(rx, ry, (float)(2.0 / n), (float)(2.0 / m), 1.0f, 0.0f, 1.0f);
}
void Game::setStartMenu() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(i>=10)grid[i][j] = NONE;
			else grid[i][j] = MAIN_MENU;
		}
	}
	grid[11][5] = BUY_TURN;
	grid[10][8] = BOOST_UP;
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
	nextLevelMenu = false;
	setStartMenu();
	if (!gameStarted) {
		gameStarted = true;
		chapterEnded = false;
		currentChapter = 0;
		level = 1;
	}
	if (level == 6) {
		chapterEnded = true;
		nextLevelMenu = false;
		level = 1;
		currentChapter++;
	}
	if (currentChapter == MAX_CHAPTER) {
		gameWin = true;// you won
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
	gameStarted = false;
	pause = false;
	gameOver = false;
	chapterEnded = false;
	nextLevelMenu = false;
	gameWin = false;
	delete wave;
	wave = NULL;
	level = 1;
	currentChapter = 0;
	lifes = 20;
	setStartMenu();
	reloadCurrentPath();
	gold = START_GOLD;
}