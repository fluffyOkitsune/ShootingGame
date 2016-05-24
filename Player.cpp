#pragma once

#include <windows.h>

#include "DxLib.h"
#include "Player.h"

#define MAX_VEL_X		10
#define MAX_VEL_Y		10
#define START_X			300
#define START_Y			380
#define MAX_POS_X		600
#define MAX_POS_Y		400

Player::Player(){

}

// ������
void Player::Initialize(){
	posX = START_X;
	posY = START_Y;
	velX = 0;
	velY = 0;
	time = 0;
	
	// �ˌ��Ԋu
	shootInterval = 0;

}
// �X�V
void Player::Update(){
	Move();

	time++;
}
// ���@�̕`��
void Player::Draw(){
	DrawTriangle(posX-4, posY+6, posX+4, posY+6, posX, posY-6, GetColor(255,255,255), true);

}

// �ړ�
void Player::Move(){
	if(CheckHitKey(KEY_INPUT_LEFT) != 0){
		// ���Ɉړ�
		velX -= 2;
	}else if(CheckHitKey(KEY_INPUT_RIGHT) != 0){
		// �E�Ɉړ�
		velX += 2;
	}else{
		//����������Ă��Ȃ������猸��
		if(velX>0)
			velX--;
		else if(velX<0)
			velX++;
	}
	if(CheckHitKey(KEY_INPUT_UP) != 0){
		// ��Ɉړ�
		velY -= 2;
	}else if(CheckHitKey(KEY_INPUT_DOWN) != 0){
		// ���Ɉړ�
		velY += 2;
	}else{
		//����������Ă��Ȃ������猸��
		if(velY>0)
			velY--;
		else if(velY<0)
			velY++;
	}
	// �ō����x�𒴂��Ȃ��悤�ɂ���
	if(velX > MAX_VEL_X)
		velX = MAX_VEL_X;
	if(velX < -MAX_VEL_X)
		velX = -MAX_VEL_X;
	if(velY > MAX_VEL_Y)
		velY = MAX_VEL_Y;
	if(velY < -MAX_VEL_Y)
		velY = -MAX_VEL_Y;

	// ���W���ړ�����
	posX += velX;
	posY += velY;

	// ��ʂ��o�Ȃ��悤�ɂ���
	if(posX < 0)
		posX = 0;
	else if(posX > MAX_POS_X)
		posX = MAX_POS_X;
	if(posY < 0)
		posY = 0;
	else if(posY > MAX_POS_Y)
		posY = MAX_POS_Y;
}