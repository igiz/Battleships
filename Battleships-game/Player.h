#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include<string> 
using namespace std;

class Player {
	public:
		Player(string name);
		string getName();
	private:
		string name;
};

#endif