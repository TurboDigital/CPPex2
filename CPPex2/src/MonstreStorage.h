#pragma once
#include <memory>
#include <vector>
#include "Monstre.h"

class MonstreStorage {

public:
	MonstreStorage():monstres() {

	}

	typedef std::vector<std::shared_ptr<Monstre>> Storage;

	void addMonstre(std::shared_ptr<Monstre> const& monstre);

	void forEachDraw();

	void forEachMove();

	int getSize();


private:
	Storage monstres;

};