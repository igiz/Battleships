#pragma once
#ifndef CRUISER_H
#define CRUISER_H

#include "Ship.h"

class Cruiser : public Ship {
public:
	Cruiser();
	string name();
};

#endif