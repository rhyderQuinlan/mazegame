#include "pch.h"
#include "Enemy.h"
#include "Player.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <random>
#include <ctime>
using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace sf;

default_random_engine e_generator;
uniform_int_distribution<int> place_distribution(1, 19);

bool hitplayer = false;

Enemy::Enemy() {
}

int Enemy::genPlacement(int p) {
	p = place_distribution(e_generator);
	return p;
}

void Enemy::setHitPlayer(bool x) {
	hitplayer = x;
}

bool Enemy::getHit() {
	return hitplayer;
}

int Enemy::getX_pos() {
	return x_pos;
}

int Enemy::getY_pos() {
	return y_pos;
}

int** Enemy::spawn(int **g) {
	active = true;
	int placement = 0;
	bool valid = false;
	while (!valid) {
		placement = genPlacement(placement);
		x_pos = placement;
		placement = genPlacement(placement);
		y_pos = placement;
		if (g[x_pos][y_pos] == 0)
		{
			g[x_pos][y_pos] = 2;
			valid = true;
			cout << "Enemy x: " << x_pos << " y: " << y_pos << endl;
		}
	}
	return g;
}

int** Enemy::move(int** g) {
	uniform_int_distribution<int> dir_distribution(1, 4);
	//1 = up 2 = right 3 = down 4 = left	
	if (g[x_pos - 1][y_pos] == 1
		or g[x_pos][y_pos + 1] == 1
		or g[x_pos + 1][y_pos] == 1
		or g[x_pos][y_pos - 1] == 1)
	{
		setHitPlayer(true);
	}
	else if (g[x_pos - 1][y_pos] != 0
		and g[x_pos][y_pos + 1] != 0
		and g[x_pos + 1][y_pos] != 0
		and g[x_pos][y_pos - 1] != 0) {
		//wait to move
	}
	else {
		int direction = 0;
		bool valid = false;
		while (!valid) {
			direction = dir_distribution(e_generator);
			switch (direction)
			{
			case 1:
				//up
				if (g[x_pos - 1][y_pos] == 0)
				{
					g[x_pos - 1][y_pos] = 2;
					g[x_pos][y_pos] = 0;
					x_pos = x_pos - 1;
					valid = true;
				}
				else if (g[x_pos - 1][y_pos] == 1) {
					cout << "Hit player!" << endl;
					setHitPlayer(true);
				}
				break;
			case 2:
				//right
				if (g[x_pos][y_pos + 1] == 0)
				{
					g[x_pos][y_pos + 1] = 2;
					g[x_pos][y_pos] = 0;
					y_pos = y_pos + 1;
					valid = true;
				}
				else if (g[x_pos][y_pos + 1] == 1) {
					cout << "Hit player!" << endl;
					setHitPlayer(true);
				}
				break;
			case 3:
				//down
				if (g[x_pos + 1][y_pos] == 0)
				{
					g[x_pos + 1][y_pos] = 2;
					g[x_pos][y_pos] = 0;
					x_pos = x_pos + 1;
					valid = true;
				}
				else if (g[x_pos + 1][y_pos] == 1) {
					cout << "Hit player!" << endl;
					setHitPlayer(true);
				}
				break;
			case 4:
				//left
				if (g[x_pos][y_pos - 1] == 0)
				{
					g[x_pos][y_pos - 1] = 2;
					g[x_pos][y_pos] = 0;
					y_pos = y_pos - 1;
					valid = true;
				}
				else if (g[x_pos][y_pos - 1] == 1) {
					cout << "Hit player!" << endl;
					setHitPlayer(true);
				}
				break;
			}
		}
	}
	return g;
}

void Enemy::setActive(bool h) {
	if (h)
	{
		active = false;
	}
}

bool Enemy::getActive() {
	return active;
}


Enemy::~Enemy()
{
}
