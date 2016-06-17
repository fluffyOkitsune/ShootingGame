#include "Config.h"
#include "DxLib.h"

Config::Config(ISceneChanger* changer) : BaseScene(changer) {
}

//初期化
void Config::Initialize(){
	//画像のロード
	mImageHandle = LoadGraph("images/Usagi.png");
}

//更新
void Config::Update(){
	if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){ //Escキーが押されていたら
		//シーンをメニューに変更
		mSceneChanger->ChangeScene(eScene_Menu);
	}
}

//描画
void Config::Draw(){
	BaseScene::Draw();//親クラスの描画メソッドを呼ぶ
	DrawString(0, 0,"設定画面です。",GetColor(255,255,255));
	DrawString(0,20,"Escキーを押すとメニュー画面に戻ります。",GetColor(255,255,255));
}
