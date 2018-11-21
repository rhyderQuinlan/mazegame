#pragma once
class Enemy
{
public:
	Enemy();
	~Enemy();
	int** setPosition(int**);
	void genDirection();
	void genPlacement();
	int** move(int**);
};

