#pragma once
class Player 
{
public:
	Player();
	~Player();
	int** setPosition(int**);
	int getX();
	int getY();
	int** move(int, int, int**);
	void randGenerator();
};

