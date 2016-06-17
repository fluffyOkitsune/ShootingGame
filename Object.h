#pragma once

#include "Task.h"

class Object : public Task {
public:
    virtual ~Object(){}

	// 初期
    virtual void Initialize(){}

	// 終了
    virtual void Finalize(){}

	// 更新
    virtual void Update() = 0;

	// 描画
    virtual void Draw() = 0;

	// 有効化
	virtual void Activate(int t, int x,int y) = 0;

};
