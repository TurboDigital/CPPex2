#include "Wave.h"

void Wave::createWave(){
	if (monstreCount > 0 && frequence == 0) {
		monstreStorage.addMonstre(std::make_shared<Monstre>(Monstre(path,path->getStartX(), path->getStartY(), 100, 0.0009f, N, M, 7.0f, 7.0f, 0.0f)));
		monstreCount--;
		frequence = MONSTRE_WAVE_FREQUENCE;
		std::printf("MONSTRE ADDED\n");
	}
	else {
		frequence--;
	}
}