#pragma once

#include "Task.h"

#define MAX_VEL_X	10
#define MAX_VEL_Y	10

class Bullet : public Task{
private : 
	int posX;
	int posY;
	bool activate;

public : 
	// コンストラクタ
	Bullet::Bullet();

	// 初期化処理をオーバーライド
	void Initialize() override;

	// 終了処理をオーバーライド
	//void Finalize() override;

	// 更新処理をオーバーライド
	void Update() override;

	// 描画処理をオーバーライド
	void Draw() override;

	// 弾丸を有効化する
	void Activate(int x,int y);
};