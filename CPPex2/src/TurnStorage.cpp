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

void TurnStorage::removeAllTurns() {
	turns.clear();
}

void TurnStorage::drawBorders(int i, int j) {
	for (unsigned int k = 0; k < turns.size(); k++) {
		if (turns[k].get()->i == i && turns[k].get()->j == j) {
			turns[k].get()->drawBorder();
		}
	}
}

void TurnStorage::upgradeTurn(int i, int j) {
	for (unsigned int k = 0; k < turns.size(); k++) {
		if (turns[k].get()->i == i && turns[k].get()->j == j) {
			turns[k].get()->updateLevel();
		}
	}
}

int TurnStorage::getTurnAttack(int i, int j) {
	for (unsigned int k = 0; k < turns.size(); k++) {
		if (turns[k].get()->i == i && turns[k].get()->j == j) {
			return turns[k].get()->getAttack();
		}
	}
}
int TurnStorage::getTurnAttackRate(int i, int j) {
	for (unsigned int k = 0; k < turns.size(); k++) {
		if (turns[k].get()->i == i && turns[k].get()->j == j) {
			return turns[k].get()->getAttackRate();
		}
	}
}
int TurnStorage::getTurnLevel(int i, int j) {
	for (unsigned int k = 0; k < turns.size(); k++) {
		if (turns[k].get()->i == i && turns[k].get()->j == j) {
			return turns[k].get()->getLevel();
		}
	}
}

bool TurnStorage::exists(int i, int j) {
	for (unsigned int k = 0; k < turns.size(); k++) {
		if (turns[k].get()->i == i && turns[k].get()->j == j) {
			return true;
		}
	}
	return false;
}