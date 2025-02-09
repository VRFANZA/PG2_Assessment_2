#include "Bullet.h"
#include <Novice.h>

void Bullet::Initialisation(float posX, float posY, float speedX, float speedY, float radius){
	pos_ = { posX,posY };
	speed_ = { speedX,speedY };
	radius_ = radius;
}

void Bullet::Update(){
	Move();
}

void Bullet::Move(){
	pos_.y -= speed_.y;

	if (pos_.y <= 0 - radius_) {
		isShoot_ = false;
	}
}

void Bullet::Draw(){
	if (isShoot_) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(radius_),
			static_cast<int>(radius_),
			0.0f, 0x00FF00FF, kFillModeSolid);
	}
}
