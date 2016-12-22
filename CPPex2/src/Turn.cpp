#include "Turn.h"
#include <math.h>

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
	GraphicPrimitives::drawFillRect2D(rx, ry, squareSizeX, squareSizeY, r, g, b, a);



}

void Turn::drawBorder() {
	float squareSizeX = (float)(2.0 / n); //to check later if the frame is not a square
	float squareSizeY = (float)(2.0 / m);
	float x = -1.0f;
	float y = 1.0f - squareSizeY;	//FillRect draw from LEFT DOWN corner to RIGHT UP

	int tX = getI();
	int tY = getJ();

	float rx = x + ((tY - 1)*squareSizeX);	//x axis + j*(size of square 0.0 .. 0.x x<0.9)
	float ry = y - ((tX + 1)*squareSizeY);	//y axis + i*(size of square 0.0 .. 0.x x<0.9)
	GraphicPrimitives::drawOutlinedRect2D(rx, ry, squareSizeX * 3, squareSizeY * 3, .85f, .64f, .12f, a);
}

void Turn::attack() {
	
	//TO DO Attack

	//clear bullets that are arrived
	for (unsigned int k = 0; k < bullets.size(); k++) {
		if (bullets[k]->dead) {
			bullets.erase(bullets.begin() + k);
		}
	}

	MonstreStorage::Storage monstresAround = game->getMonstersAround(i, j);

	Bullet * bullet = NULL;
	float sizeX = (float)(2.0 / n);
	float sizeY = (float)(2.0 / m);
	float x = -1.0f + sizeX*j + sizeX / 2.0f;
	float y = 1.0f - sizeY*i - sizeY / 2.0f;
	if (freq <= 0) {
		if(monstresAround.size()>=1){
			int k = 0;
			std::printf("MONSTRE %d", k);
			std::printf("\t POSITION %lf %lf", monstresAround[k].get()->getX(), monstresAround[k].get()->getY());
			float destinationX = monstresAround[k].get()->getX() + monstresAround[k].get()->getWidth() / 2;
			float destinationY = monstresAround[k].get()->getY() + monstresAround[k].get()->getHeight() / 2;

			float distance = sqrt(pow(destinationX - x, 2) + pow(destinationY - y, 2));
			float directionX = ((destinationX - x) / distance) / 500;
			float directionY = ((destinationY - y) / distance) / 500;


			bullets.push_back(std::make_shared<Bullet>(Bullet(x, y, directionX, directionY, destinationX, destinationY, distance, 0.01f, turnAttack)));
			freq = freqMax;
		}	
	}
	freq--;

}

void Turn::updateLevel() {
	if (level + 1 > levelMax) {
		return;
	}
	else {
		level++;
	}
	switch (level) {
	case 1:
		freqMax = 100;
		turnAttack += 20;
		r = .13f;	g = .54f;	b = .13f;
		break;
	case 2:
		freqMax = 80;
		turnAttack += 20;
		r = .69f;	g = .18f;	b = .37f;
		break;
	case 3:
		freqMax = 50;
		turnAttack += 20;
		r = .27f;	g = .50f;	b = .70f;
		break; 
	case 4:
		freqMax = 30;
		turnAttack += 20;
		r = .09f;	g = .09f;	b = .43f;
		break;
	}
}


int Turn::getAttack() {
	return turnAttack;
}

int Turn::getLevel() {
	return level;
}
int Turn::getAttackRate(){
	return freqMax;
}