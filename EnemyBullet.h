// Game -> ObjectMng -> EnemyBullet
#pragma once
#include "Object.h"
#include "Player.h"

#define BULLET_SIZE 10
#define WINDOW_WIDTH	640
#define WINDOW_HEIGHT	480

class EnemyBullet : public Object {
public : 
	int type;			// �e�̃^�C�v
	float posX, posY;	// �e�̈ʒu
	float velX, velY;	// �e�̑��x
	bool active;		// �L�����t���O
	int time;			// �o�����Ă���̌o�߃t���[����
	Player* player;

	EnemyBullet::EnemyBullet();
	EnemyBullet::EnemyBullet(Player* p);
	
	// ������
    void Initialize() override;

	// �X�V
    void Update() override;

	// �`��
    void Draw() override;

	// �L����
	void Activate(int t, int x, int y) override;

};