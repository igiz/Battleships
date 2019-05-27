#include "pch.h"
#include"Ship.h"
#include <iostream>
using namespace std;

Ship::Ship(int size) : hitpoints(size) , size(size)
{

}

void Ship::hit()
{
	hitpoints--;
	if (hitpoints <= 0) {
		cout << (this->name()) << " destroyed!";
	}
}

int Ship::getSize()
{
	return size;
}

bool Ship::destroyed()
{
	return hitpoints <= 0;
}
