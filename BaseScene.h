#pragma once

#include "Task.h"
#include "ISceneChanger.h"

class BaseScene : public Task {

protected:
	//画像ハンドル格納用変数
    int mImageHandle;

	//クラス所有元にシーン切り替えを伝えるインターフェイス
    ISceneChanger* mSceneChanger;

public :
    BaseScene(ISceneChanger* changer);
    virtual ~BaseScene(){}

	//初期化処理をオーバーライド
	virtual void Initialize() override {}

	//終了処理をオーバーライド。
    virtual void Finalize() override ;

	//更新処理をオーバーライド。
    virtual void Update() override {}

	//描画処理をオーバーライド。
    virtual void Draw() override ;
};
