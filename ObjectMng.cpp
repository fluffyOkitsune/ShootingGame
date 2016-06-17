#include "ObjectMng.h"

ObjectMng::ObjectMng(){
}
ObjectMng::ObjectMng(Player* p){
	// �摜�Ƃ�
	ImageUsagi = LoadGraph("Usagi.png");

	// �G
	for(int i = 0 ; i < NUM_ENEMY_OBJ ; i++){
		enemy[i] = Enemy();
		enemy[i].player = p;
	}
	// �G�e		
	for(int i = 0 ; i < NUM_ENEMY_BULLET_OBJ ; i++){
		bullet[i] = EnemyBullet();
		bullet[i].player = p;
	}
	// �G�t�F�N�g		
	for(int i = 0 ; i < NUM_EFFECT_OBJ ; i++){
		effect[i] = Effect();
	}
}
// ������
void ObjectMng::Initialize(){
	// �G
	enemyID = 0;
	for(int i = 0 ; i < NUM_ENEMY_OBJ ; i++){
		enemy[i].Initialize();
	}
	// �G�e	
	bulletID = 0;
	for(int i = 0 ; i < NUM_ENEMY_BULLET_OBJ ; i++){
		bullet[i].Initialize();
	}
	// �G�t�F�N�g	
	effectID = 0;
	for(int i = 0 ; i < NUM_EFFECT_OBJ ; i++){
		effect[i].Initialize();
	}
}
//�X�V
void ObjectMng::Update(){
	// �G
	for(int i = 0 ; i < NUM_ENEMY_OBJ ; i++){
		enemy[i].Update();

		Enemy* e = &enemy[i];
		if(e->shoot >=0){
			bullet[bulletID].Activate(e->shoot,(int)e->posX,(int)e->posY);
			e->shoot = -1;
		}
	}
	// �G�e	
	for(int i = 0 ; i < NUM_ENEMY_BULLET_OBJ ; i++){
		bullet[i].Update();
	}
	// �G�t�F�N�g	
	for(int i = 0 ; i < NUM_EFFECT_OBJ ; i++){
		effect[i].Update();
	}
}
// �`��
void ObjectMng::Draw(){
	// �G
	for(int i = 0 ; i < NUM_ENEMY_OBJ ; i++){
		if(enemy[i].active)
			enemy[i].Draw();
	}
	// �G�e
	for(int i = 0 ; i < NUM_ENEMY_BULLET_OBJ ; i++){
		if(bullet[i].active)
			bullet[i].Draw();
	}
	// �G�t�F�N�g
	for(int i = 0 ; i < NUM_EFFECT_OBJ ; i++){
		if(effect[i].active)
			effect[i].Draw();
	}
}
// �L����
void ObjectMng::EnemyActivate(int t, int x, int y){
	// �e�ۂ�L����
	enemy[enemyID].Activate(t,x,y);
	// ID���ړ�
	enemyID = (enemyID+1) % NUM_ENEMY_OBJ;
}
// �L����
void ObjectMng::BulletActivate(int t, int x, int y){
	// �e�ۂ�L����
	bullet[bulletID].Activate(t,x,y);
	// ID���ړ�
	bulletID = (bulletID+1) % NUM_ENEMY_BULLET_OBJ;
}
// �L����
void ObjectMng::EffectActivate(int t, int x, int y){
	// �e�ۂ�L����
	effect[effectID].Activate(t,x,y);
	// ID���ړ�
	effectID = (effectID+1) % NUM_EFFECT_OBJ;
};