// Game
#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"
#include "Player.h"
#include "ObjectMng.h"

enum State {
	PRE_INTRO, INTRO, GAME, DIALOG, CLEAR, DIED, GAMEOVER
};

// �Q�[����ʃN���X
class Game : public BaseScene {
public : 
	Player player;	// ���@
	ObjectMng om;	// �G�ƓG�e

	State state;	// ���

	long time;		// ����
	int stageID;	// ���݂̃X�e�[�W�ԍ�
	int score;		// �X�R�A
	int highScore;	// �n�C�X�R�A

	Game::Game(ISceneChanger* changer);

	// ������
	void Initialize() override;

	// �X�V
	void Update() override;

	// �`��
	void Draw() override;

	// ��e�m�F
	bool IsHit();
	bool GetHit();

	// �X�e�[�W���
	void Stage(int ID, int time);

	// �{�X�o��
	void Boss(int ID);

};