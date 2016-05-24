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

// 初期化
void Player::Initialize(){
	posX = START_X;
	posY = START_Y;
	velX = 0;
	velY = 0;
	time = 0;
	
	// 射撃間隔
	shootInterval = 0;

}
// 更新
void Player::Update(){
	Move();

	time++;
}
// 自機の描画
void Player::Draw(){
	DrawTriangle(posX-4, posY+6, posX+4, posY+6, posX, posY-6, GetColor(255,255,255), true);

}

// 移動
void Player::Move(){
	if(CheckHitKey(KEY_INPUT_LEFT) != 0){
		// 左に移動
		velX -= 2;
	}else if(CheckHitKey(KEY_INPUT_RIGHT) != 0){
		// 右に移動
		velX += 2;
	}else{
		//何も押されていなかったら減速
		if(velX>0)
			velX--;
		else if(velX<0)
			velX++;
	}
	if(CheckHitKey(KEY_INPUT_UP) != 0){
		// 上に移動
		velY -= 2;
	}else if(CheckHitKey(KEY_INPUT_DOWN) != 0){
		// 下に移動
		velY += 2;
	}else{
		//何も押されていなかったら減速
		if(velY>0)
			velY--;
		else if(velY<0)
			velY++;
	}
	// 最高速度を超えないようにする
	if(velX > MAX_VEL_X)
		velX = MAX_VEL_X;
	if(velX < -MAX_VEL_X)
		velX = -MAX_VEL_X;
	if(velY > MAX_VEL_Y)
		velY = MAX_VEL_Y;
	if(velY < -MAX_VEL_Y)
		velY = -MAX_VEL_Y;

	// 座標を移動する
	posX += velX;
	posY += velY;

	// 画面を出ないようにする
	if(posX < 0)
		posX = 0;
	else if(posX > MAX_POS_X)
		posX = MAX_POS_X;
	if(posY < 0)
		posY = 0;
	else if(posY > MAX_POS_Y)
		posY = MAX_POS_Y;
}