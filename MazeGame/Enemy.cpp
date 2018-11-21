#include "pch.h"
#include "Enemy.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <random>
using namespace std;

int x_pos, y_pos, direction, placement;
default_random_engine dir_generator;
uniform_int_distribution<int> dir_distribution(1, 4);

default_random_engine place_generator;
uniform_int_distribution<int> place_distribution(1, 20);

Enemy::Enemy()
{
}

void Enemy::genDirection() {
	direction = dir_distribution(dir_generator);
}

void Enemy::genPlacement() {
	placement = dir_distribution(dir_generator);
}

int** Enemy::setPosition(int **g) {
	bool valid = false;
	while (!valid) {
		genPlacement();
		x_pos = placement;
		genPlacement();
		y_pos = placement;
		if (g[x_pos][y_pos] == 0)
		{
			g[x_pos][y_pos] = 3;
			valid = true;
			cout << "Enemy x: " << x_pos << " y: " << y_pos << endl;
		}
	}
	return g;
}

int** Enemy::move(int** g) {
	//1 = up 2 = right 3 = down 4 = left
	bool valid = false;
	while (!valid) {
		genDirection();
		cout << "Random direction: " << direction << endl;
		switch (direction)
		{
		case 1:
			//up
			if (g[x_pos - 1][y_pos] == 0)
			{
				g[x_pos - 1][y_pos] = 3;
				g[x_pos][y_pos] = 0;
				x_pos = x_pos - 1;
				valid = true;
				cout << "Enemy up" << endl;
			}
			break;
		case 2:
			//right
			if (g[x_pos][y_pos + 1] == 0)
			{
				g[x_pos][y_pos + 1] = 3;
				g[x_pos][y_pos] = 0;
				y_pos = y_pos + 1;
				valid = true;
				cout << "Enemy right" << endl;
			}
			break;
		case 3:
			//down
			if (g[x_pos + 1][y_pos] == 0)
			{
				g[x_pos + 1][y_pos] = 3;
				g[x_pos][y_pos] = 0;
				x_pos = x_pos + 1;
				valid = true;
				cout << "Enemy down" << endl;
			}
			break;
		case 4:
			//left
			if (g[x_pos][y_pos - 1] == 0)
			{
				g[x_pos][y_pos - 1] = 3;
				g[x_pos][y_pos] = 0;
				y_pos = y_pos - 1;
				valid = true;
				cout << "Enemy left" << endl;
			}
			break;
		}
	}
	return g;
}


Enemy::~Enemy()
{
}
