#include "ObjectMng.h"

ObjectMng::ObjectMng(){
}
ObjectMng::ObjectMng(Player* p){
	// æÆ©
	ImageUsagi = LoadGraph("Usagi.png");

	// G
	for(int i = 0 ; i < NUM_ENEMY_OBJ ; i++){
		enemy[i] = Enemy();
		enemy[i].player = p;
	}
	// Ge		
	for(int i = 0 ; i < NUM_ENEMY_BULLET_OBJ ; i++){
		bullet[i] = EnemyBullet();
		bullet[i].player = p;
	}
	// GtFNg		
	for(int i = 0 ; i < NUM_EFFECT_OBJ ; i++){
		effect[i] = Effect();
	}
}
// ú»
void ObjectMng::Initialize(){
	// G
	enemyID = 0;
	for(int i = 0 ; i < NUM_ENEMY_OBJ ; i++){
		enemy[i].Initialize();
	}
	// Ge	
	bulletID = 0;
	for(int i = 0 ; i < NUM_ENEMY_BULLET_OBJ ; i++){
		bullet[i].Initialize();
	}
	// GtFNg	
	effectID = 0;
	for(int i = 0 ; i < NUM_EFFECT_OBJ ; i++){
		effect[i].Initialize();
	}
}
//XV
void ObjectMng::Update(){
	// G
	for(int i = 0 ; i < NUM_ENEMY_OBJ ; i++){
		enemy[i].Update();

		Enemy* e = &enemy[i];
		if(e->shoot >=0){
			bullet[bulletID].Activate(e->shoot,(int)e->posX,(int)e->posY);
			e->shoot = -1;
		}
	}
	// Ge	
	for(int i = 0 ; i < NUM_ENEMY_BULLET_OBJ ; i++){
		bullet[i].Update();
	}
	// GtFNg	
	for(int i = 0 ; i < NUM_EFFECT_OBJ ; i++){
		effect[i].Update();
	}
}
// `æ
void ObjectMng::Draw(){
	// G
	for(int i = 0 ; i < NUM_ENEMY_OBJ ; i++){
		if(enemy[i].active)
			enemy[i].Draw();
	}
	// Ge
	for(int i = 0 ; i < NUM_ENEMY_BULLET_OBJ ; i++){
		if(bullet[i].active)
			bullet[i].Draw();
	}
	// GtFNg
	for(int i = 0 ; i < NUM_EFFECT_OBJ ; i++){
		if(effect[i].active)
			effect[i].Draw();
	}
}
// Lø»
void ObjectMng::EnemyActivate(int t, int x, int y){
	// eÛðLø»
	enemy[enemyID].Activate(t,x,y);
	// IDðÚ®
	enemyID = (enemyID+1) % NUM_ENEMY_OBJ;
}
// Lø»
void ObjectMng::BulletActivate(int t, int x, int y){
	// eÛðLø»
	bullet[bulletID].Activate(t,x,y);
	// IDðÚ®
	bulletID = (bulletID+1) % NUM_ENEMY_BULLET_OBJ;
}
// Lø»
void ObjectMng::EffectActivate(int t, int x, int y){
	// eÛðLø»
	effect[effectID].Activate(t,x,y);
	// IDðÚ®
	effectID = (effectID+1) % NUM_EFFECT_OBJ;
};