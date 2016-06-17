#include "SceneMgr.h"
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	// ウィンドウモード変更と初期化と裏画面設定
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK );

	// シーンマネージャーの初期化
	SceneMgr sceneMgr;
	sceneMgr.Initialize();

	// 画面更新 & メッセージ処理 & 画面消去
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
		// 更新
		sceneMgr.Update();

		// 描画
		sceneMgr.Draw();
	}

	sceneMgr.Finalize();

	// DXライブラリ終了処理
	DxLib_End();

	return 0;
}