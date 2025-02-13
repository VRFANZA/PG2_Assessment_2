#pragma once
#include "Actor.h"
#include "Bullet.h"

class Player :public Actor {

public:

	

	//================
	// 包含
	//================
	Bullet* bullet_;

	//==============
	// 関数
	//==============

	// ゲッターロボ
	Vector2 GetPos()override { return pos_; }
	float GetRadius()override { return radius_; }
	int GetIsAlive() { return isAlive_; }
	void SetIsAlive(int isAlive) { this->isAlive_ = isAlive; }

	// コンストラクタ使ってなかったから生存フラグをやっちゃおう
	Player(int isAlive);

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
	/// <param name="keys">キー入力を受け取った変数</param>
	/// <param name="pleKeys">1フレーム前のキー入力を受け取った変数</param>
	void Update(const char* keys, const char* preKeys);

	/// <summary>
	/// 移動関数
	/// </summary>
	/// <param name="keys">キー入力を受け取った変数</param>
	void Move(const char* keys);

	/// <summary>
	/// 発射処理関数
	/// </summary>
	/// <param name="keys">現在フレームのキー入力を受け取った変数</param>
	/// <param name="preKeys">1フレーム前のキー入力を受け取った変数</param>
	void Shoot(const char* keys, const char* preKeys);

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw() override;

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

private:

	// 生存フラグ
	int isAlive_;

	//コントローラー操作用のメンバ変数
	int leftStick0X_ = 0;
	int leftStick0Y_ = 0;
};