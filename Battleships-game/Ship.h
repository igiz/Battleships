#pragma once
#ifndef SHIP_H
#define SHIP_H

class Ship {
	public:
		Ship(int hitpoints, int size);
		void hit();
		int getSize();
		virtual void desribe() = 0;
	protected:
		int hitpoints;
		int size;
};

#endif