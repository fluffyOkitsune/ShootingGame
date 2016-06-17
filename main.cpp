#include "SceneMgr.h"
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	// �E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK );

	// �V�[���}�l�[�W���[�̏�����
	SceneMgr sceneMgr;
	sceneMgr.Initialize();

	// ��ʍX�V & ���b�Z�[�W���� & ��ʏ���
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
		// �X�V
		sceneMgr.Update();

		// �`��
		sceneMgr.Draw();
	}

	sceneMgr.Finalize();

	// DX���C�u�����I������
	DxLib_End();

	return 0;
}