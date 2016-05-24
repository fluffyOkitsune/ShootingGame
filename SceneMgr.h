#pragma once

#include "ISceneChanger.h"
#include "BaseScene.h"

class SceneMgr : public ISceneChanger, Task {

private:
	//�V�[���Ǘ��ϐ�
	BaseScene* mScene;

	//���̃V�[���Ǘ��ϐ�
	eScene mNextScene;

public:
	SceneMgr();

	//������
	void Initialize() override;

	//�I������
	void Finalize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	// ���� nextScene �ɃV�[����ύX����
	void ChangeScene(eScene NextScene) override;

};