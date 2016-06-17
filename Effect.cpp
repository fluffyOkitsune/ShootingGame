#include <cmath>
#include "Effect.h"
#include "DxLib.h"

#define VEL	2
#define PI	3.14159265358979265358979

Effect::Effect(){
}

// 初期化
void Effect::Initialize(){
	active = false;

}
// 更新
void Effect::Update(){
	if(active){
		switch (type){
		case 0 :
			if(time == 30)
				active = false;
			break;
		}
		time++;
	}
}
// 描画
void Effect::Draw(){
	if(active){		
		switch(type){
		case 0 :
			// 爆発エフェクト
			int size = (int)(time / 2);
			for(int i = 0 ; i<6 ; i++){
				// 回転する速さ
				double deg = time / 3;

				int X0 = (int)(posX + ((VEL * time) * std::cos((i * PI + deg)/3)));
				int Y0 = (int)(posY + ((VEL * time) * std::sin((i * PI + deg)/3)));
				DrawOval(X0, Y0, size, size, GetColor(255,128,0), true);
			}
			DrawOval((int)posX, (int)posY, size * 2, size * 2, GetColor(255,255,0), true);
		break;
		}
	}
}
// 有効化
void Effect::Activate(int t, int x, int y){
	type = t;
	posX = (float)x;
	posY = (float)y;

	time = 0;

	active = true;

}


