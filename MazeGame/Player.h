#pragma once
class Player 
{
public:
	Player();
	~Player();
	int getX();
	int getY();
	void move(int, int, int**);
};

