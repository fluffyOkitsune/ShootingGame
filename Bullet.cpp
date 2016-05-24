#pragma once

#include "DxLib.h"
#include "Bullet.h"


Bullet::Bullet(){

}
// �����ݒ�
void Bullet::Initialize() {
	activate = false;
}
// �X�V
void Bullet::Update() {
	//�ړ�
	posY -= 10;
	if(posY<0)
		activate = false;
}
// �`��
void Bullet::Draw() {
	if(activate){
		DrawBox(posX-1, posY-5, posX+1, posY+5, GetColor(255,255,255), true);
	}
}
// �L����
void Bullet::Activate(int x,int y) {
	posX = x;
	posY = y;
	activate = true;
}