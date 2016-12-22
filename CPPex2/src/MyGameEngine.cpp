#include "MyGameEngine.h"

void MyGameEngine::idle() {

	if (!game->pause) {
		observer->collisions();
		observer->verifyGameState();
		turnStorage->forEachAttack();
		if (game->wave != NULL) {
			game->wave->createWave(game->level, game->loadGame->getLife(game->level-1), game->loadGame->getSpeed(game->level-1), game->loadGame->getArmor(game->level-1));
			game->lifes -= game->wave->getArrivedMonsters();
			game->wave->monstreStorage.deleteDeadMonsters();
			game->wave->monstreStorage.forEachMove();
		}
	}
	
}