#pragma once
#include "Actor.h"
#include "Player.h"
#include "math.h"

class Enemy :public Actor{

public:
	//==============
	// 変数
	//==============
	int isAlive_;

	//==============
	// 関数
	//==============

	// ゲッターロボ
	Vector2 GetPos()override { return pos_; }
	float GetRadius()override { return radius_; }

	/// <summary>
	/// 初期化関数
	/// </summary>
	/// <param name="posX">二次元座標の横の初期値</param>
	/// <param name="posY">二次元座標の縦の初期値</param>
	/// <param name="speedX">横の移動速度</param>
	/// <param name="speedY">縦の移動速度</param>
	/// <param name="radius">オブジェクトの半径</param>
	void Initialisation(float posX, float posY, float speedX, float speedY, float radius ,int iaAlove);

	/// <summary>
	/// 更新関数
	/// </summary>
	void Update() override;

	/// <summary>
	/// 移動関数
	/// </summary>
	void Move();

	/// <summary>
	/// 円同士の当たり判定の関数
	/// </summary>
	/// <param name="objectNum1Pos">1つ目のオブジェクトの二次元座標</param>
	/// <param name="objectNum1Radius">1つ目のオブジェクトの半径</param>
	/// <param name="objectNum2Pos">2つ目のオブジェクトの二次元座標</param>
	/// <param name="objectNum2Radius">2つ目のオブジェクトの半径</param>
	/// <returns>当たっていればtrueを返す</returns>
	int CircleCollisionDetection(Vector2 objectNum1Pos,float objectNum1Radius,Vector2 objectNum2Pos,float objectNum2Radius)override;

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw() override;

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Enemy();
};

