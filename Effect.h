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

	// ‰Šú‰»
	void Initialize() override;

	// XV
	void Update() override;

	// •`‰æ
	void Draw() override;

	// —LŒø‰»
	void Activate(int t, int x,int y) override;

};
