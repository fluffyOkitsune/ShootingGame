// Game
#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"
#include "Player.h"
#include "ObjectMng.h"

enum State {
	PRE_INTRO, INTRO, GAME, DIALOG, CLEAR, DIED, GAMEOVER
};

// ゲーム画面クラス
class Game : public BaseScene {
public : 
	Player player;	// 自機
	ObjectMng om;	// 敵と敵弾

	State state;	// 状態

	long time;		// 時間
	int stageID;	// 現在のステージ番号
	int score;		// スコア
	int highScore;	// ハイスコア

	Game::Game(ISceneChanger* changer);

	// 初期化
	void Initialize() override;

	// 更新
	void Update() override;

	// 描画
	void Draw() override;

	// 被弾確認
	bool IsHit();
	bool GetHit();

	// ステージ情報
	void Stage(int ID, int time);

	// ボス登場
	void Boss(int ID);

};