#include "Actor.h"

void Actor::Initialisation(float posX, float posY, float speedX, float speedY, float radius){
	pos_ = { posX,posY };
	speed_ = { speedX,speedY };
	radius_ = radius;
}

void Actor::Update()
{
}

void Actor::Move()
{
}

void Actor::Shoot()
{
}

int Actor::CircleCollisionDetection(Vector2 objectNum1Pos, float objectNum1Radius, Vector2 objectNum2Pos, float objectNum2Radius){

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

void Actor::Draw()
{
}
