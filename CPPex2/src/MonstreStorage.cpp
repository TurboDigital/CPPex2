#include "MonstreStorage.h"

void MonstreStorage::addMonstre(std::shared_ptr<Monstre> const& monstre) {
	monstres.push_back(monstre);
}

void MonstreStorage::forEachDraw() {
	for (unsigned int i = 0; i < (int)monstres.size(); i++) {
		monstres[i].get()->draw();
	}
}

void MonstreStorage::forEachMove() {
	for (unsigned int i = 0; i < (int)monstres.size(); i++) {
		monstres[i].get()->move();
	}
}

int MonstreStorage::getSize() {
	if(!monstres.empty())
		return monstres.size();
	return 0;
}

void MonstreStorage::setDamage(Monstre * monstre_, int damage_) {
	for (unsigned int i = 0; i < (int)monstres.size(); i++) {
		if (monstres[i].get() == monstre_) {
			monstres[i].get()->setDamage(damage_);
		}
	}
}

void MonstreStorage::deleteDeadMonsters() {
	for (unsigned int i = 0; i < (int)monstres.size(); i++) {
		if (monstres[i].get()->dead) {
			monstres.erase(monstres.begin() + i);
		}
	}
}

int MonstreStorage::getArrivedMonsters() {
	int count = 0;
	for (unsigned int i = 0; i < (int)monstres.size(); i++) {
		if (monstres[i].get()->arrived) {
			count++;
		}
	}
	return count;
}