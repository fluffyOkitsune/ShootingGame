#include <windows.h>

#include "Game.h"
#include "DxLib.h"

#define NUM_BULLET_OBJ	20
#define SHOOT_INTERVAL	6

Game::Game(ISceneChanger* changer) : BaseScene(changer) {

}

//������
void Game::Initialize(){
	// mImageHandle = LoadGraph("images/Scene_Game.png");

	// ���@
	p = Player();
	
	// ���@�̒e��
	for(int i = 0 ; i < NUM_BULLET_OBJ ; i++){
		bullet[i] = Bullet();
		bullet[i].Initialize();
	}

	// �e��ID
	bulletID = 0;

	// ������
	p.Initialize();

	// �G

	// �G�e

}

//�X�V
void Game::Update(){
	//Esc�L�[��������Ă�����
	if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){
		//�V�[�������j���[�ɕύX
		mSceneChanger->ChangeScene(eScene_Menu);
	}
	// ���@
	p.Update();
	
	// ���@�̒e��
	for(int i=0 ; i<NUM_BULLET_OBJ; i++){
		bullet[i].Update();
	}
	
	// �G

	// �G�e
	
	//shootInterval = 0�̂Ƃ��̂ݎˌ��\
	if(p.shootInterval > 0)
		p.shootInterval--;
	else if(CheckHitKey(KEY_INPUT_SPACE) != 0)
		Shoot();

}

//�`��
void Game::Draw(){
	//�e�N���X�̕`�惁�\�b�h���Ă�
	BaseScene::Draw();
	DrawString(0, 0,"�Q�[����ʂł��B",GetColor(255,255,255));
	DrawString(0,20,"Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B",GetColor(255,255,255));
	
	// ���@
	p.Draw();

	// ���@�̒e��
	for(int i=0 ; i<NUM_BULLET_OBJ; i++){
		bullet[i].Draw();
	}
	
	// �G

	// �G�e

}

// �ˌ�
void Game::Shoot(){
	// �ˌ��s���Ԃ�ݒ�
	p.shootInterval = SHOOT_INTERVAL;
	// �e�ۂ�L����
	bullet[bulletID].Activate(p.posX,p.posY);
	// ID���ړ�
	bulletID = (bulletID+1) % NUM_BULLET_OBJ;
}