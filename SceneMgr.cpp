#include "DxLib.h"
#include "Config.h"
#include "Game.h"
#include "Menu.h"
#include "SceneMgr.h"

// ���̃V�[���Ǘ��ϐ�
SceneMgr::SceneMgr() : mNextScene(eScene_None) {
	mScene = (BaseScene*) new Menu(this);
}

// ������
void SceneMgr::Initialize(){
	mScene->Initialize();
}

// �I������
void SceneMgr::Finalize(){
	mScene->Finalize();
}

// �X�V
void SceneMgr::Update(){
	if(mNextScene != eScene_None){
		//���̃V�[�����Z�b�g����Ă�����
		mScene->Finalize();
		
		//���݂̃V�[���̏I�����������s
		delete mScene;

		switch(mNextScene){
			//�V�[���ɂ���ď����𕪊�
		case eScene_Menu:
			//���̉�ʂ����j���[�Ȃ�
			//���j���[��ʂ̃C���X�^���X�𐶐�����
			mScene = (BaseScene*) new Menu(this);
			break;

		case eScene_Game:
			mScene = (BaseScene*) new Game(this);
			break;

		case eScene_Config:
			mScene = (BaseScene*) new Config(this);
			break;
		}
		//���̃V�[�������N���A
		mNextScene = eScene_None;

		//�V�[����������
		mScene->Initialize();
	}
	//�V�[���̍X�V
	mScene->Update();
}

// �`��
void SceneMgr::Draw(){
	//�V�[���̕`��
	mScene->Draw(); 
}

// ���� nextScene �ɃV�[����ύX����
void SceneMgr::ChangeScene(eScene NextScene){
	//���̃V�[�����Z�b�g����
	mNextScene = NextScene;
}
