#include "Monstre.h"

void Monstre::takeDamage(int damage) {
	life -= damage;
}

void Monstre::draw() {
	//TO DO Drawing
	//std::printf("%lf %lf %lf %lf \n", x, y, vx, vy);
	GraphicPrimitives::drawFillRect2D(x, y, getWidth(), getHeight(), r, g, b);
}
void Monstre::move() {
	if (life <= 0)dead = true;
	if (!dead) {
		int width = glutGet(GLUT_WINDOW_WIDTH);
		int height = glutGet(GLUT_WINDOW_HEIGHT);

		int startX = path->path[lines];
		int startY = path->path[lines + 1];
		int endX = path->path[lines + 2];
		int endY = path->path[lines + 3];

		float endPointX = -1.0f + squareSizeX * (endY);
		float endPointY = 1.0f - squareSizeY * (endX);


		if (startX == endX) {
			if (startX <= endY) {
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
			if (startX <= endX) {
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

		if ((y > endPointY - squareSizeY && y < endPointY) 
			&& (x > endPointX && x < endPointX + squareSizeX)) 
		{
			vx = 0.0f;
			vy = 0.0f;
			change = false;
			if (endX == path->path[path->size - 2] && lines == path->size - 4) {
				arrived = true;
				dead = true;
				change = true;
			}
			lines += 2;
		}
	}
}

float Monstre::getX() {
	return x;
}
float Monstre::getY() {
	return y;
}
float Monstre::getWidth() {
	return squareSizeX / 2.0f;
}

float Monstre::getHeight() {
	return squareSizeY / 2.0f;
}

void Monstre::setDamage(int damage_) {
	life -= (damage_-armor);
}