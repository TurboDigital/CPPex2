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
	for (int k = 0; k < bullets.size(); k++) {
		if (bullets[k]->dead) {
			bullets.erase(bullets.begin()+k);
		}
	}
	Bullet * bullet = NULL;
	if (freq%fire_rate == 0) {
		float sizeX = (float)(2.0 / n);
		float sizeY = (float)(2.0 / m);
		float x = -1.0f + sizeX*j + sizeX/2.0f;
		float y = 1.0f - sizeY*i - sizeY/2.0f;
		bullets.push_back(std::make_shared<Bullet>(Bullet(x,y,0.001f,0.0f,x+0.2,y,0.01)));
		freq = 0;
	}
	freq++;

}