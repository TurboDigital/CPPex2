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