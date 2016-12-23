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
	if (game->currentChapter == MAX_CHAPTER) {
		game->gameWin = true;
		game->nextLevelMenu = false;
	}
	if (game->lifes <= 0) {
		game->gameOver = true;
		game->pause = true;
	}
	if (game->chapterEnded && !game->gameWin && !game->gameOver) {
		game->loadNextLevel();
		game->chapterEnded = false;
		game->gold = START_GOLD;
		turnStorage->removeAllTurns();
	}
	if (game->wave != NULL) {
		if (game->wave->isEmpty() && !game->gameOver&& game->gameStarted && game->wave->monstreCount == 0) {
			game->levelComplete();
		}
	}
}

void GameEventsObserver::virtualDraw() {
	virtualTrunStorage->forEachDraw();
}

void GameEventsObserver::refreshVirtual() {
	virtualTrunStorage->removeAllTurns();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < game->m; j++) {
			if (game->grid[i][j] == Game::CreatureType::ROAD) {
				addTurnPlaces(i, j);
			}
		}
	}
}

void GameEventsObserver::addTurnPlaces(int i, int j) {
	checkNoneCaseAndAddTurn(i - 1, j - 1);
	checkNoneCaseAndAddTurn(i - 1, j);
	checkNoneCaseAndAddTurn(i - 1, j + 1);
	checkNoneCaseAndAddTurn(i, j - 1);
	checkNoneCaseAndAddTurn(i, j + 1);
	checkNoneCaseAndAddTurn(i + 1, j - 1);
	checkNoneCaseAndAddTurn(i + 1, j);
	checkNoneCaseAndAddTurn(i + 1, j + 1);
}


void GameEventsObserver::checkNoneCaseAndAddTurn(int i, int j) {
	if (i >= 0 && j <= game->m && i < 10 && j >= 0) {
		if (game->grid[i][j] == Game::CreatureType::TURN) {
			//if(!virtualTrunStorage->exists(j, i))
			virtualTrunStorage->addTurn(std::make_shared<Turn>(Turn(game,j, i, game->n, game->m, 0.67f, 1.0f, 0.18f, 0.2f)));
		}
	}
}

