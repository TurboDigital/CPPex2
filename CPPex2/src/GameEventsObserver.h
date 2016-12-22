#pragma once
#include "Game.h"
#include "TurnStorage.h"

class GameEventsObserver {
	Game * game;
	TurnStorage * turnStorage;
public:
	GameEventsObserver(Game * game_, TurnStorage * trunStorage_) :
		game(game_),
		turnStorage(trunStorage_)
		{};

	void collisionsBulletMonster(Turn * turn, int i, int j);
	void collisions();

	void verifyGameState();
};