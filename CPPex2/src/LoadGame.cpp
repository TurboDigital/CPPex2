#include "LoadGame.h"
#include <fstream>
#include <string>
#include <sstream>

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

void LoadGame::readDataFromFile() {
	std::ifstream input("src/GameData.txt", std::ifstream::in);
	std::string file;

	for (std::string line; std::getline(input, line);) {
		file += line;
		file.push_back(' ');
	}
	std::printf("Data from file:\n%s ", file.c_str());
	std::string data, 
		path = "PATHS",
		wave = "WAVE";

	std::size_t findStart = file.find("START_DATA");
	std::size_t findPath = file.find(path, findStart + 1);
	std::size_t findWave = file.find(wave);
	std::size_t findEnd = file.find("END_DATA");

	std::string paths = file.substr(findPath + 5, findWave - findPath - 5);
	std::string waves = file.substr(findWave + 4, findEnd - findWave - 4);

	std::vector<std::string> parsedPaths = split(paths,'|');
	
	Row pathArray;
	

	for (int i = 0; i < parsedPaths.size(); i++) {
		std::stringstream stream(parsedPaths[i]);
		int n;
		while(stream >>n){
			pathArray.push_back(n);
		}
		pathMatrix.push_back(pathArray);
		pathArray.clear();
	}
	
	std::vector<std::string> parsedWaves = split(waves, '|');
	
	Row waveLine;

	for (int i = 0; i < parsedWaves.size(); i++) {
		std::stringstream stream(parsedWaves[i]);
		int n;
		while (stream >> n) {
			waveLine.push_back(n);
		}
		waveMatrix.push_back(waveLine);
		waveLine.clear();
	}
	

}


void LoadGame::split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}


std::vector<std::string> LoadGame::split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

void LoadGame::setAllDataFromFile() {

	for (int i = 0; i < pathMatrix.size(); i++) {
		addPath(std::make_shared<Path>(Path(pathMatrix[i].data(), pathMatrix[i].size())));
	}
	for (int i = 0; i < waveMatrix.size(); i++) {
		setWave(waveMatrix[i][0], waveMatrix[i][1], waveMatrix[i][2], waveMatrix[i][3]);
	}

}
