#include <cmath>
#include "Enemy.h"
#include "DxLib.h"

#define PI	3.14159265358979265358979

Enemy::Enemy(){
}
Enemy::Enemy(Player* p){
	player = p;
}
// 初期化
void Enemy::Initialize(){
	active = false;
	shoot = -1;
}
// 更新
void Enemy::Update(){
	if(active){
		switch (type){
		case 0 : // 普通の敵
			// 速度
			velX = 1.0f;
			velY = 5.0f - (0.1f * (float)time);

			// 射撃
			if(time == 30)
				shoot = 0;
			break;

		case 1 : // 追尾弾を撃つ敵
			// 速度
			if(time <= 60)
			velY = 2.0f;
			else if(60 < time && time <= 120)
			velY = 0.0f;
			else if(120 < time)
			velY = -2.0f;
			
			// 射撃
			if(time == 90)
				shoot = 1;
			break;

		case 2 : // 追いかけてくる敵
			// 速度
			const float V = 2.0;
			double deg = 0.0;

			// 角度を計算
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
		// 移動
		posX += velX;
		posY += velY;
		time++;

		// 画面を出たら無効化
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
// 描画
void Enemy::Draw(){
	if(active){
		int X = (int)posX;
		int Y = (int)posY;

		switch(type){
		case 0 : // 普通の敵
			DrawBox(X-ENEMY_SIZE, Y-ENEMY_SIZE, X+ENEMY_SIZE, Y+ENEMY_SIZE, GetColor(255,255,255), false);
			break;

		case 1 : // 追尾弾を撃つ敵
			DrawOval(X, Y, 2*ENEMY_SIZE, 2*ENEMY_SIZE, GetColor(255,255,255), false);
			break;

		case 2 : // 追いかけてくる敵
			{
				// 角度を計算
				double deg = 0.0;
				if(velX == 0.0)
					deg = PI/2;
				else
					deg = std::atan(velY/velX);
				if(player->posX - posX < 0)
					deg += PI;

				// 点の位置を計算
				const int X0 = (int)(X + ENEMY_SIZE * std::cos(0.0 + deg));
				const int Y0 = (int)(Y + ENEMY_SIZE * std::sin(0.0 + deg));
				const int X1 = (int)(X + ENEMY_SIZE * std::cos((PI * 5/6) + deg));
				const int Y1 = (int)(Y + ENEMY_SIZE * std::sin((PI * 5/6) + deg));
				const int X2 = (int)(X + ENEMY_SIZE * std::cos((PI * 7/6) + deg));
				const int Y2 = (int)(Y + ENEMY_SIZE * std::sin((PI * 7/6) + deg));

				DrawTriangle(X0, Y0, X1, Y1 ,X2, Y2, GetColor(255,255,255), false);
			}
			break;

		case 10 : // ボス『真・ダークラビット』
			// DrawGraph(0, 0, ObjectMng::ImageUsagi, true);
			break;
		}
	}
}
// 有効化
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