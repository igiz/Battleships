#include "pch.h"
#include "Board.h"
using namespace std;

static string cellMarker = "[ ]";
static string cellMissMarker = "[O]";
static string cellHitMarker = "[X]";
static string cellShipPosition = " # ";
static string emptyCell = "   ";

Board::Board(Player* player, int width, int height) : player(player)
{
	if (width < 5 || height < 5) {
		throw out_of_range("Size of the board must be 5x5 or greater");
	}

	cells.resize(height);

	for (int i = 0; i < height; i++) {
		vector<Cell*> row(width);
		for (int j = 0; j < width; j++) {
			Cell* cell = new Cell();
			row[j] = cell;
		}
		cells[i] = row;
	}

	this->width = width;
	this->height = height;
}

void Board::shoot(int x, int y)
{
	if (isInBounds(x, y)) {
		Cell* cell = cells.at(y).at(x);
		if (cell->isHit()) {
			throw invalid_argument("Cell already hit");
		}
		if (cell->shoot()) {
			cout << "Hit a ship!";
		}
	} else {
		throw out_of_range("Co-ordinates are outside the bounds");
	}
}

void Board::placeShip(int x, int y, Ship* ship, bool horizontal)
{
	int xBounds = x + (horizontal ? ship->getSize()-1 : 0);
	int yBounds = y + (horizontal ? 0 : ship->getSize()-1);

	if (isInBounds(xBounds, yBounds)) {
		if (collides(x, y, xBounds, yBounds)) {
			throw invalid_argument("Ship collides with another ship at this location");
		}
		ships.push_back(ship);
		for (int i = y; i <= yBounds; i++) {
			for (int j = x; j <= xBounds; j++) {
				cells.at(i).at(j)->occupy(ship);
			}
		}
	} else {
		throw out_of_range("Co-ordinates are outside the bounds");
	}
}

void Board::printState(bool showShipPositions)
{

	int widthMiddle = width / 2;
	int heightMiddle = height / 2;

	//Print X axis marker
	for (int i = 0; i < widthMiddle; i++) {
		cout << emptyCell;
	}
	cout << " X " << endl;

	//Print the header
	cout << emptyCell << emptyCell;
	for (int i = 0; i < width; i++) {
		cout << "|" << i << "|";
	}
	cout << endl;

	for (int i = 0; i < height; i++) {
		string axisMarker = i == heightMiddle ? " Y " : emptyCell;
		cout << axisMarker;
		cout << "|" << i << "|";
		for (int j = 0; j < width; j++) {
			string marker;
			Cell* cell = cells.at(i).at(j);
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
		cout << endl;
	}
}

bool Board::hasLost()
{
	bool result = true;
	for (vector<Ship*>::iterator it = ships.begin(); it != ships.end(); it++) {
		if (!(*it)->destroyed()) {
			result = false;
			break;
		}
	}
	return result;
}

Player* Board::getPlayer()
{
	return player;
}

#pragma region  Private Methods

bool Board::isInBounds(int x, int y)
{
	bool result = x <= width && y <= height;
	return result;
}

bool Board::collides(int startX, int startY, int endX, int endY)
{
	bool result = false;
	for (int i = startY; i <= endY && !result; i++) {
		for (int j = startX; j <= endX && !result; j++) {
			Cell* cell = cells.at(i).at(j);
			result = !cell->isEmpty();
		}
	}
	return result;
}

#pragma endregion