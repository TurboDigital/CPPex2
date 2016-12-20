#include "Bullet.h"

void Bullet::draw() {
	GraphicPrimitives::drawFillRect2D(x, y, size, size, 1.0f, .0f, .0f);
	move();
}

void Bullet::move() {
	x += vx;
	y += vy;
	if(x>=destX && y >= destY){
		vx = 0;
		vy = 0;
		dead = true;
	}
}