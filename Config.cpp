#include "Config.h"
#include "DxLib.h"

Config::Config(ISceneChanger* changer) : BaseScene(changer) {
}

//������
void Config::Initialize(){
	//�摜�̃��[�h
	mImageHandle = LoadGraph("images/Usagi.png");
}

//�X�V
void Config::Update(){
	if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){ //Esc�L�[��������Ă�����
		//�V�[�������j���[�ɕύX
		mSceneChanger->ChangeScene(eScene_Menu);
	}
}

//�`��
void Config::Draw(){
	BaseScene::Draw();//�e�N���X�̕`�惁�\�b�h���Ă�
	DrawString(0, 0,"�ݒ��ʂł��B",GetColor(255,255,255));
	DrawString(0,20,"Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B",GetColor(255,255,255));
}
