#pragma once
#include "Actor.h"

class Bullet :public Actor {
public:

	// アクセッサ
	void SetPosX_(float posX) { this->pos_.x = posX; }
	void SetPosY_(float posY) { this->pos_.y = posY; }

	// ゲッターロボ
	Vector2 GetPos()override { return pos_; }
	float GetRadius()override { return radius_; }

	// 発射フラグ
	int isShoot_ = false;

	//==============
	// 関数
	//==============

	/// <summary>
	/// 初期化関数
	/// </summary>
	/// <param name="posX">二次元座標の横の初期値</param>
	/// <param name="posY">二次元座標の縦の初期値</param>
	/// <param name="speedX">横の移動速度</param>
	/// <param name="speedY">縦の移動速度</param>
	/// <param name="radius">オブジェクトの半径</param>
	void Initialisation(float posX, float posY, float speedX, float speedY, float radius) override;

	/// <summary>
	/// 更新関数
	/// </summary>
	void Update() override;

	/// <summary>
	/// 弾の弾道の関数
	/// </summary>
	void Move() override;
	
	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw() override;

};

