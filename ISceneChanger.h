#pragma once

// 列挙型
enum eScene{
	//メニュー画面
	eScene_Menu,

	//ゲーム画面
	eScene_Game,

	//設定画面
	eScene_Config,

	//無し
	eScene_None,
};

//シーンを変更するためのインターフェイスクラス
class ISceneChanger {
public:
	virtual ~ISceneChanger() = 0;

	//指定シーンに変更する
	virtual void ChangeScene(eScene NextScene) = 0;
};
