#pragma once
#ifndef AIRCRAFTCARRIER_H
#define AIRCRAFTCARRIER_H

#include "Ship.h"

class AircraftCarrier : public Ship {
	public:
		AircraftCarrier();
		string name();
};

#endif