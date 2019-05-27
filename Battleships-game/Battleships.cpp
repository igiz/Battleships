#include "pch.h"
#include "Player.h"
#include "Board.h"
#include "Ship.h"

// ##  Ship Types  ##
#include "Carrier.h"
#include "Destroyer.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Submarine.h"

#include <iostream>
#include <string> 
using namespace std;

Ship* createShip(string name);

int main()
{
	int boardSize;
	Board* boards[2] = {};

	//This is the starting fleet for each player.
	string fleet[6] = { "CARRIER", "BATTLESHIP", "SUBMARINE","CRUISER","DESTROYER", "DESTROYER"};
	size_t fleetLength = sizeof(fleet) / sizeof(fleet[0]);

	cout << "Battleships : Legends never die" << endl;
	cout << "Enter board size (N = N x N board):";
	cin >> boardSize;

	for (int i = 0; i < 2; i++) {
		// Setup player information
		string name;
		cout << endl<< "Enter Player " << (i + 1) << " name:";
		cin >> name;
		Player* player = new Player(name);
		Board* playerBoard = new Board(player, boardSize, boardSize);
		cout << endl << name << ", its time to place your fleet. This is the playing board." << endl;
		playerBoard->printState(true);
		cout << endl;

		//Place ships
		for (size_t j = 0; j < fleetLength; j++) {
			do {
				try {
					int x;
					int y;
					bool horizontal;

					//Collect co-ordinates
					cout << "Type co-ordinates for the " + fleet[j] + " :" << endl;
					cout << "X:";
					cin >> x;
					cout << "Y:";
					cin >> y;
					cout << endl << "Horizontal(1) or Vertical(0)?" << endl;
					cin >> horizontal;

					//Create and save ship
					Ship* ship = createShip(fleet[j]);
					playerBoard->placeShip(x, y, ship, horizontal);

					cout << "Ship placed:" << endl;
					//Print current state of the board
					playerBoard->printState(true);

					break;
				}
				catch (exception& ex) {
					cout << ex.what() << endl;
				}
			} while (true);
		}
		//Save board for the game
		boards[i] = playerBoard;
	}


	//Gameplay loop
	int currentPlayer = 0;
	int enemy = 1;
	do {
		Board* enemyBoard = boards[enemy];
		cout << "Its your turn, " << boards[currentPlayer]->getPlayer()->getName() << "." << endl;
		cout << "Shots made so far:" << endl;
		enemyBoard->printState(false);

		do {
			try {
				int x;
				int y;
				cout << "Enter co-ordinates to shoot:" << endl;
				cout << "X:";
				cin >> x;
				cout << "Y:";
				cin >> y;
				cout << endl;
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

//Factory function for ships
Ship* createShip(string name) {

	//"CARRIER", "BATTLESHIP", "SUBMARINE","CRUISER","DESTROYER"
	if (name == "CARRIER") {
		return new Carrier();
	} else if (name == "BATTLESHIP") {
		return new Battleship();
	} else if (name == "SUBMARINE") {
		return new Submarine();
	} else if (name == "CRUISER") {
		return new Cruiser();
	} else if (name == "DESTROYER") {
		return new Destroyer();
	}
}
