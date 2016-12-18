#pragma once
#include <memory>
#include <vector>
#include "Turn.h"
class TurnStorage {
	
	
public:

	TurnStorage(int i) :
		turns(i) 
	{}

	typedef std::vector<std::shared_ptr<Turn>> Storage;

	void addTurn(std::shared_ptr<Turn> const& turn);

	void forEachDraw();

	void forEachAttack();

	int getSize();

	void removeTurn(int i, int j);

private:
	Storage turns;
};
