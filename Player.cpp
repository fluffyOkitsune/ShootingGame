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

// ������
void Player::Initialize(){
	posX = START_X;
	posY = START_Y;
	velX = 0.0f;
	velY = 0.0f;
	ctrl = false;

	// �ˌ��Ԋu
	shootInterval = 0;

	// ���@�̒e��
	bulletID = 0;
	for(int i = 0 ; i < NUM_BULLET_OBJ ; i++){
		bullet[i] = Bullet();
		bullet[i].Initialize();
	}
}
// �X�V
void Player::Update(){
	if(ctrl)
		Move();

	// ���@�̒e��
	for(int i=0 ; i<NUM_BULLET_OBJ; i++){
		bullet[i].Update();
	}

	//�ˌ�����
	if(shootInterval > 0)
		shootInterval--;
	else if(CheckHitKey(KEY_INPUT_SPACE) != 0)
		Shoot();

}
// �`��
void Player::Draw(){
	// ���@�̕`��
	int X = (int)posX;
	int Y = (int)posY;
	DrawTriangle(X-PLAYER_WIDTH, Y+PLAYER_HEIGHT, X+PLAYER_WIDTH, Y+PLAYER_HEIGHT, X, Y-PLAYER_HEIGHT, GetColor(255,255,255), true);

	// ���@�̒e��
	for(int i=0 ; i<NUM_BULLET_OBJ; i++){
		bullet[i].Draw();
	}
}

// �ړ�
void Player::Move(){
	if(CheckHitKey(KEY_INPUT_LEFT) != 0){
		// ���Ɉړ�
		velX -= 2.0f;
	}else if(CheckHitKey(KEY_INPUT_RIGHT) != 0){
		// �E�Ɉړ�
		velX += 2.0f;
	}else{
		//����������Ă��Ȃ������猸��
		if(velX>0)
			velX--;
		else if(velX<0)
			velX++;
	}
	if(CheckHitKey(KEY_INPUT_UP) != 0){
		// ��Ɉړ�
		velY -= 2.0f;
	}else if(CheckHitKey(KEY_INPUT_DOWN) != 0){
		// ���Ɉړ�
		velY += 2.0f;
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
	else if(posX > WINDOW_WIDTH)
		posX = WINDOW_WIDTH;
	if(posY < 0)
		posY = 0;
	else if(posY > WINDOW_HEIGHT)
		posY = WINDOW_HEIGHT;
}
// �ˌ�
void Player::Shoot(){
	// �ˌ��s���Ԃ�ݒ�
	shootInterval = SHOOT_INTERVAL;
	// �e�ۂ�L����
	bullet[bulletID].Activate((int)posX,(int)posY);
	// ID���ړ�
	bulletID = (bulletID+1) % NUM_BULLET_OBJ;
}