#include "Player.h"
#include "Novice.h"

Player::Player(int isAlive){
	isAlive_ = isAlive;
}

void Player::Initialisation(float posX, float posY, float speedX, float speedY, float radius){
	pos_ = { posX,posY };
	speed_ = { speedX,speedY };
	radius_ = radius;

	// 弾クラスのインスタンス生成
	bullet_ = new Bullet;
	bullet_->Initialisation(0.0f, 0.0f, 0.0f, 16.0f, 8.0f);
}

void Player::Update(const char* keys, const char* preKeys){
	if (isAlive_) {
		Move(keys);
		Shoot(keys, preKeys);

		if (bullet_->isShoot_) {
			bullet_->Update();
		}
	}
}

void Player::Move(const char* keys){
	// コントローラー(0)の左ジョイスティックの値の取得
	Novice::GetAnalogInputLeft(0, &leftStick0X_, &leftStick0Y_);

	// 上方向に移動
	if (keys[DIK_W]) {
		pos_.y -= speed_.y;
	} else if (leftStick0Y_ < 0) {
		pos_.y -= speed_.y;
	}

	// 左方向に移動
	if (keys[DIK_A]) {
		pos_.x -= speed_.x;
	} else if (leftStick0X_ < 0) {
		pos_.x -= speed_.x;
	}

	// 下方向に移動
	if (keys[DIK_S]) {
		pos_.y += speed_.y;
	} else if (leftStick0Y_ > 0) {
		pos_.y += speed_.y;
	}

	// 右方向に移動
	if (keys[DIK_D]) {
		pos_.x += speed_.x;
	} else if (leftStick0X_ > 0) {
		pos_.x += speed_.y;
	}
}

void Player::Shoot(const char* keys, const char* preKeys){
	// 発射処理
	if (!bullet_->isShoot_) {
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			bullet_->isShoot_ = true;
			// 弾をプレイヤーの位置で初期化
			bullet_->SetPosX_(pos_.x);
			bullet_->SetPosY_(pos_.y);

		} else if (Novice::IsTriggerButton(0, kPadButton11)) {// コントローラー(0)のRTのトリガーを取得
			bullet_->isShoot_ = true;
			// 弾をプレイヤーの位置で初期化
			bullet_->SetPosX_(pos_.x);
			bullet_->SetPosY_(pos_.y);
		}
	}
}

void Player::Draw(){

	// 弾をプレイヤーの下に描画
	if (bullet_->isShoot_) {
		bullet_->Draw();
	}

	// プレイヤーの描画
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f, 0xFFFFFFFF, kFillModeSolid);	
}

Player::~Player(){
	delete bullet_;
}
