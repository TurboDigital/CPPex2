/*
 * Copyright (C) 2016 Guillaume Perez
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; If not, see <http://www.gnu.org/licenses/>.
*/



#include <iostream>
#include "Engine.h"
#include <chrono>
#include <thread>

#include "MyControlEngine.h"
#include "MyGameEngine.h"
#include "MyGraphicEngine.h"
#include "GameEventsObserver.h"
#include "LoadGame.h"



int main(int argc, char * argv[])
{

	LoadGame load(2,5);
	Game game(&load);
	TurnStorage turnStorage(&game);
	MonstreStorage monstreStorage;
	GameEventsObserver observer(&game, &turnStorage);

	Engine e(argc, argv, game.window_width, game.window_height);
	GraphicEngine * ge = new MyGraphicEngine(&turnStorage, &monstreStorage, &game);
	GameEngine * gme = new MyGameEngine(&turnStorage, &monstreStorage, &game, &observer);
	ControlEngine * ce = new MyControlEngine(&turnStorage, &game);

	e.setGameEngine(gme);
	e.setControlEngine(ce);
	e.setGraphicEngine(ge);

    e.start();

    
    return 0;
    
}

