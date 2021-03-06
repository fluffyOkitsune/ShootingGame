#pragma once

class Task {
public : 
    virtual ~Task(){}

	//初期化
    virtual void Initialize(){}

	//終了
    virtual void Finalize(){}

	//更新
    virtual void Update() = 0;

	//描画
    virtual void Draw() = 0;
};
