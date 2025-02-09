#include "Enemy.h"
#include <Novice.h>

void Enemy::Initialisation(float posX, float posY, float speedX, float speedY, float radius,int isAlive) {
	pos_.x = posX;
	pos_.y = posY;
	speed_.x = speedX;
	speed_.y = speedY;
	radius_ = radius;
	isAlive_ = isAlive;
}

void Enemy::Update(){
	if (isAlive_) {
		Move();
	}
}

void Enemy::Move(){
	// 敵の移動処理
	pos_.x += speed_.x;
	pos_.y += speed_.y;

	// 敵の反射処理
	if (pos_.x >= 1280.0f - radius_ || pos_.x <= 0.0f + radius_) {
		speed_.x *= -1.0f;
	}
}

int Enemy::CircleCollisionDetection(Vector2 objectNum1Pos, float objectNum1Radius, Vector2 objectNum2Pos, float objectNum2Radius){

	Vector2 objectNum1ToObjectNum2 = {
		objectNum1Pos.x - objectNum2Pos.x,
		objectNum1Pos.y - objectNum2Pos.y,
	};

	float objectNum1ToObjectNum2Distance =
		sqrtf(powf(objectNum1ToObjectNum2.x, 2.0f) + powf(objectNum1ToObjectNum2.y, 2.0f));

	if (objectNum1ToObjectNum2Distance <= objectNum1Radius + objectNum2Radius) {
		return true;
	} else {
		return false;
	}
}

void Enemy::Draw(){
	if (isAlive_) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(radius_),
			static_cast<int>(radius_),
			0.0f, 0xFF0000FF, kFillModeSolid);
	}
}

Enemy::~Enemy()
{
}