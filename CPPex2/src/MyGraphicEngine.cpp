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

	float x = -1.0f, y = -1.0f; //start paint from left down corner
	//draw the table
	for (int i = 0; i < grid->n; i++) {
		for (int j = 0; j < grid->m; j++) {
			if (j % 2 == 0 && i % 2 == 0 || j % 2 != 0 && i % 2 != 0) {
				GraphicPrimitives::drawFillRect2D(x + (j*squareSizeX), y + (i*squareSizeY), squareSizeX, squareSizeY, 1.0f, 0.0f, 1.0f);
			}
			else {
				GraphicPrimitives::drawFillRect2D(x + (j*squareSizeX), y + (i*squareSizeY), squareSizeX, squareSizeY, 0.0f, 1.0f, 0.0f);
			}
		}
	}

	grid->draw();

}