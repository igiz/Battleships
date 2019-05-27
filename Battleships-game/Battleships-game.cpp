// Battleships-game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include "Player.h"
#include "Board.h"
#include "Ship.h"
#include "AircraftCarrier.h"
#include <iostream>
#include <string> 
using namespace std;

Ship* createShip(string name);

int main()
{
	int boardSize;
	Board* boards[2] = {};
	string fleet[2] = { "Carrier","Carrier" };
	size_t fleetLength = sizeof(fleet) / sizeof(fleet[0]);

	cout << "Battleships : Legends never die" << endl;
	cout << "Enter board size: (N = N x N board)" << endl;
	cin >> boardSize;

	for (int i = 0; i < 2; i++) {
		// Setup player information
		string name;
		cout << "Enter player " << (i + 1) << " name" << endl;
		cin >> name;
		Player* player = new Player(name);
		Board* playerBoard = new Board(player, boardSize, boardSize);
		cout << name << " place your ships..." << endl;

		//Place ships
		for (size_t j = 0; j < fleetLength; j++) {
			do {
				try {
					int x;
					int y;
					bool horizontal;

					//Collect co-ordinates
					cout << "Type X co-ordinates for your " + fleet[j] << endl;
					cin >> x;
					cout << "Type Y co-ordinates for your " + fleet[j] << endl;
					cin >> y;
					cout << "Horizontal(1) or Vertical(0)?" << endl;
					cin >> horizontal;

					//Create and save ship
					Ship* ship = createShip(fleet[j]);
					playerBoard->placeShip(x, y, ship, horizontal);

					cout << "Ship placed , board looks like:" << endl;
					//Print current state of the board
					playerBoard->printState(true, true);

					break;
				}
				catch (exception& ex) {
					cout << ex.what() << endl;
				}
			} while (true);

			//Save board for the game

		}
		boards[i] = playerBoard;
	}


	//Gameplay loop
	int currentPlayer = 0;
	int enemy = 1;
	do {
		Board* enemyBoard = boards[enemy];
		cout << "Its " << boards[currentPlayer]->getPlayer()->getName() << " turn." << endl;
		cout << "Current state of the enemy board:" << endl;
		enemyBoard->printState(false, false);

		do {
			try {
				int x;
				int y;
				cout << "Enter co-ordinates to shoot:" << endl;
				cout << "X co-ordinate:" << endl;
				cin >> x;
				cout << "Y co-ordinate:" << endl;
				cin >> y;
				enemyBoard->shoot(x, y);
				break;
			}
			catch (exception& ex) {
				cout << ex.what() << endl;
			}
		} while (true);

		if (enemyBoard->hasLost()) {
			cout << "All enemy ships destroyed! The winner is " << boards[currentPlayer]->getPlayer()->getName() << endl;
			break;
		} else {
			int temp = enemy;
			enemy = currentPlayer;
			currentPlayer = temp;
		}
	} while (true);
}

Ship* createShip(string name) {

	if (name == "Carrier") {
		return new AircraftCarrier();
	} else {
		throw invalid_argument("Unknown ship type");
	}
}
