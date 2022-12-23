#pragma once

class Enemy
{
private:
	int PosX_;
	int PosY_;
	int radius_;

public:

	void Initialize();

	void Draw();

	int GetPosX() { return PosX_; }
	int GetPosY() { return PosY_; }
	int GetRadius() { return radius_; }
};

