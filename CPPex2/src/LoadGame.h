#pragma once
#include "Config.h"
#include "Path.h"
#include <vector>
#include <memory>

class LoadGame {
public:
	LoadGame(int chapter_, int waves_):
		levels(waves_,MonsterType(3)),
		totalChapters(chapter_),
		wavesPerChapter(waves_)
		{
		readDataFromFile();
		setAllDataFromFile();
	};

	int myPath[12] = {0,4,5,4,5,7,12,7,12,2,2,2};
	int myPath1[12] = {0,4,5,4,5,7,8,7,8,2,2,2};

	int totalChapters;
	int wavesPerChapter;
	
	typedef std::vector<int> MonsterType;
	typedef std::vector<MonsterType> Level;

	Level levels;

	typedef std::vector<std::shared_ptr<Path>> LoadedPaths;
	LoadedPaths loadedPaths;

	typedef std::vector<int> Row;
	typedef std::vector<Row> PathMatrix;

	PathMatrix pathMatrix;
	PathMatrix waveMatrix;

	void readDataFromFile();
	void addPath(std::shared_ptr<Path> const& path);
	void setWave(int wave_, int life_, int speed_, int armor);
	void setAllDataFromFile();

	int getLife(int wave_);
	float getSpeed(int wave_);
	int getArmor(int wave_);

	void LoadGame::split(const std::string &s, char delim, std::vector<std::string> &elems);
	std::vector<std::string> LoadGame::split(const std::string &s, char delim);
	
	
};