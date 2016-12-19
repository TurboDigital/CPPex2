#include "MyGameEngine.h"

void MyGameEngine::idle() {

	//to do idle
	//monstreStorage->addMonstre();
	//wait one second
	monstreStorage->forEachMove();
	turnStorage->forEachAttack();
}