#include "Bullet.h"
#include <math.h>

void Bullet::draw() {
	GraphicPrimitives::drawFillRect2D(x, y, size, size, 1.0f, .0f, .0f);
	move();
}

void Bullet::move() {
	x += vx;
	y += vy;
	
	if (sqrt(pow(startX-x,2)+pow(startY-y,2)) >= distance) {
		vx = 0;
		vy = 0;
		dead = true;
	}


}