#include <cmath>
#include "Enemy.h"
#include "DxLib.h"

#define PI	3.14159265358979265358979

Enemy::Enemy(){
}
Enemy::Enemy(Player* p){
	player = p;
}
// ������
void Enemy::Initialize(){
	active = false;
	shoot = -1;
}
// �X�V
void Enemy::Update(){
	if(active){
		switch (type){
		case 0 : // ���ʂ̓G
			// ���x
			velX = 1.0f;
			velY = 5.0f - (0.1f * (float)time);

			// �ˌ�
			if(time == 30)
				shoot = 0;
			break;

		case 1 : // �ǔ��e�����G
			// ���x
			if(time <= 60)
			velY = 2.0f;
			else if(60 < time && time <= 120)
			velY = 0.0f;
			else if(120 < time)
			velY = -2.0f;
			
			// �ˌ�
			if(time == 90)
				shoot = 1;
			break;

		case 2 : // �ǂ������Ă���G
			// ���x
			const float V = 2.0;
			double deg = 0.0;

			// �p�x���v�Z
			if(player->posX - posX == 0.0)
				deg = PI/2;
			else
				deg = std::atan((player->posY - posY)/(player->posX - posX));
			if(player->posX - posX < 0)
				deg += PI;

			velX = (float)(V * std::cos(deg));
			velY = (float)(V * std::sin(deg));
			break;
		}
		// �ړ�
		posX += velX;
		posY += velY;
		time++;

		// ��ʂ��o���疳����
		if(posX < 0 && velX < 0)
			active = false;
		else if(posX > WINDOW_WIDTH && velX > 0)
			active = false;
		else if(posY < 0 && velY < 0)
			active = false;
		else if(posY > WINDOW_HEIGHT && velY > 0)
			active = false;
	}
}
// �`��
void Enemy::Draw(){
	if(active){
		int X = (int)posX;
		int Y = (int)posY;

		switch(type){
		case 0 : // ���ʂ̓G
			DrawBox(X-ENEMY_SIZE, Y-ENEMY_SIZE, X+ENEMY_SIZE, Y+ENEMY_SIZE, GetColor(255,255,255), false);
			break;

		case 1 : // �ǔ��e�����G
			DrawOval(X, Y, 2*ENEMY_SIZE, 2*ENEMY_SIZE, GetColor(255,255,255), false);
			break;

		case 2 : // �ǂ������Ă���G
			{
				// �p�x���v�Z
				double deg = 0.0;
				if(velX == 0.0)
					deg = PI/2;
				else
					deg = std::atan(velY/velX);
				if(player->posX - posX < 0)
					deg += PI;

				// �_�̈ʒu���v�Z
				const int X0 = (int)(X + ENEMY_SIZE * std::cos(0.0 + deg));
				const int Y0 = (int)(Y + ENEMY_SIZE * std::sin(0.0 + deg));
				const int X1 = (int)(X + ENEMY_SIZE * std::cos((PI * 5/6) + deg));
				const int Y1 = (int)(Y + ENEMY_SIZE * std::sin((PI * 5/6) + deg));
				const int X2 = (int)(X + ENEMY_SIZE * std::cos((PI * 7/6) + deg));
				const int Y2 = (int)(Y + ENEMY_SIZE * std::sin((PI * 7/6) + deg));

				DrawTriangle(X0, Y0, X1, Y1 ,X2, Y2, GetColor(255,255,255), false);
			}
			break;

		case 10 : // �{�X�w�^�E�_�[�N���r�b�g�x
			// DrawGraph(0, 0, ObjectMng::ImageUsagi, true);
			break;
		}
	}
}
// �L����
void Enemy::Activate(int t, int x, int y){
	type = t;
	posX = (float)x;
	posY = (float)y;

	velX = 0.0;
	velY = 0.0;

	time = 0;

	shoot = -1;

	active = true;

}