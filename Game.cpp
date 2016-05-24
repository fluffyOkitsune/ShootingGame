#include <windows.h>

#include "Game.h"
#include "DxLib.h"

#define NUM_BULLET_OBJ	20
#define SHOOT_INTERVAL	6

Game::Game(ISceneChanger* changer) : BaseScene(changer) {

}

//初期化
void Game::Initialize(){
	// mImageHandle = LoadGraph("images/Scene_Game.png");

	// 自機
	p = Player();
	
	// 自機の弾丸
	for(int i = 0 ; i < NUM_BULLET_OBJ ; i++){
		bullet[i] = Bullet();
		bullet[i].Initialize();
	}

	// 弾丸ID
	bulletID = 0;

	// 初期化
	p.Initialize();

	// 敵

	// 敵弾

}

//更新
void Game::Update(){
	//Escキーが押されていたら
	if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){
		//シーンをメニューに変更
		mSceneChanger->ChangeScene(eScene_Menu);
	}
	// 自機
	p.Update();
	
	// 自機の弾丸
	for(int i=0 ; i<NUM_BULLET_OBJ; i++){
		bullet[i].Update();
	}
	
	// 敵

	// 敵弾
	
	//shootInterval = 0のときのみ射撃可能
	if(p.shootInterval > 0)
		p.shootInterval--;
	else if(CheckHitKey(KEY_INPUT_SPACE) != 0)
		Shoot();

}

//描画
void Game::Draw(){
	//親クラスの描画メソッドを呼ぶ
	BaseScene::Draw();
	DrawString(0, 0,"ゲーム画面です。",GetColor(255,255,255));
	DrawString(0,20,"Escキーを押すとメニュー画面に戻ります。",GetColor(255,255,255));
	
	// 自機
	p.Draw();

	// 自機の弾丸
	for(int i=0 ; i<NUM_BULLET_OBJ; i++){
		bullet[i].Draw();
	}
	
	// 敵

	// 敵弾

}

// 射撃
void Game::Shoot(){
	// 射撃不可時間を設定
	p.shootInterval = SHOOT_INTERVAL;
	// 弾丸を有効化
	bullet[bulletID].Activate(p.posX,p.posY);
	// IDを移動
	bulletID = (bulletID+1) % NUM_BULLET_OBJ;
}