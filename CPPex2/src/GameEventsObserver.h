#pragma once
#include "Game.h"
#include "TurnStorage.h"

class GameEventsObserver {
	Game * game;
	TurnStorage * turnStorage;
	TurnStorage * virtualTrunStorage;
public:
	GameEventsObserver(Game * game_, TurnStorage * trunStorage_, TurnStorage * virtualTrunStorage_) :
		game(game_),
		turnStorage(trunStorage_),
		virtualTrunStorage(virtualTrunStorage_),
		drawVirtual(false)
		{};
	bool drawVirtual;

	void collisionsBulletMonster(Turn * turn, int i, int j);
	void collisions();

	void verifyGameState();

	void refreshVirtual();
	void addTurnPlaces(int i, int j);
	void checkNoneCaseAndAddTurn(int i, int j);
	void virtualDraw();

};