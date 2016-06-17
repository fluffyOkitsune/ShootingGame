#include <cmath>
#include "EnemyBullet.h"
#include "DxLib.h"

#define PI	3.14159265358979265358979

EnemyBullet::EnemyBullet(){
}
EnemyBullet::EnemyBullet(Player* p){
	player = p;
}
// �����ݒ�
void EnemyBullet::Initialize() {
	active = false;
}
// �X�V
void EnemyBullet::Update() {
	if(active){
		switch (type){
		case 0 : 
			break;
		case 1 : 
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
void EnemyBullet::Draw() {
	if(active){
		int X = (int)posX;
		int Y = (int)posY;

		switch(type){
		case 0 : // �ʏ�e
			{
				const int X0 = (int)(X-1);
				const int Y0 = (int)(Y-5);
				const int X1 = (int)(X+1);
				const int Y1 = (int)(Y+5);
				DrawBox(X0, Y0, X1, Y1, GetColor(255,0,0), true);
			}
			break;

		case 1 : // �����Ɍ������Ă���e
			{
				// ���x
				const float V = 2.0;
				double deg = 0.0;

				// �p�x���v�Z
				if(velX == 0.0)
					deg = PI/2;
				else
					deg = std::atan(velY/velX);
				if(velX < 0)
					deg += PI;

				const int X0 = (int)((X-1) * std::cos(0.0 + deg));
				const int Y0 = (int)((Y-5) * std::sin(0.0 + deg));
				const int X1 = (int)((X+1) * std::cos(0.0 + deg));
				const int Y1 = (int)((Y+5) * std::sin(0.0 + deg));
				DrawBox(X0, Y0, X1, Y1, GetColor(255,0,0), true);
			}
			break;
		}
	}
}
// �L����
void EnemyBullet::Activate(int t, int x, int y) {
	type = t;
	posX = (float)x;
	posY = (float)y;
	active = true;

	switch (type){
	case 0 : 
		velY = 3.0f;
		break;
	case 1 : 
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
}