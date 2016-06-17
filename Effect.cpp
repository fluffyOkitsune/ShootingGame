#include <cmath>
#include "Effect.h"
#include "DxLib.h"

#define VEL	2
#define PI	3.14159265358979265358979

Effect::Effect(){
}

// ������
void Effect::Initialize(){
	active = false;

}
// �X�V
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
// �`��
void Effect::Draw(){
	if(active){		
		switch(type){
		case 0 :
			// �����G�t�F�N�g
			int size = (int)(time / 2);
			for(int i = 0 ; i<6 ; i++){
				// ��]���鑬��
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
// �L����
void Effect::Activate(int t, int x, int y){
	type = t;
	posX = (float)x;
	posY = (float)y;

	time = 0;

	active = true;

}


