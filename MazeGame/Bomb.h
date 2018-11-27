#pragma once
class Bomb
{
public:
	Bomb();
	~Bomb();
	int** dropBomb(int**, int, int);
	int** explode(int**);
	bool checkHit(int, int);
	void resetHitArray();
	int getScore();
	void setScore(int);
	int getActiveEnemies();
	void setActiveEnemies(int);
	void setHitPlayer(bool);
	bool getHitPlayer();
};

