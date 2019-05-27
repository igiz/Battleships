#include "pch.h"
#include "Cell.h"

Cell::Cell():empty(true)
{
}

Ship * Cell::getOccupier()
{
	return ship;
}

void Cell::occupy(Ship* ship)
{
	empty = false;
	this->ship = ship;
}

bool Cell::shoot()
{
	if (!empty) {
		ship->hit();
	}
	return !empty;
}

bool Cell::isHit()
{
	return hit;
}

bool Cell::isEmpty()
{
	return empty;
}
