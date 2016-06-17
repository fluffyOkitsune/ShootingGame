// Game -> Player
#pragma once

#include "Task.h"
#include "Bullet.h"

// 自機のサイズ
#define PLAYER_WIDTH 6
#define PLAYER_HEIGHT 10

// 自機の弾丸の最大数
#define NUM_BULLET_OBJ	20
#define SHOOT_INTERVAL	6

class Player : public Task{
public :
	// 座標
	float posX, posY;
	
	// 射撃間隔
	int shootInterval;
	
	bool ctrl;

	// 弾丸
	Bullet bullet[NUM_BULLET_OBJ];


private :
	// 速度
	float velX, velY;

	// 弾丸ID
	int bulletID;

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