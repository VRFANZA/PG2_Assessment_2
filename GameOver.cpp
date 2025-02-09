#include "GameOver.h"
#include <Novice.h>

void GameOver::Update(const char* keys, const char* preKeys){
	// キー入力
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		SceneManager::ChangeScene(SceneManager::TITLE);
	}
}

void GameOver::Draw(){
	// 描画処理
	Novice::ScreenPrintf(0, 0, "GameOver:SPACEtoTITLE");
}
