#include "MyGameEngine.h"

void MyGameEngine::idle() {

	//to do idle
	//monstreStorage->addMonstre();
	//wait one second
	//monstreStorage->forEachMove();
	
	if (!game->pause) {
		turnStorage->forEachAttack();
		turnStorage->forEachAttack();
		if (game->wave != NULL) {
			game->wave->createWave();
			game->wave->monstreStorage.forEachMove();
		}
	}
	
}