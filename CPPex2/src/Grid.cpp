#include "Grid.h"
#include <sstream>
#include <string.h>

void Grid::initGrid() {
	//TO-DO read from a file paths and path[N]
	int paths = 5;
	int path[12] = {0,4,5,4,5,7,12,7,12,2,2,2};
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
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == ROAD){
				addTurnPlaces(i, j);
			}
				
		}
	}

	grid[12][5] = TURN;

}

bool Grid::checkNoneCase(int i, int j) {
	if (i < 0 || j >= m || i > 10 || j < 0) return false;
	if (grid[i][j] == NONE) {
		grid[i][j] = TURN;
		return true;
	}
	return false;
}

void Grid::addTurnPlaces(int i, int j) {
	checkNoneCase(i - 1, j - 1);
	checkNoneCase(i - 1, j);
	checkNoneCase(i - 1, j + 1);
	checkNoneCase(i, j - 1);
	checkNoneCase(i, j + 1);
	checkNoneCase(i + 1, j - 1);
	checkNoneCase(i + 1, j);
	checkNoneCase(i + 1, j + 1);
}

Grid::CreatureType Grid::getEl(int i, int j) {
	return grid[i][j];
}

bool Grid::addNewTurn(int i, int j) {
	if (turnArray.size() == turnLimit)
		return false;
	//turnArray.insert(&Turn(i, j));
	
}

void Grid::draw() {
	float squareSizeX = (float)(2.0 / n); //to check later if the frame is not a square
	float squareSizeY = (float)(2.0 / m);
	float x = -1.0f;
	float y = 1.0f - squareSizeY;	//FillRect draw from LEFT DOWN corner to RIGHT UP
	for (int i = 0; i < turnArray.size(); i++) {
		int tX = turnArray[i][0];
		int tY = turnArray[i][1];
		float rx = x + (tX*squareSizeX);	//x axis + j*(size of square 0.0 .. 0.x x<0.9)
		float ry = y - (tY*squareSizeY);	//y axis + i*(size of square 0.0 .. 0.x x<0.9)
		GraphicPrimitives::drawFillRect2D(rx, ry, squareSizeX, squareSizeY, 1.0f, 1.0f, 1.0f);
	}
	/*
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
	*/
}