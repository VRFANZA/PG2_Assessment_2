#pragma once
#include <Vector2.h>
#include <math.h>

class Actor{

protected:
	//============
	// 変数
	//============
	Vector2 pos_;
	Vector2 speed_;
	float radius_;

public:
	//==============
	// 関数
	//==============

	// ゲッターロボ
	virtual Vector2 GetPos() { return pos_; }
	virtual float GetRadius() { return radius_; }

	/// <summary>
	/// 初期化関数
	/// </summary>
	/// <param name="posX">二次元座標の横の初期値</param>
	/// <param name="posY">二次元座標の縦の初期値</param>
	/// <param name="speedX">横の移動速度</param>
	/// <param name="speedY">縦の移動速度</param>
	/// <param name="radius">オブジェクトの半径</param>
	virtual void Initialisation(float posX, float posY, float speedX,float speedY, float radius);

	/// <summary>
	/// 更新処理関数
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 移動関数
	/// </summary>
	virtual void Move();

	/// <summary>
	/// 発射処理関数
	/// </summary>
	virtual void Shoot();

	/// <summary>
	/// 円同士の当たり判定の関数
	/// </summary>
	/// <param name="objectNum1Pos">1つ目のオブジェクトの二次元座標</param>
	/// <param name="objectNum1Radius">1つ目のオブジェクトの半径</param>
	/// <param name="objectNum2Pos">2つ目のオブジェクトの二次元座標</param>
	/// <param name="objectNum2Radius">2つ目のオブジェクトの半径</param>
	/// <returns>当たっていればtrueを返す</returns>
	virtual int CircleCollisionDetection(Vector2 objectNum1Pos, float objectNum1Radius, Vector2 objectNum2Pos, float objectNum2Radius);

	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw();
};