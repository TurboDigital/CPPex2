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
	if (game->gameStarted && !game->gameOver) {
		game->draw();
		turnStorage->forEachDraw();
		turnStorage->forEachDrawBullets();
		if (game->wave != NULL)game->wave->monstreStorage.forEachDraw();
		if (game->pause) {
			game->pauseDraw();
		}
		if (game->nextLevelMenu) {
			game->goToNextLevelDraw();
		}
	}
	
	if (!game->gameStarted) {
		game->startDraw();
	}
	if (game->gameOver) {
		game->gameOverDraw();
	}
	
	

}