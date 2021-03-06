// Game -> ObjectMng -> Effect
#pragma once
#include "Object.h"

class Effect : public Object {
public : 
	int type;
	float posX, posY;
	bool active;
	int time;

	Effect::Effect();

	// 初期化
	void Initialize() override;

	// 更新
	void Update() override;

	// 描画
	void Draw() override;

	// 有効化
	void Activate(int t, int x,int y) override;

};
