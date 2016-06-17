#include "Player.h"
#include "DxLib.h"

#define MAX_VEL_X		10
#define MAX_VEL_Y		10
#define START_X			300
#define START_Y			380

#define WINDOW_WIDTH	640
#define WINDOW_HEIGHT	480

Player::Player(){

}

// 初期化
void Player::Initialize(){
	posX = START_X;
	posY = START_Y;
	velX = 0.0f;
	velY = 0.0f;
	ctrl = false;

	// 射撃間隔
	shootInterval = 0;

	// 自機の弾丸
	bulletID = 0;
	for(int i = 0 ; i < NUM_BULLET_OBJ ; i++){
		bullet[i] = Bullet();
		bullet[i].Initialize();
	}
}
// 更新
void Player::Update(){
	if(ctrl)
		Move();

	// 自機の弾丸
	for(int i=0 ; i<NUM_BULLET_OBJ; i++){
		bullet[i].Update();
	}

	//射撃処理
	if(shootInterval > 0)
		shootInterval--;
	else if(CheckHitKey(KEY_INPUT_SPACE) != 0)
		Shoot();

}
// 描画
void Player::Draw(){
	// 自機の描画
	int X = (int)posX;
	int Y = (int)posY;
	DrawTriangle(X-PLAYER_WIDTH, Y+PLAYER_HEIGHT, X+PLAYER_WIDTH, Y+PLAYER_HEIGHT, X, Y-PLAYER_HEIGHT, GetColor(255,255,255), true);

	// 自機の弾丸
	for(int i=0 ; i<NUM_BULLET_OBJ; i++){
		bullet[i].Draw();
	}
}

// 移動
void Player::Move(){
	if(CheckHitKey(KEY_INPUT_LEFT) != 0){
		// 左に移動
		velX -= 2.0f;
	}else if(CheckHitKey(KEY_INPUT_RIGHT) != 0){
		// 右に移動
		velX += 2.0f;
	}else{
		//何も押されていなかったら減速
		if(velX>0)
			velX--;
		else if(velX<0)
			velX++;
	}
	if(CheckHitKey(KEY_INPUT_UP) != 0){
		// 上に移動
		velY -= 2.0f;
	}else if(CheckHitKey(KEY_INPUT_DOWN) != 0){
		// 下に移動
		velY += 2.0f;
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
	else if(posX > WINDOW_WIDTH)
		posX = WINDOW_WIDTH;
	if(posY < 0)
		posY = 0;
	else if(posY > WINDOW_HEIGHT)
		posY = WINDOW_HEIGHT;
}
// 射撃
void Player::Shoot(){
	// 射撃不可時間を設定
	shootInterval = SHOOT_INTERVAL;
	// 弾丸を有効化
	bullet[bulletID].Activate((int)posX,(int)posY);
	// IDを移動
	bulletID = (bulletID+1) % NUM_BULLET_OBJ;
}