#pragma once
#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Ship.h"

class Battleship : public Ship {
public:
	Battleship();
	string name();
};

#endif