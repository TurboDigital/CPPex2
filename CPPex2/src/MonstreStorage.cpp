#include "MonstreStorage.h"

void MonstreStorage::addMonstre(std::shared_ptr<Monstre> const& monstre) {
	monstres.push_back(monstre);
}

void MonstreStorage::forEachDraw() {
	for (unsigned int i = 0; i < monstres.size(); i++) {
		monstres[i].get()->draw();
	}
}

void MonstreStorage::forEachMove() {
	for (unsigned int i = 0; i < monstres.size(); i++) {
		monstres[i].get()->move();
	}
}

int MonstreStorage::getSize() {
	return monstres.size();
}