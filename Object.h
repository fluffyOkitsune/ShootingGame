#pragma once

#include "Task.h"

class Object : public Task {
public:
    virtual ~Object(){}

	// ����
    virtual void Initialize(){}

	// �I��
    virtual void Finalize(){}

	// �X�V
    virtual void Update() = 0;

	// �`��
    virtual void Draw() = 0;

	// �L����
	virtual void Activate(int t, int x,int y) = 0;

};
