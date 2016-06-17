#pragma once

#include "Bullet.h"
#include "DxLib.h"


Bullet::Bullet(){

}
// 初期設定
void Bullet::Initialize() {
	active = false;
}
// 更新
void Bullet::Update() {
	//移動
	posY += -10.0f;

	// 画面外に出たら無効化;
	if(posY<0)
		active = false;
}
// 描画
void Bullet::Draw() {
	if(active){
		int X = (int)posX;
		int Y = (int)posY;
		DrawBox(X, Y-5, X+1, Y+5, GetColor(255,255,255), true);
	}
}
// 有効化
void Bullet::Activate(int x,int y) {
	posX = (float)x;
	posY = (float)y;
	active = true;
}