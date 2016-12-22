#include "Wave.h"

void Wave::createWave(int level, int life_, float speed_, int armor){
	if (monstreCount > 0 && frequence == 0) {
		monstreStorage.addMonstre(std::make_shared<Monstre>(Monstre(path,path->getStartX(), path->getStartY(), life_, speed_, N, M, 7.0f, 7.0f, 0.0f)));
		monstreCount--;
		frequence = MONSTRE_WAVE_FREQUENCE;
		std::printf("MONSTRE ADDED\n");
	}
	else {
		frequence--;
	}
}

void Wave::setDamage(Monstre * monstre_, int damage_) {
	monstreStorage.setDamage(monstre_, damage_);
}

bool Wave::isEmpty() {
	return (monstreStorage.getSize() == 0);
}

int Wave::getArrivedMonsters() {
	return monstreStorage.getArrivedMonsters();
}