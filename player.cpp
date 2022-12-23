#include "player.h"
#include "Novice.h"

void Player::Initialize()
{
	 PosX_ = 300;
	 PosY_ = 300;
	 radius_ = 16;
	 speed_ = 5;
	 bullet_ = new Bullet;
	 bullet_->Initialize();
}



void Player::Move(char* keys)
{
	if (PosX_ >= 1280 - radius_) {
		PosX_ = 1280 - radius_;
	}
	if (PosX_ <=  radius_) {
		PosX_ =  radius_;
	}
	if (PosY_ <= radius_) {
		PosY_ = radius_;
	}
	if (PosY_ >= 720 - radius_) {
		PosY_ = 720 - radius_;
	}

	if (keys[DIK_W] != 0) {
		PosY_ -= speed_;
	}
	if (keys[DIK_S] != 0) {
		PosY_ += speed_;
	}
	
	if (keys[DIK_D] != 0) {
		PosX_ += speed_;
	}
	if (keys[DIK_A] != 0) {
		PosX_ -= speed_;
	}
	
}
void Player::Update(char* keys, char* preKeys) {
	Move(keys);
	if (keys[DIK_SPACE] &&
		preKeys[DIK_SPACE] == 0 &&
		bullet_->isBulletShot_ == 0) {
		bullet_->isBulletShot_ = 1;
		bullet_->PosX_ = PosX_;
		bullet_->PosY_ = PosY_;
		
	}
	bullet_->Shot();

	color_ = BLUE;
}


void Player::Draw()
{
	Novice::DrawEllipse(PosX_, PosY_, radius_, radius_, 0.0f, color_, kFillModeSolid);
	bullet_->Draw();
}

void Player::OnCollision()
{

	color_ = GREEN;
}