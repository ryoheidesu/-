#pragma once

class Bullet
{
private:

public:
	int PosX_;
	int PosY_;
	int radius_;
	int speed_;
	int isBulletShot_;

	void Initialize();


	void Draw();
	void Update();

	void Shot();


};

