#include "MyControlEngine.h"
#include <math.h>
#include <string.h>

void MyControlEngine::MouseCallback(int button, int state, int x , int y) {
	//to do mouse clicks
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);

	//find the case [i][j] from grid: translation from the frame to Matrix
	int caseX = (unsigned int)trunc((game->m - (height - y) / (height / game->m)) - 1);
	int caseY = (unsigned int)trunc((game->n - (width - x) / (width / game->n)) - 1);
	if (caseX == -1)caseX = 0;

	Game::CreatureType caseType = game->getEl(caseY, caseX);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//TO DO: onClick and put turns
		//DONE
		if (caseType == Game::CreatureType::BUY_TURN) {
			game->isSelected = true;
			observer->refreshVirtual();
			observer->drawVirtual = true;
		}
		else if (caseType == Game::CreatureType::TURN) {
			if (turnStorage->exists(caseX, caseY)) {
				game->clickTowerI = caseX;
				game->clickTowerJ = caseY;
				game->clicked = true;
			}
			else {
				game->clicked = false;
			}
		}
		else if (caseType == Game::CreatureType::BOOST_UP && game->clicked) {
			if (game->gold >= 30) {
				turnStorage->upgradeTurn(game->clickTowerI, game->clickTowerJ);
				game->gold -= 30;
			}
		}
		else if (game->clicked) {
			game->clicked = false;
		}
	}
	if (state == GLUT_UP && game->isSelected) {
		
		if (caseType == Game::CreatureType::TURN) {
			if (game->gold >= 50) {
				turnStorage->addTurn(std::make_shared<Turn>(Turn(game, caseX, caseY, game->n, game->m, 1.0f, 0.0f, 1.0f)));
				game->gold -= 50;
			}
		}
		game->isSelected = false;
		observer->drawVirtual = false;
	}
}

void MyControlEngine::MotionCallback(int x, int y){

	//TO DO: onClick and put turns
	//DONE
	if (game->isSelected) {
		observer->drawVirtual = true;
		int width = glutGet(GLUT_WINDOW_WIDTH);
		int height = glutGet(GLUT_WINDOW_HEIGHT);

		float squareSizeX = (float)(2.0 / game->n); //to check later if the frame is not a square
		float squareSizeY = (float)(2.0 / game->m);

		int caseX = (unsigned int)trunc((game->m - (height - y) / (height / game->m)) - 1);
		int caseY = (unsigned int)trunc((game->n - (width - x) / (width / game->n)) - 1);
		if (caseX == -1)caseX = 0;

		game->selectedXPos = (float)(x / (width / 2.0f) - 1.0f) - squareSizeX / 2.0f;
		game->selectedYPos = (float)-(y / (height / 2.0f) - 1.0f) - squareSizeY / 2.0f;
	}
}

void MyControlEngine::KeyboardCallback(unsigned char key, int x, int y) {

	if (key == 'p') {
		game->pause = !game->pause;
		std::printf("PAUSE");
	}
	if (key == 'g' && !game->gameStarted && game->wave == NULL) {
		std::printf("GOGOGO");
		if (game->loadNextLevel()) {
			game->wave = new Wave(game->level, game->currentPath());
			game->countMonstres = game->wave->monstreCount;
		}
	}
	if (key == 'r' && game->wave != NULL) {
		if (game->loadNextLevel()) {
			game->wave = new Wave(game->level, game->currentPath());
			game->countMonstres = game->wave->monstreCount;
		}
	}
	if (key == 'n' && game->nextLevelMenu) {
		if (game->loadNextLevel()) {
			game->wave = new Wave(game->level, game->currentPath());
			game->countMonstres = game->wave->monstreCount;
			game->nextLevelMenu = false;
		}
	}
	if (key == 'r' && game->gameOver) {
		game->restartGame();
		turnStorage->removeAllTurns();
		std::printf("RESTART FROM GAME OVER \n");
	}
	if (key == 'r' && game->gameWin) {
		game->restartGame();
		turnStorage->removeAllTurns();
		std::printf("RESTART FROM GAME WIN \n");
	}

}