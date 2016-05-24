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
	// �R���X�g���N�^
	Bullet::Bullet();

	// �������������I�[�o�[���C�h
	void Initialize() override;

	// �I���������I�[�o�[���C�h
	//void Finalize() override;

	// �X�V�������I�[�o�[���C�h
	void Update() override;

	// �`�揈�����I�[�o�[���C�h
	void Draw() override;

	// �e�ۂ�L��������
	void Activate(int x,int y);
};