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
	
	grid[12][5] = BUY_TURN;

}

void Grid::checkNoneCaseAndAddTurn(int i, int j) {
	if (i >= 0 && j <= m && i < 10 && j >= 0) {
		if (grid[i][j] == NONE) {
			grid[i][j] = TURN;
		}
	}
}

void Grid::addTurnPlaces(int i, int j) {
	checkNoneCaseAndAddTurn(i - 1, j - 1);
	checkNoneCaseAndAddTurn(i - 1, j);
	checkNoneCaseAndAddTurn(i - 1, j + 1);
	checkNoneCaseAndAddTurn(i, j - 1);
	checkNoneCaseAndAddTurn(i, j + 1);
	checkNoneCaseAndAddTurn(i + 1, j - 1);
	checkNoneCaseAndAddTurn(i + 1, j);
	checkNoneCaseAndAddTurn(i + 1, j + 1);
}

Grid::CreatureType Grid::getEl(int i, int j) {
	return grid[i][j];
}


void Grid::storeTurn(std::shared_ptr<Turn> const& turn) {
	turnStorage.push_back(turn);
}

bool Grid::addNewTurn(int i, int j) {
	//if (turnStorage.size() == turnLimit)
	//	return false;
	storeTurn(std::make_shared<Turn>(Turn(i, j)));
	std::printf("the size = %d", turnStorage.size());
	return true;
}

void Grid::draw() {
	float squareSizeX = (float)(2.0 / n); //to check later if the frame is not a square
	float squareSizeY = (float)(2.0 / m);
	float x = -1.0f;
	float y = 1.0f - squareSizeY;	//FillRect draw from LEFT DOWN corner to RIGHT UP
	
	if (isSelected) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == TURN)
					GraphicPrimitives::drawFillRect2D(x + (i*squareSizeX), y - (j*squareSizeY), squareSizeX, squareSizeY, 0.80f, 0.80f, 0.80f);
			}
		}

		float rx = selectedXPos;
		float ry = selectedYPos;
		std::printf("pos x = %lf pos y = %lf \n", rx, ry);
		GraphicPrimitives::drawFillRect2D(rx, ry, squareSizeX, squareSizeY, 1.0f, 0.0f, 1.0f);


	}

	for (unsigned int i = 0; i < turnStorage.size(); i++) {
		int tX = turnStorage[i].get()->getI();
		int tY = turnStorage[i].get()->getJ();
		float rx = x + (tY*squareSizeX);	//x axis + j*(size of square 0.0 .. 0.x x<0.9)
		float ry = y - (tX*squareSizeY);	//y axis + i*(size of square 0.0 .. 0.x x<0.9)
		
		GraphicPrimitives::drawFillRect2D(rx, ry, squareSizeX, squareSizeY, 1.0f, 0.0f, 1.0f);
		//TO DO textures
		//GraphicPrimitives::drawSpritedRect2D(rx, ry, squareSizeX, squareSizeY, 0, 0, new TextureManager("sprites/turn2.bmp",32,32));
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