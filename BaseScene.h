#pragma once

#include "Task.h"
#include "ISceneChanger.h"

class BaseScene : public Task {

protected:
	//�摜�n���h���i�[�p�ϐ�
    int mImageHandle;

	//�N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�C�X
    ISceneChanger* mSceneChanger;

public :
    BaseScene(ISceneChanger* changer);
    virtual ~BaseScene(){}

	//�������������I�[�o�[���C�h
	virtual void Initialize() override {}

	//�I���������I�[�o�[���C�h�B
    virtual void Finalize() override ;

	//�X�V�������I�[�o�[���C�h�B
    virtual void Update() override {}

	//�`�揈�����I�[�o�[���C�h�B
    virtual void Draw() override ;
};
