#include "enemy.h"
#include "Novice.h"

void Enemy::Initialize()
{
	PosX_ = 200;
	PosY_ = 200;
	radius_ = 16;
}



void Enemy::Draw()
{

	Novice::DrawEllipse(PosX_, PosY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
}
