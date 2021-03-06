// Game -> Player-> Bullet
#pragma once
#include "Task.h"

#define MAX_VEL_X	10
#define MAX_VEL_Y	10

class Bullet : public Task{
public : 
	float posX, posY;
	bool active;

	Bullet::Bullet();

	// 初期化
	void Initialize() override;

	// 更新
	void Update() override;

	// 描画
	void Draw() override;

	// 弾丸を有効化
	void Activate(int x,int y);
};