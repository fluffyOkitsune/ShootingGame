#include "Menu.h"
#include "DxLib.h"

Menu::Menu(ISceneChanger* changer) : BaseScene(changer) {
}

// ������
void Menu::Initialize(){
	// �摜�̃��[�h
	mImageHandle = LoadGraph("images/Scene_Menu.png");
}

// �X�V
void Menu::Update(){
	// G�L�[��������Ă�����
	if(CheckHitKey(KEY_INPUT_G)!=0){
		// �V�[�����Q�[����ʂɕύX
		mSceneChanger->ChangeScene(eScene_Game);
	}
	// C�L�[��������Ă�����
	if(CheckHitKey(KEY_INPUT_C)!=0){
		// �V�[����ݒ��ʂɕύX
		mSceneChanger->ChangeScene(eScene_Config);
	}
}

// �`��
void Menu::Draw(){
	// �e�N���X�̕`�惁�\�b�h���Ă�
	BaseScene::Draw();
	DrawString(0, 0,"���j���[��ʂł��B",GetColor(255,255,255));
	DrawString(0,20,"G�L�[�������ƃQ�[����ʂɐi�݂܂��B",GetColor(255,255,255));
	DrawString(0,40,"C�L�[�������Ɓ@�ݒ��ʂɐi�݂܂��B",GetColor(255,255,255));
}
