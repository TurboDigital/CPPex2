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
		addPath(std::make_shared<Path>(Path(myPath, 5)));
		addPath(std::make_shared<Path>(Path(myPath1, 5)));

		setWave(0, 100, 10, 20);
		setWave(1, 130, 15, 20);
		setWave(2, 140, 20, 20);
		setWave(3, 150, 25, 20);
		setWave(4, 160, 30, 20);

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

	
	void addPath(std::shared_ptr<Path> const& path);
	void setWave(int wave_, int life_, int speed_, int armor);

	int getLife(int wave_);
	float getSpeed(int wave_);
	int getArmor(int wave_);
	
};