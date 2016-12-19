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

int main(int argc, char * argv[])
{
	Engine e(argc, argv, 600, 600);

	Grid grid(14,14);
	TurnStorage turnStorage(0);
	MonstreStorage monstreStorage(0);
	monstreStorage.addMonstre(std::make_shared<Monstre>(Monstre(-0.4f, 0.9f, 100, 0.0009f, 14, 14, 7.0f, 7.0f, 0.0f)));
	monstreStorage.addMonstre(std::make_shared<Monstre>(Monstre(-0.4f, 1.0f, 100, 0.0009f, 14, 14, 7.0f, 7.0f, 0.0f)));
	monstreStorage.addMonstre(std::make_shared<Monstre>(Monstre(-0.4f, 1.1f, 100, 0.0009f, 14, 14, 7.0f, 7.0f, 0.0f)));

	GraphicEngine * ge = new MyGraphicEngine(&grid, &turnStorage, &monstreStorage);
	GameEngine * gme = new MyGameEngine(&grid, &turnStorage, &monstreStorage);
	ControlEngine * ce = new MyControlEngine(&grid,&turnStorage);

	e.setGameEngine(gme);
	e.setControlEngine(ce);
	e.setGraphicEngine(ge);

    e.start();

    
    return 0;
    
}

