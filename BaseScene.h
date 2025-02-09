#pragma once
class BaseScene {
public:

	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="keys">キー入力</param>
	/// <param name="preKeys">前のフレームのキー入力</param>
	virtual void Update(const char* keys, const char* preKeys);

	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw();
};

