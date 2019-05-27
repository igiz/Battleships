#pragma once
#ifndef CELL_H
#define CELL_H

#include"Ship.h"

class Cell {
	private:
		Ship* ship;
		bool empty;
		bool hit;
	public:
		Cell();
		Ship* getOccupier();
		void occupy(Ship* ship);
		bool shoot();
		bool isHit();
		bool isEmpty();
};

#endif