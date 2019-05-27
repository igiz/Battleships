#pragma once
#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Ship.h"

class Submarine : public Ship {
public:
	Submarine();
	string name();
};

#endif