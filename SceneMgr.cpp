#include "DxLib.h"
#include "Config.h"
#include "Game.h"
#include "Menu.h"
#include "SceneMgr.h"

// 次のシーン管理変数
SceneMgr::SceneMgr() : mNextScene(eScene_None) {
	mScene = (BaseScene*) new Menu(this);
}

// 初期化
void SceneMgr::Initialize(){
	mScene->Initialize();
}

// 終了処理
void SceneMgr::Finalize(){
	mScene->Finalize();
}

// 更新
void SceneMgr::Update(){
	if(mNextScene != eScene_None){
		//次のシーンがセットされていたら
		mScene->Finalize();
		
		//現在のシーンの終了処理を実行
		delete mScene;

		switch(mNextScene){
			//シーンによって処理を分岐
		case eScene_Menu:
			//次の画面がメニューなら
			//メニュー画面のインスタンスを生成する
			mScene = (BaseScene*) new Menu(this);
			break;

		case eScene_Game:
			mScene = (BaseScene*) new Game(this);
			break;

		case eScene_Config:
			mScene = (BaseScene*) new Config(this);
			break;
		}
		//次のシーン情報をクリア
		mNextScene = eScene_None;

		//シーンを初期化
		mScene->Initialize();
	}
	//シーンの更新
	mScene->Update();
}

// 描画
void SceneMgr::Draw(){
	//シーンの描画
	mScene->Draw(); 
}

// 引数 nextScene にシーンを変更する
void SceneMgr::ChangeScene(eScene NextScene){
	//次のシーンをセットする
	mNextScene = NextScene;
}
