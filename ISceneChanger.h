#pragma once

// �񋓌^
enum eScene{
	//���j���[���
	eScene_Menu,

	//�Q�[�����
	eScene_Game,

	//�ݒ���
	eScene_Config,

	//����
	eScene_None,
};

//�V�[����ύX���邽�߂̃C���^�[�t�F�C�X�N���X
class ISceneChanger {
public:
	virtual ~ISceneChanger() = 0;

	//�w��V�[���ɕύX����
	virtual void ChangeScene(eScene NextScene) = 0;
};
