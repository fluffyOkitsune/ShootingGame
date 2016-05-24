#pragma once

#include "ISceneChanger.h"
#include "BaseScene.h"

class SceneMgr : public ISceneChanger, Task {

private:
	//シーン管理変数
	BaseScene* mScene;

	//次のシーン管理変数
	eScene mNextScene;

public:
	SceneMgr();

	//初期化
	void Initialize() override;

	//終了処理
	void Finalize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	// 引数 nextScene にシーンを変更する
	void ChangeScene(eScene NextScene) override;

};