#include "BaseScene.h"
#include "DxLib.h"

//コンストラクタ
BaseScene::BaseScene(ISceneChanger* changer) : mImageHandle(0) {
	mSceneChanger = changer;
}

void BaseScene::Finalize(){
	DeleteGraph(mImageHandle);
}

void BaseScene::Draw(){
	DrawGraph(0,0,mImageHandle,FALSE);
}
