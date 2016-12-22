#include "LoadGame.h"
void LoadGame::addPath(std::shared_ptr<Path> const& path) {
	loadedPaths.push_back(path);
}

void LoadGame::setWave(int wave_, int life_, int speed_, int armor_) {
	if (wave_ < 0 || wave_ > wavesPerChapter)
		return;
	
	levels[wave_][0] = life_;
	levels[wave_][1] = speed_;
	levels[wave_][2] = armor_;
		
}

int LoadGame::getLife(int wave_) {
	return levels[wave_][0];
}
float LoadGame::getSpeed(int wave_) {
	return levels[wave_][1] / 10000.0f;
}
int LoadGame::getArmor(int wave_) {
	return levels[wave_][2];
}