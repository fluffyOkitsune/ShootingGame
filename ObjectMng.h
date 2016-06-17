// Game -> ObjectMng
#pragma once

#include "Task.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Effect.h"
#include "Player.h"
#include "DxLib.h"

// �G�I�u�W�F�̐�
#define NUM_ENEMY_OBJ			20

// �G�e�̐�
#define NUM_ENEMY_BULLET_OBJ	50

// �G�t�F�N�g�̐�
#define NUM_EFFECT_OBJ			30

// �G�̊Ǘ��I�u�W�F
class ObjectMng : public Task {
public : 
	// �v���C���[�̃|�C���^
	Player* player;

	// �摜�Ƃ�
	int ImageUsagi;
	int ImageKuma;

	// �e�I�u�W�F��ID
	int bulletID, enemyID, effectID;

	// �e�I�u�W�F���i�[����z��
	Enemy enemy[NUM_ENEMY_OBJ];
	EnemyBullet bullet[NUM_ENEMY_BULLET_OBJ];
	Effect effect[NUM_EFFECT_OBJ];

	// �R���X�g���N�^
	ObjectMng::ObjectMng();
	ObjectMng::ObjectMng(Player* p);

	// ������
	void Initialize() override;

	// �X�V
	void Update() override;

	// �`��
	void Draw() override;

	// �I�u�W�F�N�g�̗L����
	void EnemyActivate(int t,int x,int y);
	void BulletActivate(int t, int x, int y);
	void EffectActivate(int t, int x, int y);
};