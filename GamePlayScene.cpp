#include "GamePlayScene.h"
#include <Novice.h>

GamePlayScene::GamePlayScene() {
	player_ = new Player(true);
	player_->Initialisation(640, 360, 8, 8, 15);

	enemy_ = new Enemy();
	enemy_->Initialisation(640, 100, 5, 0, 25, true);
}

void GamePlayScene::Update(const char* keys, const char* preKeys) {
	// キー入力
	if (keys[DIK_1] && !preKeys[DIK_1]) {
		SceneManager::ChangeScene(SceneManager::TITLE);
	}

	// プレイヤーの更新関数
	player_->Update(keys, preKeys);

	// 敵の更新
	enemy_->Update();

	// プレイヤーと敵の当たり判定
	if (player_->GetIsAlive() && enemy_->isAlive_) {
		if (enemy_->CircleCollisionDetection(enemy_->GetPos(), enemy_->GetRadius(), player_->GetPos(), player_->GetRadius())) {
			player_->SetIsAlive(false);
		}
	}

	// プレイヤーの弾と敵の当たり判定
	if (enemy_->isAlive_) {
		if (enemy_->CircleCollisionDetection(enemy_->GetPos(), enemy_->GetRadius(), player_->bullet_->GetPos(), player_->bullet_->GetRadius())) {
			enemy_->isAlive_ = false;
		}
	}

	// 敵が死んだらクリア画面に行く
	if (!enemy_->isAlive_) {
		SceneManager::ChangeScene(SceneManager::CLEAR);
	}

	// プレイヤーが死んだらゲームオーバー画面に行く
	if (!player_->GetIsAlive()) {
		SceneManager::ChangeScene(SceneManager::GAMEOVER);
	}
}

void GamePlayScene::Draw() {
	// 描画処理
	Novice::ScreenPrintf(0, 0, "GAME");

	// プレイヤーの描画関数
	player_->Draw();

	enemy_->Draw();
}

GamePlayScene::~GamePlayScene() {
	delete player_;
	delete enemy_;
}
