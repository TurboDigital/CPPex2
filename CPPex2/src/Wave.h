#pragma once
#include "MonstreStorage.h"
#include "Config.h"



class Wave {
	Path * path;
public:
	Wave(int monstreCount_, Path * path_) :
		path(path_),
		monstreCount(monstreCount_*MONSTRE_PER_LEVEL),
		frequence(MONSTRE_WAVE_FREQUENCE)
	{}
	int counter = 0;
	int monstreCount;
	int frequence;
	MonstreStorage monstreStorage;

	void createWave(int level, int life_, float speed_, int armor);
	void setDamage(Monstre * monstre_, int damage_);

	bool isEmpty();
	int getArrivedMonsters();

};