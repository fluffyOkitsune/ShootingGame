#pragma once

#include "Task.h"
#include "Bullet.h"

class Player : public Task{
public :
	// ���W
	int posX;
	int posY;
	
	// �ˌ��Ԋu
	int shootInterval;

private :
	// ���x
	int velX;
	int velY;

	// ����
	long time;

public : 
	// �R���X�g���N�^
	Player::Player();

	//�������������I�[�o�[���C�h
    void Initialize() override;

	//�X�V�������I�[�o�[���C�h
    void Update() override;

	//�`�揈�����I�[�o�[���C�h
    void Draw() override;

private :
	// �ړ�����
	void Move();

	// �ˌ�
	void Shoot();
};