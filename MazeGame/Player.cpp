#include "pch.h"
#include "Player.h"

int x_coord;
int y_coord;

Player::Player() {
	x_coord = 1;
	y_coord = 1;
}

int Player::getX() { return x_coord; }
int Player::getY() { return y_coord; }

void Player::move(int x, int y, int **g) {
	int grid = **g;
	int *x_move = x_coord + x;
	grid[x_move][y_coord + y] = 3;
	grid[x_coord - x][y_coord - y] = 1;
	x_coord = x_coord + x;
	y_coord = y_coord + y;
}


Player::~Player()
{
}
