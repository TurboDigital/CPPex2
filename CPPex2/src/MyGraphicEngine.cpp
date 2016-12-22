#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw() {

	/*
	coords of the frame
	(-1,1)	*********************(1,1)
			*					*
			*					*
			*		(0,0)		*
			*					*
			*					*
	(-1,-1)	*********************(1,-1)
	*/
	if (game->gameStarted && !game->gameWin) {
		game->draw();
		if (observer->drawVirtual) {
			observer->virtualDraw();
			game->drawSelected();
		}
		turnStorage->forEachDraw();
		if (game->clicked) {
			int towerI = game->clickTowerI;
			int towerJ = game->clickTowerJ;
			turnStorage->drawBorders(towerI,towerJ);

			int level = turnStorage->getTurnLevel(towerI, towerJ);
			int attack = turnStorage->getTurnAttack(towerI, towerJ);
			int attackRate = turnStorage->getTurnAttackRate(towerI, towerJ);
			game->drawSelectedInfo(level, attack, attackRate);
		}
		turnStorage->forEachDrawBullets();
		if (game->wave != NULL)game->wave->monstreStorage.forEachDraw();
		if (game->pause) {
			game->pauseDraw();
		}
		if (game->nextLevelMenu) {
			game->goToNextLevelDraw();
		}
	}
	
	if (!game->gameStarted && !game->gameOver && !game->gameWin) {
		game->startDraw();
	}
	if (game->gameOver && game->gameStarted && !game->gameWin) {
		game->gameOverDraw();
	}
	if (game->gameWin) {
		game->gameWinDraw();
	}
	
	

}