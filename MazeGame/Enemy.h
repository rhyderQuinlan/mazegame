#pragma once
class Enemy
{
	int x_pos, y_pos;
	bool active = false;
public:
	Enemy();
	~Enemy();
	int** spawn(int**);
	int genPlacement(int);
	int** move(int**);
	void setHitPlayer(bool);
	bool getHit();
	int getX_pos();
	int getY_pos();
	void setActive(bool);
	bool getActive();
};

