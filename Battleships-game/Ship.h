#pragma once
#ifndef SHIP_H
#define SHIP_H

#include<string> 
using namespace std;

class Ship {
	public:
		Ship(int size);
		void hit();
		int getSize();
		bool destroyed();
		virtual string name() = 0;
	protected:
		int hitpoints;
		int size;
};

#endif