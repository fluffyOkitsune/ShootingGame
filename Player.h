// Game -> Player
#pragma once

#include "Task.h"
#include "Bullet.h"

// ���@�̃T�C�Y
#define PLAYER_WIDTH 6
#define PLAYER_HEIGHT 10

// ���@�̒e�ۂ̍ő吔
#define NUM_BULLET_OBJ	20
#define SHOOT_INTERVAL	6

class Player : public Task{
public :
	// ���W
	float posX, posY;
	
	// �ˌ��Ԋu
	int shootInterval;
	
	bool ctrl;

	// �e��
	Bullet bullet[NUM_BULLET_OBJ];


private :
	// ���x
	float velX, velY;

	// �e��ID
	int bulletID;

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