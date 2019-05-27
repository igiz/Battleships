#pragma once
#ifndef CARRIER_H
#define CARRIER_H

#include "Ship.h"

class Carrier : public Ship {
	public:
		Carrier();
		string name();
};

#endif