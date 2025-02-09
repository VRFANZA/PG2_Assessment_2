#pragma once
#include "BaseScene.h"
#include "Player.h"
#include "Enemy.h"
#include "SceneManager.h"

class GamePlayScene : public BaseScene{
public:
	GamePlayScene();

	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="keys">キー入力</param>
	/// <param name="preKeys">前のフレームのキー入力</param>
	void Update(const char* keys, const char* preKeys) override;

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw() override;

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GamePlayScene();

private:
	Player* player_;
	Enemy* enemy_;
};

