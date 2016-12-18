#include "Monstre.h"

void Monstre::takeDamage(int damage) {
	life -= damage;
}

void Monstre::draw() {
	//TO DO Drawing
	//std::printf("%lf %lf %lf %lf \n", x, y, vx, vy);
	GraphicPrimitives::drawFillRect2D(x, y, squareSizeX / 2, squareSizeY / 2, r, g, b);
}
void Monstre::move() {

	// float squareSizeX = (float)(2.0 / n); //to check later if the frame is not a square
	// float squareSizeY = (float)(2.0 / m);

	// int path[12] = { 0,4,5,4,5,7,12,7,12,2,2,2 };
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);

	int startX = path[lines];
	int startY = path[lines + 1];
	int endX = path[lines + 2];
	int endY = path[lines + 3];
	
	float startPointX = -1.0f + squareSizeX * (startY) + (squareSizeX / 2.0f);
	float startPointY = 1.0f - squareSizeY * (startX) - (squareSizeX / 2.0f);
	
	float endPointX = -1.0f + squareSizeX * (endY) + (squareSizeX / 2.0f);
	float endPointY = 1.0f - squareSizeY * (endX) - (squareSizeX / 2.0f);
	
	if(!change){
		if (startX == endX) {
			if (startX < endY) {
					// Y axis
					vx = 0.001f;
					change = true;
			}
			else {
					// -X axis
					vy = -0.001f;
					change = true;
			}
		}
		if (startY == endY) {
			if (startX < endX) {
					// X axis
					vy = -0.001f;
					change = true;
			}
			else {
					// -Y axis
					vx = 0.001f;
					change = true;
			}
		}
	}
	
	x += vx;
	y += vy;

	if (y > endPointY - squareSizeY / 2 && y < endPointY) {
		lines += 2;
		vx = 0.0f;
		vy = 0.0f;
		change = false;
	}
}