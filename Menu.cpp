#include "Menu.h"
#include "DxLib.h"

Menu::Menu(ISceneChanger* changer) : BaseScene(changer) {
}

// 初期化
void Menu::Initialize(){
	// 画像のロード
	mImageHandle = LoadGraph("images/Scene_Menu.png");
}

// 更新
void Menu::Update(){
	// Gキーが押されていたら
	if(CheckHitKey(KEY_INPUT_G)!=0){
		// シーンをゲーム画面に変更
		mSceneChanger->ChangeScene(eScene_Game);
	}
	// Cキーが押されていたら
	if(CheckHitKey(KEY_INPUT_C)!=0){
		// シーンを設定画面に変更
		mSceneChanger->ChangeScene(eScene_Config);
	}
}

// 描画
void Menu::Draw(){
	// 親クラスの描画メソッドを呼ぶ
	BaseScene::Draw();
	DrawString(0, 0,"メニュー画面です。",GetColor(255,255,255));
	DrawString(0,20,"Gキーを押すとゲーム画面に進みます。",GetColor(255,255,255));
	DrawString(0,40,"Cキーを押すと　設定画面に進みます。",GetColor(255,255,255));
}
