#include "Grid.h"
#include <sstream>
#include <string.h>

int Grid::getEl(int i, int j) {
	return grid[i][j];
}

void Grid::setEl(int i, int j, int val) {
	grid[i][j] = val;
}

void Grid::draw() {
	float squareSizeX = (float)(2.0 / n); //to check later if the frame is not a square
	float squareSizeY = (float)(2.0 / m);
	float x = -1.0f;
	float y = 1.0f - squareSizeY;	//FillRect draw from LEFT DOWN corner to RIGHT UP

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] >= 1) {
				//draw the new color on each clicked square
				float rx = x + (j*squareSizeX);	//x axis + j*(size of square 0.0 .. 0.x x<0.9)
				float ry = y - (i*squareSizeY);	//y axis + i*(size of square 0.0 .. 0.x x<0.9)
				GraphicPrimitives::drawFillRect2D(rx, ry, squareSizeX, squareSizeY, 1.0f, 1.0f, 1.0f);
				
				//source: stackoverflow
				std::ostringstream oss;
				oss << grid[i][j];
				std::string number = oss.str();

				char * charNumber = new char[number.length()+1];
				strcpy_s(charNumber, number.length()+1 ,number.c_str()); //to make it safer
				//draw the number of clicks
				GraphicPrimitives::drawText2D(charNumber, rx + (squareSizeX / 2), ry + (squareSizeY / 2), 0.0f, 0.0f, 1.0f);

			}
		}
	}
}