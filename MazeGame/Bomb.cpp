#include "pch.h"
#include "Bomb.h"
#include <iostream>
using namespace std;

int bomb_x, bomb_y;
int score = 0;
int activeenemies = 4;
bool playerhit = false;

int** enemyHitArray = new int*[4];


Bomb::Bomb()
{
	for (int row = 0; row < 4; row++)
	{
		enemyHitArray[row] = new int[2];
	}
}

void setBomb_Coord(int x, int y) {
	bomb_x = x;
	bomb_y = y;
}


int** Bomb::dropBomb(int** g, int x, int y) {
	setBomb_Coord(x, y);
	g[bomb_x][bomb_y] = 6;
	return g;
}

void enemyHit(int x, int y, int row) {
	enemyHitArray[row][0] = x;
	enemyHitArray[row][1] = y;
}

int** Bomb::explode(int** g) {
	int a = 0;
	if (g[bomb_x][bomb_y] == 6)
	{
		playerhit = true;
	}

	g[bomb_x][bomb_y] = 5;

	//explosion up
	for (int j = 1; j < 4; j++)
	{
		if (g[bomb_x - j][bomb_y] == 0) {
			g[bomb_x - j][bomb_y] = 5;
		}
		
		if (g[bomb_x - j][bomb_y] == 2) {
			enemyHit(bomb_x - j, bomb_y, a);
			a++;
			score++;
			g[bomb_x - j][bomb_y] = 5;
		}
		
		if (g[bomb_x - j][bomb_y] == 1)
		{
			playerhit = true;
			g[bomb_x - j][bomb_y] = 5;
		}
		
		if(g[bomb_x - j][bomb_y] == 3){
			j = 4;
		}
	}

	//explosion right
	for (int j = 1; j < 4; j++)
	{
		if (g[bomb_x][bomb_y + j] == 0) {
			g[bomb_x][bomb_y + j] = 5;
		}
		
		if (g[bomb_x][bomb_y + j] == 2) {
			enemyHit(bomb_x, bomb_y + j, a);
			a++;
			score++;
			g[bomb_x][bomb_y + j] = 5;
		}
		
		if (g[bomb_x][bomb_y + j] == 1)
		{
			playerhit = true;
			g[bomb_x][bomb_y + j] = 5;
		}
		
		if (g[bomb_x][bomb_y + j] == 3)
		{
			j = 4;
		}
	}

	//explosion down
	for (int j = 1; j < 4; j++)
	{
		if (g[bomb_x + j][bomb_y] == 0) {
			g[bomb_x + j][bomb_y] = 5;
		}
		
		if (g[bomb_x + j][bomb_y] == 2) {
			enemyHit(bomb_x + j, bomb_y, a);
			a++;
			score++;
			g[bomb_x + j][bomb_y] = 5;
		}
		
		if (g[bomb_x + j][bomb_y] == 1)
		{
			playerhit = true;
			g[bomb_x + j][bomb_y] = 5;
		}

		if(g[bomb_x + j][bomb_y] == 3) {
			j = 4;
		}
	}

	//explosion left
	for (int j = 1; j < 4; j++)
	{
		if (g[bomb_x][bomb_y - j] == 0) {
			g[bomb_x][bomb_y - j] = 5;
		}
		
		if (g[bomb_x][bomb_y - j] == 2) {
			enemyHit(bomb_x, bomb_y - j, a);
			a++;
			score++;
			g[bomb_x][bomb_y - j] = 5;
		}
		
		if (g[bomb_x][bomb_y - j] == 1)
		{
			playerhit = true;
			g[bomb_x][bomb_y - j] = 5;
		}
		
		if(g[bomb_x][bomb_y - j] == 3) {
			j = 4;
		}
	}

	//explosion up-right
	for (int j = 1; j < 4; j++)
	{
		if (g[bomb_x - j][bomb_y + j] == 0) {
			g[bomb_x - j][bomb_y + j] = 5;
		}
		
		if (g[bomb_x - j][bomb_y + j] == 2) {
			cout << "Enemy Hit!" << endl;
			enemyHit(bomb_x - j, bomb_y + j, a);
			a++;
			score++;
			g[bomb_x - j][bomb_y + j] = 5;
		}
		
		if (g[bomb_x - j][bomb_y + j] == 1)
		{
			playerhit = true;
			g[bomb_x - j][bomb_y + j] = 5;
		}
		
		if(g[bomb_x - j][bomb_y + j] == 3){
			j = 4;
		}
	}

	//explosion down-right
	for (int j = 1; j < 4; j++)
	{
		if (g[bomb_x + j][bomb_y + j] == 0) {
			g[bomb_x + j][bomb_y + j] = 5;
		}
		
		if (g[bomb_x + j][bomb_y + j] == 2) {
			enemyHit(bomb_x + j, bomb_y + j, a);
			a++;
			score++;
			g[bomb_x + j][bomb_y + j] = 5;
		}
		
		if (g[bomb_x + j][bomb_y + j] == 1)
		{
			playerhit = true;
			g[bomb_x + j][bomb_y + j] = 5;
		}

		if(g[bomb_x + j][bomb_y + j] == 3) {
			j = 4;
		}
	}

	//explosion down-left
	for (int j = 1; j < 4; j++)
	{
		if (g[bomb_x + j][bomb_y - j] == 0) {
			g[bomb_x + j][bomb_y - j] = 5;
		}
		
		if (g[bomb_x + j][bomb_y - j] == 2) {
			enemyHit(bomb_x + j, bomb_y - j, a);
			a++;
			score++;
			g[bomb_x + j][bomb_y - j] = 5;
		}
		
		if (g[bomb_x + j][bomb_y - j] == 1)
		{
			playerhit = true;
			g[bomb_x + j][bomb_y - j] = 5;
		}
		
		if(g[bomb_x + j][bomb_y - j] == 3){
			j = 4;
		}
	}

	//explosion up-left
	for (int j = 1; j < 4; j++)
	{
		if (g[bomb_x - j][bomb_y - j] == 0) {
			g[bomb_x - j][bomb_y - j] = 5;
		}
		
		if (g[bomb_x - j][bomb_y - j] == 2) {
			enemyHit(bomb_x - j, bomb_y - j, a);
			a++;
			score++;
			g[bomb_x - j][bomb_y - j] = 5;
		}
		
		if (g[bomb_x - j][bomb_y - j] == 1)
		{
			playerhit = true;
			g[bomb_x - j][bomb_y - j] = 5;
		}
		
		if(g[bomb_x - j][bomb_y - j] == 3){
			j = 4;
		}
	}

	return g;
}

void Bomb::setHitPlayer(bool x) {
	playerhit = x;
}

bool Bomb::getHitPlayer() {
	return playerhit;
}

bool Bomb::checkHit(int x, int y) {
	for (int i = 0; i < 4; i++)
	{
		if (enemyHitArray[i][0] == x and enemyHitArray[i][1] == y)
		{
			activeenemies--;
			return true;
		}
	}
	return false;
}

void Bomb::resetHitArray() {
	for (int i = 0; i < 4; i++)
	{
		enemyHitArray[i][0] = NULL;
		enemyHitArray[i][1] = NULL;
	}
}

int Bomb::getScore() {
	return score;
}

void Bomb::setScore(int x) {
	score = x;
}

int Bomb::getActiveEnemies() {
	return activeenemies;
}

void Bomb::setActiveEnemies(int count) {
	activeenemies = count;
}

Bomb::~Bomb()
{
}
