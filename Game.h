#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"
#include "Player.h"

#define NUM_BULLET_OBJ	20

//�Q�[����ʃN���X
class Game : public BaseScene {
public :
	// ���@
	Player p;

	// �e��
	Bullet bullet[NUM_BULLET_OBJ];

	// �e��ID
	int bulletID;

	// �R���X�g���N�^
    Game::Game(ISceneChanger* changer);

	//�������������I�[�o�[���C�h�B
    void Initialize() override;

	//�I���������I�[�o�[���C�h�B
    //void Finalize() override;

	//�X�V�������I�[�o�[���C�h�B
    void Update() override;

	//�`�揈�����I�[�o�[���C�h�B
    void Draw() override;
	
	// �ˌ�
	void Shoot();

};
