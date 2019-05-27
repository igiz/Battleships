#include "Board.h"
using namespace std;

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
	int addX = horizontal ? ship->getSize() : 0;
	int addY = horizontal ? 0 : ship->getSize();

	if (isInBounds(x+addX, y+addY)) {
		
	} else {
		throw out_of_range("Negaliojancios koordinates.");
	}
}

void Board::printState()
{
	for (int i = 0; i < width; i++) {
		for (int y = 0; y < height; y++) {
			Cell* cell = cells.at(i).at(y);
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
