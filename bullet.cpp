#include "bullet.h"
#include "Novice.h"

void Bullet::Initialize()
{
	PosX_ = 100;
	PosY_ = 100;
	radius_ = 8;
	speed_ = 15;
	isBulletShot_ = 0;
}

void Bullet::Shot() {
	if (isBulletShot_ == 1) {
		PosY_ = PosY_ - speed_;
		if (PosY_ <= 0) {
			isBulletShot_ = 0;
		}
	}
}


void Bullet::Draw()
{
	if (isBulletShot_) {
		Novice::DrawEllipse(PosX_, PosY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);

	}
}