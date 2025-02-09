#pragma once
#include "BaseScene.h"
#include <memory>

class SceneManager {
public:

	/// <summary>
	/// シーン
	/// </summary>
	enum Scene {
		TITLE,
		GAME,
		CLEAR,
		GAMEOVER
	};

	/// <summary>
	/// シーン切り替え関数
	/// </summary>
	/// <param name="scene">切り替え先のシーン</param>
	static void ChangeScene(Scene scene);

	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="keys">キーのプレス</param>
	/// <param name="preKeys">前のフレームのキー入力</param>
	static void Updade(const char* keys, const char* preKeys);

	/// <summary>
	/// 描画関数
	/// </summary>
	static void Draw();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~SceneManager();

private:
	static BaseScene* nowScene_;
};
