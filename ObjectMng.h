// Game -> ObjectMng
#pragma once

#include "Task.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Effect.h"
#include "Player.h"
#include "DxLib.h"

// 敵オブジェの数
#define NUM_ENEMY_OBJ			20

// 敵弾の数
#define NUM_ENEMY_BULLET_OBJ	50

// エフェクトの数
#define NUM_EFFECT_OBJ			30

// 敵の管理オブジェ
class ObjectMng : public Task {
public : 
	// プレイヤーのポインタ
	Player* player;

	// 画像とか
	int ImageUsagi;
	int ImageKuma;

	// 各オブジェのID
	int bulletID, enemyID, effectID;

	// 各オブジェを格納する配列
	Enemy enemy[NUM_ENEMY_OBJ];
	EnemyBullet bullet[NUM_ENEMY_BULLET_OBJ];
	Effect effect[NUM_EFFECT_OBJ];

	// コンストラクタ
	ObjectMng::ObjectMng();
	ObjectMng::ObjectMng(Player* p);

	// 初期化
	void Initialize() override;

	// 更新
	void Update() override;

	// 描画
	void Draw() override;

	// オブジェクトの有効化
	void EnemyActivate(int t,int x,int y);
	void BulletActivate(int t, int x, int y);
	void EffectActivate(int t, int x, int y);
};