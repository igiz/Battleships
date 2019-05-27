#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Ship.h"
#include "Cell.h"
#include "Player.h"

using namespace std;

class Board {
	private:
		Player* player;
		vector<vector<Cell*>> cells;
		vector<Ship*> ships;
		int width;
		int height;
		bool isInBounds(int x, int y);
	public:
		Board(Player* player, int width, int height);
		void shoot(int x, int y);
		void placeShip(int x, int y, Ship* ship, bool horizontal);
		void printState(bool includeShipPositions);
		bool hasLost();
};

#endif