// Game -> ObjectMng -> EnemyBullet
#pragma once
#include "Object.h"
#include "Player.h"

#define BULLET_SIZE 10
#define WINDOW_WIDTH	640
#define WINDOW_HEIGHT	480

class EnemyBullet : public Object {
public : 
	int type;			// 弾のタイプ
	float posX, posY;	// 弾の位置
	float velX, velY;	// 弾の速度
	bool active;		// 有効化フラグ
	int time;			// 出現してからの経過フレーム数
	Player* player;

	EnemyBullet::EnemyBullet();
	EnemyBullet::EnemyBullet(Player* p);
	
	// 初期化
    void Initialize() override;

	// 更新
    void Update() override;

	// 描画
    void Draw() override;

	// 有効化
	void Activate(int t, int x, int y) override;

};