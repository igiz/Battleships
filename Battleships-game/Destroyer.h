#pragma once
#ifndef DESTROYER_H
#define DESTROYER_H

#include "Ship.h"

class Destroyer : public Ship {
public:
	Destroyer();
	string name();
};

#endif