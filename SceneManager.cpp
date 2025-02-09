#include "SceneManager.h"
#include <Novice.h>
#include "TitleScene.h"
#include "GamePlayScene.h"
#include "ClearScene.h"
#include "GameOver.h"

// シーンを格納する場所を空の状態で生成
BaseScene* SceneManager::nowScene_ = nullptr;

void SceneManager::ChangeScene(Scene scene) {

	nowScene_ = nullptr;
	delete nowScene_;

	switch (scene){

	case SceneManager::TITLE:
		nowScene_ = new TitleScene();

		break;

	case SceneManager::GAME:
		nowScene_ = new GamePlayScene();

		break;

	case SceneManager::CLEAR:
		nowScene_ = new ClearScene();

		break;

	case SceneManager::GAMEOVER:
		nowScene_ = new GameOver();

		break;

	default:
		break;
	}

}

void SceneManager::Updade(const char* keys, const char* preKeys) {
	nowScene_->Update(keys, preKeys);
}

void SceneManager::Draw() {
	nowScene_->Draw();
}

SceneManager::~SceneManager() {
}
