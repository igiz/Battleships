#include "pch.h"
#include "Cell.h"

Cell::Cell():empty(true)
{
}

Ship * Cell::getOwner()
{
	return owner;
}

void Cell::setOwner(Ship* owner)
{
	empty = false;
	this->owner = owner;
}

bool Cell::shoot()
{
	if (!empty) {
		owner->hit();
	}
	return !empty;
}

bool Cell::isHit()
{
	return hit;
}
