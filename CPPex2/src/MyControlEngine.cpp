#include "MyControlEngine.h"
#include <math.h>

void MyControlEngine::MouseCallback(int button, int state, int x , int y) {
	//to do mouse clicks
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//find the case [i][j] from grid: translation from the frame to Matrix
		int caseX = (int)trunc(grid->n - (600 - x) / (600 / grid->n) - 1);
		int caseY = (int)trunc(grid->m - (600 - y) / (600 / grid->m) - 1);
		
		//get the actual value from the grid
		int val = grid->getEl(caseY, caseX);
		grid->setEl(caseY, caseX, ++val);	//update the value from grid
	}
}