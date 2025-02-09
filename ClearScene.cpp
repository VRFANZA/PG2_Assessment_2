#include "ClearScene.h"
#include <Novice.h>

void ClearScene::Update(const char* keys, const char* preKeys){
	// キー入力
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		SceneManager::ChangeScene(SceneManager::TITLE);
	}
}

void ClearScene::Draw(){
	// 描画処理
	Novice::ScreenPrintf(0, 0, "Clear:SPACEtoTITLE");
}
