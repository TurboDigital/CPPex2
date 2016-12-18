#include "Turn.h"

int Turn::getI() {
	return i;
}

int Turn::getJ() {
	return j;
}

void Turn::setXY(float x, float y) {
	virtualX = x;
	virtualY = y;
}

void Turn::draw(){
	//TO DO Drawing
	float squareSizeX = (float)(2.0 / n); //to check later if the frame is not a square
	float squareSizeY = (float)(2.0 / m);
	float x = -1.0f;
	float y = 1.0f - squareSizeY;	//FillRect draw from LEFT DOWN corner to RIGHT UP

	int tX = getI();
	int tY = getJ();

	float rx = x + (tY*squareSizeX);	//x axis + j*(size of square 0.0 .. 0.x x<0.9)
	float ry = y - (tX*squareSizeY);	//y axis + i*(size of square 0.0 .. 0.x x<0.9)
	GraphicPrimitives::drawFillRect2D(rx, ry, squareSizeX, squareSizeY, r, g, b);

}

void Turn::attack() {
	//TO DO Attack
}