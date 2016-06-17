#include <windows.h>
#include <iostream>
#include <string>
#include "Game.h"
#include "DxLib.h"

Game::Game(ISceneChanger* changer) : BaseScene(changer) {
	player = Player();
	om = ObjectMng(&player);

	score = 0;
	highScore = 0;

}
// ������
void Game::Initialize(){
	player.Initialize();
	om.Initialize();

	time = 0;
	score = 0;
	stageID = 1;

	state = PRE_INTRO;

}
// �X�V
void Game::Update(){
	//Esc
	if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){
		mSceneChanger->ChangeScene(eScene_Menu);
	}

	// �V�[���ʏ���
	switch(state){
	case PRE_INTRO:
		//TODO
		state = INTRO;
		time = 0;
		break;
	case INTRO:
		//TODO
		if(time==60){
			state = GAME;
			player.ctrl = true;
			time = 0;
		}
		break;
	case GAME:
		// �G�Ȃǂ̔z�u
		Stage(stageID,time);

		// ���@�Ȃǂ̈ړ�
		player.Update();
		om.Update();

		// �q�b�g����
		IsHit();
		GetHit();

		break;
	case DIALOG:
		// �{�X�Ƃ̑Θb
		player.ctrl = false;

		break;
	case CLEAR:

		break;
	case DIED:

		break;
	case GAMEOVER:
		player.ctrl = false;
		if(CheckHitKey(KEY_INPUT_SPACE)!=0){
			Initialize();
		}
		break;
	}

	// �^�C�}�[
	time++;

	if(score > highScore)
		highScore = score;

}
// �`��
void Game::Draw(){
	BaseScene::Draw();
	// �X�R�A
	DrawFormatString(0, 0,GetColor(255,255,255),"SCORE %d",score);
	DrawFormatString(120, 0,GetColor(255,255,255),"HIGH SCORE %d",highScore);
	DrawFormatString(400, 0,GetColor(255,255,255),"Time %d",time);

	player.Draw();
	om.Draw();

	switch(state){
	case PRE_INTRO:
		break;
	case INTRO:
		DrawFormatString(200, 120,GetColor(255,255,255),"READY ?");
		break;
	case GAME:
		if(time<60){
			DrawFormatString(200, 120,GetColor(255,255,255),"GO !");
		}
		break;
	case DIALOG:
		break;
	case CLEAR:
		break;
	case DIED:
		break;
	case GAMEOVER:
		DrawFormatString(200, 120,GetColor(255,255,255),"GAME OVER");
		break;
	}

}
// ��e�m�F(���� -> �G)
bool Game::IsHit(){
	for(int i=0 ; i<NUM_ENEMY_OBJ ;i++){
		Enemy *e = &om.enemy[i];
		if(e->active){
			for(int j = 0 ; j<NUM_BULLET_OBJ ; j++){
				Bullet *b = &player.bullet[j];
				if(b->active){
					if(b->posX >= e->posX-ENEMY_SIZE && b->posX <= e->posX+ENEMY_SIZE && 
						b->posY >= e->posY-ENEMY_SIZE && b->posY <= e->posY+ENEMY_SIZE){
							// �����G�t�F�N�g	
							Player* p = &player;
							om.EffectActivate(0, (int)e->posX, (int)e->posY);
							
							// �I�u�W�F�̖�����
							e->active = false;
							b->active = false;

							// �X�R�A���Z
							switch(e->type){
							case 0 :
								score += 100;
								break;
							}
							return true;
					}
				}
			}
		}
	}
	return false;
}
// ��e�m�F(�G -> ����)
bool Game::GetHit(){
	Player* p = &player;
	for(int i=0 ; i<NUM_ENEMY_BULLET_OBJ ;i++){
		EnemyBullet *b = &om.bullet[i];
		if(b->active){
			if(b->posX >= p->posX-PLAYER_WIDTH && b->posX <= p->posX+PLAYER_WIDTH && 
				b->posY >= p->posY-PLAYER_HEIGHT && b->posY <= p->posY+PLAYER_HEIGHT){
					// �����G�t�F�N�g
					om.EffectActivate(0, (int)p->posX, (int)p->posY);

					// �I�u�W�F�̖�����
					b->active = false;
					
					// �Q�[���I�[�o�[�ɂȂ�
					state = GAMEOVER;
					return true;
			}
		}
	}
	return false;
}
// �X�e�[�W�Ǘ�
void Game::Stage(const int ID, const int time){
	switch(ID){
	case 1:
		switch (time){
		case 120 :
			om.EnemyActivate(0,0,20);
			om.EnemyActivate(0,0,40);
			om.EnemyActivate(0,0,60);
			break;
		case 180 :
			om.EnemyActivate(0,20,40);
			break;
		case 240 :
			om.EnemyActivate(0,40,60);
			break;
		case 300 :
			om.EnemyActivate(0,40,60);
			break;
		case 500 :
			om.EnemyActivate(1,100,50);
			break;
		case 700 :
			om.EnemyActivate(2,100,50);
			break;
		case 900 :
			om.EnemyActivate(1,100,50);
			break;
		case 1100 :
			om.EnemyActivate(2,100,50);
			break;

		}
		break;

	case 2:
		switch (time){
		case 120 :
			break;
			break;
		}
	}
}
