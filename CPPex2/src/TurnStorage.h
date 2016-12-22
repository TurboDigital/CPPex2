#pragma once
#include <memory>
#include <vector>
#include "Turn.h"
#include "Game.h"

class TurnStorage {
	
	Game * game;
	
public:
	
	TurnStorage(Game * game_) :
		game(game_),
		turns() 
	{}

	typedef std::vector<std::shared_ptr<Turn>> Storage;

	void addTurn(std::shared_ptr<Turn> const& turn);

	void forEachDraw();

	void forEachDrawBullets();

	void forEachAttack();

	int getSize();

	void removeAllTurns();

	void removeTurn(int i, int j);

	Storage turns;
};
