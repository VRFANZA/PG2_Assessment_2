#include "TitleScene.h"
#include <Novice.h>

void TitleScene::Update(const char* keys, const char* preKeys) {
	// キー入力
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		SceneManager::ChangeScene(SceneManager::GAME);
	}
}

void TitleScene::Draw() {
	// 描画処理
	Novice::ScreenPrintf(0, 0, "TITLE:SPACEtoGAME");
}
