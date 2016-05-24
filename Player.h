#pragma once

#include "Task.h"
#include "Bullet.h"

class Player : public Task{
public :
	// 座標
	int posX;
	int posY;
	
	// 射撃間隔
	int shootInterval;

private :
	// 速度
	int velX;
	int velY;

	// 時間
	long time;

public : 
	// コンストラクタ
	Player::Player();

	//初期化処理をオーバーライド
    void Initialize() override;

	//更新処理をオーバーライド
    void Update() override;

	//描画処理をオーバーライド
    void Draw() override;

private :
	// 移動処理
	void Move();

	// 射撃
	void Shoot();
};