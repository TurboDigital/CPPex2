#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw() {

	//GraphicPrimitives::drawLine2D(0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f);

	//GraphicPrimitives::drawFillTriangle2D(0.0f, 0.0f, -0.05f, -0.05f, 0.05f, -0.05f, 0.0f, 0.0f, 1.0f);
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
	if (!game->pause && !game->gameOver) {
		game->draw();
		turnStorage->forEachDraw();
	}else if (!game->gameStarted) {
		game->drawStartMenu();
	}else if(game->wave != NULL){
		game->wave->monstreStorage.forEachDraw();
	}
	

}