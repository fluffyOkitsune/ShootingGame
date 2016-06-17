#pragma once

#include "Bullet.h"
#include "DxLib.h"


Bullet::Bullet(){

}
// �����ݒ�
void Bullet::Initialize() {
	active = false;
}
// �X�V
void Bullet::Update() {
	//�ړ�
	posY += -10.0f;

	// ��ʊO�ɏo���疳����;
	if(posY<0)
		active = false;
}
// �`��
void Bullet::Draw() {
	if(active){
		int X = (int)posX;
		int Y = (int)posY;
		DrawBox(X, Y-5, X+1, Y+5, GetColor(255,255,255), true);
	}
}
// �L����
void Bullet::Activate(int x,int y) {
	posX = (float)x;
	posY = (float)y;
	active = true;
}