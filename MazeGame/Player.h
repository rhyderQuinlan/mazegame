#pragma once
class Player
{
public:
	Player();
	~Player();
	int** p_spawn(int**);
	int getX();
	int getY();
	int** move(int, int, int**);
	void randGenerator();
	void minusLife();
	int getLives();
};

