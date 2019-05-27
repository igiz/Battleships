#pragma once
#ifndef CELL_H
#define CELL_H

#include"Ship.h"

class Cell {
	private:
		Ship* owner;
		bool empty;
		bool hit;
	public:
		Cell();
		Ship* getOwner();
		void setOwner(Ship* owner);
		bool shoot();
		bool isHit();
};

#endif