#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"
#include "Player.h"

#define NUM_BULLET_OBJ	20

//ゲーム画面クラス
class Game : public BaseScene {
public :
	// 自機
	Player p;

	// 弾丸
	Bullet bullet[NUM_BULLET_OBJ];

	// 弾丸ID
	int bulletID;

	// コンストラクタ
    Game::Game(ISceneChanger* changer);

	//初期化処理をオーバーライド。
    void Initialize() override;

	//終了処理をオーバーライド。
    //void Finalize() override;

	//更新処理をオーバーライド。
    void Update() override;

	//描画処理をオーバーライド。
    void Draw() override;
	
	// 射撃
	void Shoot();

};
