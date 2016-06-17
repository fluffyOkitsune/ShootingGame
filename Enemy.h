// Game -> ObjectMng -> Enemy
#pragma once
#include "Object.h"
#include "Player.h"

#define ENEMY_SIZE 10
#define WINDOW_WIDTH	640
#define WINDOW_HEIGHT	480

class Enemy : public Object {
public : 
	int type;			// �G�̃^�C�v
	float posX, posY;	// �G�̈ʒu
	float velX, velY;	// �G�̑��x
	bool active;		// �L�����t���O
	int time;			// �o�����Ă���̌o�߃t���[����
	Player* player;
	
	// �ˌ��t���O
	int shoot;

	Enemy::Enemy();
	Enemy::Enemy(Player* p);

	// ������
	void Initialize() override;

	// �X�V
	void Update() override;

	// �`��
	void Draw() override;

	// �L����
	void Activate(int t, int x, int y) override;

};