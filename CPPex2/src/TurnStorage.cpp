#include "TurnStorage.h"

void TurnStorage::addTurn(std::shared_ptr<Turn> const& turn) {
	turns.push_back(turn);
}

int TurnStorage::getSize() {
	return turns.size();
}

void TurnStorage::forEachDraw() {
	for (unsigned int i = 0; i < turns.size(); i++) {
		turns[i].get()->draw();
	}
}

void TurnStorage::forEachDrawBullets() {
	for (unsigned int i = 0; i < turns.size(); i++) {
		for (unsigned int j = 0; j < turns[i].get()->bullets.size(); j++) {
			turns[i].get()->bullets[j]->draw();
		}
	}
}

void TurnStorage::forEachAttack() {
	for (unsigned int i = 0; i < turns.size(); i++) {
		turns[i].get()->attack();
	}
}

void TurnStorage::removeTurn(int i, int j) {
	for (unsigned int k = 0; k < turns.size(); k++) {
		if (turns[k].get()->i == i && turns[k].get()->j == j) {
			turns.erase(turns.begin()+k);
		}
	}
}