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

	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);

	int startX = path->path[lines];
	int startY = path->path[lines + 1];
	int endX = path->path[lines + 2];
	int endY = path->path[lines + 3];
	
	float endPointX = -1.0f + squareSizeX * (endY);
	float endPointY = 1.0f - squareSizeY * (endX);
	
	
	if (startX == endX) {
		if (startX < endY) {
			// X axis
			if (!change) {
				vx = speed;
				change = true;
			}
			endPointX += squareSizeX / 2 - squareSizeX / 4;
		}
		else {
				// -X axis
			if (!change) {
				vx = -speed;
				change = true;
			}
			endPointX -= squareSizeX / 2 + squareSizeX / 4;
		}
	}
	if (startY == endY) {
		if (startX < endX) {
			// -Y axis
			if (!change) {
				vy = -speed;
				change = true;
			}
			endPointY -= squareSizeY - squareSizeY / 4;
		}
		else {
				// Y axis
			if (!change) {
				vy = speed;
				change = true;
			}
			endPointY += squareSizeY + squareSizeY / 4;
		}
	}


	
	x += vx;
	y += vy;

	if ((y > endPointY - squareSizeY && y < endPointY) && (x > endPointX && x < endPointX + squareSizeX)) {
		lines += 2;
		vx = 0.0f;
		vy = 0.0f;
		change = false;
		if (lines > 8)
			change = true;
	}
}