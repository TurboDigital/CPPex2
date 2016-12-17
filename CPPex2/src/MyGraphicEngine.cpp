#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw() {

	//GraphicPrimitives::drawLine2D(0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f);

	//GraphicPrimitives::drawFillTriangle2D(0.0f, 0.0f, -0.05f, -0.05f, 0.05f, -0.05f, 0.0f, 0.0f, 1.0f);

	//draw functions
	float squareSizeX = (float)(2.0 / grid->n); //to check later if the frame is not a square
	float squareSizeY = (float)(2.0 / grid->m);


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

	float x = -1.0f, y = 1.0f - squareSizeY; //start paint from left top corner
	// y = 0.8f because GraphicPrimitives draw from left down corner
	//draw the table
	for (int i = 0; i < grid->n; i++) {
		for (int j = 0; j < grid->m; j++) {
			Grid::CreatureType objet = grid->getEl(i, j);
			if (objet == Grid::CreatureType::ROCK)
				GraphicPrimitives::drawFillRect2D(x + (i*squareSizeX), y - (j*squareSizeY), squareSizeX, squareSizeY, 0.9f, 0.7f, 1.0f);
			if (objet == Grid::CreatureType::TREE)
				GraphicPrimitives::drawFillRect2D(x + (i*squareSizeX), y - (j*squareSizeY), squareSizeX, squareSizeY, 1.0f, 0.0f, 1.0f);
			if (objet == Grid::CreatureType::TURN)
				GraphicPrimitives::drawFillRect2D(x + (i*squareSizeX), y - (j*squareSizeY), squareSizeX, squareSizeY, 1.0f, 0.0f, 1.0f);
			if (objet == Grid::CreatureType::ROAD)
				GraphicPrimitives::drawFillRect2D(x + (i*squareSizeX), y - (j*squareSizeY), squareSizeX, squareSizeY, 0.0f, 0.1f, 1.0f);
			if (objet == Grid::CreatureType::NONE)
				GraphicPrimitives::drawFillRect2D(x + (i*squareSizeX), y - (j*squareSizeY), squareSizeX, squareSizeY, 1.0f, 1.0f, 1.0f);

			/*if (j % 2 == 0 && i % 2 == 0 || j % 2 != 0 && i % 2 != 0) {
				GraphicPrimitives::drawFillRect2D(x + (i*squareSizeX), y - (j*squareSizeY), squareSizeX, squareSizeY, 1.0f, 0.0f, 1.0f);
			}
			else {
				GraphicPrimitives::drawFillRect2D(x + (i*squareSizeX), y - (j*squareSizeY), squareSizeX, squareSizeY, 0.0f, 1.0f, 0.0f);
			}*/

		}
	}

	grid->draw();

}