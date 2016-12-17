#include "MyControlEngine.h"
#include <math.h>

void MyControlEngine::MouseCallback(int button, int state, int x , int y) {
	//to do mouse clicks
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		//find the case [i][j] from grid: translation from the frame to Matrix
		int caseX = (unsigned int)trunc((grid->m - (height - y) / (height / grid->m)) - 1);
		int caseY = (unsigned int)trunc((grid->n - (width - x) / (width / grid->n)) - 1);
		if (caseX == -1)caseX = 0;
		
		Grid::CreatureType caseType = grid->getEl(caseY, caseX);
		
		//TO DO: onClick and put turns
		if (caseType == Grid::CreatureType::BUY_TURN) {
			grid->isSelected = true;
		}
		
	}

	if (state == GLUT_UP && grid->isSelected) {
		int caseX = (unsigned int)trunc((grid->m - (height - y) / (height / grid->m)) - 1);
		int caseY = (unsigned int)trunc((grid->n - (width - x) / (width / grid->n)) - 1);
		if (caseX == -1)caseX = 0;
		Grid::CreatureType caseType = grid->getEl(caseY, caseX);
		if (caseType == Grid::CreatureType::TURN) {
			bool added = grid->addNewTurn(caseX, caseY);
			if (!added)std::printf("The case %d and %d are not allowed", caseX, caseY);
		}
		grid->isSelected = false;

	}
}

void MyControlEngine::MotionCallback(int x, int y){

	//TO DO: onClick and put turns
	if (grid->isSelected) {

		int width = glutGet(GLUT_WINDOW_WIDTH);
		int height = glutGet(GLUT_WINDOW_HEIGHT);

		float squareSizeX = (float)(2.0 / grid->n); //to check later if the frame is not a square
		float squareSizeY = (float)(2.0 / grid->m);

		int caseX = (unsigned int)trunc((grid->m - (height - y) / (height / grid->m)) - 1);
		int caseY = (unsigned int)trunc((grid->n - (width - x) / (width / grid->n)) - 1);
		if (caseX == -1)caseX = 0;

		grid->selectedXPos = (float)(x / (width / 2.0f) - 1.0f) - squareSizeX / 2.0f;
		grid->selectedYPos = (float)-(y / (height / 2.0f) - 1.0f) - squareSizeY / 2.0f;
	}
}