#pragma once
#include"bullet.h"

class Player
{
private:
	int PosX_;
	int PosY_;
	int radius_;
	int speed_;
	int color_;

	Bullet* bullet_;

public:

	void Initialize();

	void Move(char* keys);

	void Shot(char* keys, char* preKeys);
	void Update(char* keys, char* preKeys);


	void Draw();

	

	void OnCollision();

	


	int GetPosX() { return PosX_; }
	int GetPosY() { return PosY_; }
	int GetRadius() { return radius_; }
};


