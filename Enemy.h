// Game -> ObjectMng -> Enemy
#pragma once
#include "Object.h"
#include "Player.h"

#define ENEMY_SIZE 10
#define WINDOW_WIDTH	640
#define WINDOW_HEIGHT	480

class Enemy : public Object {
public : 
	int type;			// 敵のタイプ
	float posX, posY;	// 敵の位置
	float velX, velY;	// 敵の速度
	bool active;		// 有効化フラグ
	int time;			// 出現してからの経過フレーム数
	Player* player;
	
	// 射撃フラグ
	int shoot;

	Enemy::Enemy();
	Enemy::Enemy(Player* p);

	// 初期化
	void Initialize() override;

	// 更新
	void Update() override;

	// 描画
	void Draw() override;

	// 有効化
	void Activate(int t, int x, int y) override;

};