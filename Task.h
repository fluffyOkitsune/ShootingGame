#pragma once

//タスククラス。何かのモジュールはすべてこのTaskクラスを継承する。
class Task {
public:
    virtual ~Task(){}

	//初期化処理は実装してもしなくてもいい
    virtual void Initialize(){}

	//終了処理は実装してもしなくてもいい
    virtual void Finalize(){}

	//更新処理は必ず継承先で実装する
    virtual void Update() = 0;

	//描画処理は必ず継承先で実装する
    virtual void Draw() = 0;
};
