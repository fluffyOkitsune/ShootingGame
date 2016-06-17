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

	// ������
	void Initialize() override;

	// �X�V
	void Update() override;

	// �`��
	void Draw() override;

	// �e�ۂ�L����
	void Activate(int x,int y);
};