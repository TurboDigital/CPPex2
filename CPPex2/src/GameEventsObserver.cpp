#include "GameEventsObserver.h"

void GameEventsObserver::collisions() {
	for (unsigned int i = 0; i < turnStorage->turns.size(); i++) {
		collisionsBulletMonster(turnStorage->turns[i].get(), turnStorage->turns[i].get()->getI(), turnStorage->turns[i].get()->getJ());
	}
}

void GameEventsObserver::collisionsBulletMonster(Turn * turn, int i, int j) {
	MonstreStorage::Storage monstresAround = game->getMonstersAround(i, j);
	for (unsigned int k = 0; k < turn->bullets.size(); k++) {
		float bulletX = turn->bullets[k].get()->x;
		float bulletY = turn->bullets[k].get()->y;
		float bulletW = turn->bullets[k].get()->size;
		for (unsigned int t = 0; t < monstresAround.size(); t++) {
			float monstreX = monstresAround[t].get()->getX();
			float monstreY = monstresAround[t].get()->getY();
			float monstreW = monstresAround[t].get()->getWidth();
			float monstreH = monstresAround[t].get()->getHeight();
			if (bulletX < monstreX + monstreW && bulletX + bulletW > monstreX &&
				bulletY < monstreY + monstreH && bulletY + bulletW > monstreY) {
				//collided
				turn->bullets[k].get()->dead = true;
				//to do degat monstre
				game->dealDamageToAnMonsterFromWave(monstresAround[t].get(), turn->bullets[k].get()->damage);
			}

		}
	}
}

void GameEventsObserver::verifyGameState() {
	if (game->lifes <= 0) {
		game->gameOver = true;
		game->pause = true;
	}
	if (game->chapterEnded) {
		game->loadNextLevel();
		game->chapterEnded = false;
		turnStorage->removeAllTurns();
	}
	if (game->wave != NULL) {
		if (game->wave->isEmpty() && !game->gameOver&& game->gameStarted && game->wave->monstreCount == 0) {
			game->levelComplete();
		}
	}
}
