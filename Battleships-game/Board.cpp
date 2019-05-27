#include "Board.h"
using namespace std;

static string cellMarker = "[ ]";
static string cellMissMarker = "[O]";
static string cellHitMarker = "[X]";
static string cellShipPosition = " * ";

Board::Board(Player* player, int width, int height) : player(player)
{
	if (width < 5 || height < 5) {
		throw out_of_range("Size of the board must be 5x5 or greater");
	}

	for (int i = 0; i < width; i++) {
		for (int y = 0; y < height; y++) {
			Cell cell = Cell::Cell();
			vector<Cell*> column = cells.at(i);
			column.insert(column.begin() + y, &cell);
		}
	}

	this->width = width;
	this->height = height;
}

void Board::shoot(int x, int y)
{
	if (isInBounds(x, y)) {
		Cell* cell = cells.at(x).at(y);
		if (cell->isHit()) {
			throw invalid_argument("Cell already hit");
		}
		cell->shoot();
		cout << "Hit a ship!";
	} else {
		throw out_of_range("Co-ordinates are outside the bounds");
	}
}

void Board::placeShip(int x, int y, Ship* ship, bool horizontal)
{
	int xBounds = x + (horizontal ? ship->getSize() : 0);
	int yBounds = y + (horizontal ? 0 : ship->getSize());

	if (isInBounds(xBounds, yBounds)) {
		ships.push_back(ship);
		for (int i = x; i <= xBounds; i++) {
			for (int j = y; y <= yBounds; y++) {
				cells.at(i).at(y)->occupy(ship);
			}
		}
	} else {
		throw out_of_range("Co-ordinates are outside the bounds");
	}
}

void Board::printState(bool showShipPositions)
{
	cout << "Current state of " << player->getName() << " board" << endl;

	for (int y = 0; y < height; y++) {
		cout << '|| ';
		for (int i = 0; i < width; i++) {
			string marker;
			Cell* cell = cells.at(i).at(y);
			if (cell->isEmpty() && cell->isHit()) {
				marker = cellMissMarker;
			} else if (cell->isHit()) {
				marker = cellHitMarker;
			} else if(showShipPositions && !cell->isEmpty()) {
				marker = cellShipPosition;
			} else {
				marker = cellMarker;
			}
			cout << marker;
		}
		cout << ' ||' << endl;
	}
}

bool Board::hasLost()
{
	bool result = true;
	for (vector<Ship*>::iterator it = ships.begin(); it != ships.end(); it++) {
		if (!(*it)->destroyed) {
			result = false;
			break;
		}
	}
}

#pragma region  Private Methods

bool Board::isInBounds(int x, int y)
{
	bool result = x <= width && y <= height;
	return result;
}

#pragma endregion
