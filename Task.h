#pragma once

//�^�X�N�N���X�B�����̃��W���[���͂��ׂĂ���Task�N���X���p������B
class Task {
public:
    virtual ~Task(){}

	//�����������͎������Ă����Ȃ��Ă�����
    virtual void Initialize(){}

	//�I�������͎������Ă����Ȃ��Ă�����
    virtual void Finalize(){}

	//�X�V�����͕K���p����Ŏ�������
    virtual void Update() = 0;

	//�`�揈���͕K���p����Ŏ�������
    virtual void Draw() = 0;
};
