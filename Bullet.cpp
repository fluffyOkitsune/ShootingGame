#pragma once

#include "DxLib.h"
#include "Bullet.h"


Bullet::Bullet(){

}
// 初期設定
void Bullet::Initialize() {
	activate = false;
}
// 更新
void Bullet::Update() {
	//移動
	posY -= 10;
	if(posY<0)
		activate = false;
}
// 描画
void Bullet::Draw() {
	if(activate){
		DrawBox(posX-1, posY-5, posX+1, posY+5, GetColor(255,255,255), true);
	}
}
// 有効化
void Bullet::Activate(int x,int y) {
	posX = x;
	posY = y;
	activate = true;
}