#include "Path.h"

float Path::getStartX() {
	float squareSizeX = (float)(2.0 / N); //to check later if the frame is not a square
	return -1.0f + squareSizeX * path[1] + squareSizeX / 4.0f;
}

float Path::getStartY() {
	float squareSizeY = (float)(2.0 / M); //to check later if the frame is not a square
	return 1.0f - squareSizeY * path[0] - squareSizeY / 4.0f;
}