#include "ObjectMng.h"

ObjectMng::ObjectMng(){
}
ObjectMng::ObjectMng(Player* p){
	// ‰æ‘œ‚Æ‚©
	ImageUsagi = LoadGraph("Usagi.png");

	// “G
	for(int i = 0 ; i < NUM_ENEMY_OBJ ; i++){
		enemy[i] = Enemy();
		enemy[i].player = p;
	}
	// “G’e		
	for(int i = 0 ; i < NUM_ENEMY_BULLET_OBJ ; i++){
		bullet[i] = EnemyBullet();
		bullet[i].player = p;
	}
	// ƒGƒtƒFƒNƒg		
	for(int i = 0 ; i < NUM_EFFECT_OBJ ; i++){
		effect[i] = Effect();
	}
}
// ‰Šú‰»
void ObjectMng::Initialize(){
	// “G
	enemyID = 0;
	for(int i = 0 ; i < NUM_ENEMY_OBJ ; i++){
		enemy[i].Initialize();
	}
	// “G’e	
	bulletID = 0;
	for(int i = 0 ; i < NUM_ENEMY_BULLET_OBJ ; i++){
		bullet[i].Initialize();
	}
	// ƒGƒtƒFƒNƒg	
	effectID = 0;
	for(int i = 0 ; i < NUM_EFFECT_OBJ ; i++){
		effect[i].Initialize();
	}
}
//XV
void ObjectMng::Update(){
	// “G
	for(int i = 0 ; i < NUM_ENEMY_OBJ ; i++){
		enemy[i].Update();

		Enemy* e = &enemy[i];
		if(e->shoot >=0){
			bullet[bulletID].Activate(e->shoot,(int)e->posX,(int)e->posY);
			e->shoot = -1;
		}
	}
	// “G’e	
	for(int i = 0 ; i < NUM_ENEMY_BULLET_OBJ ; i++){
		bullet[i].Update();
	}
	// ƒGƒtƒFƒNƒg	
	for(int i = 0 ; i < NUM_EFFECT_OBJ ; i++){
		effect[i].Update();
	}
}
// •`‰æ
void ObjectMng::Draw(){
	// “G
	for(int i = 0 ; i < NUM_ENEMY_OBJ ; i++){
		if(enemy[i].active)
			enemy[i].Draw();
	}
	// “G’e
	for(int i = 0 ; i < NUM_ENEMY_BULLET_OBJ ; i++){
		if(bullet[i].active)
			bullet[i].Draw();
	}
	// ƒGƒtƒFƒNƒg
	for(int i = 0 ; i < NUM_EFFECT_OBJ ; i++){
		if(effect[i].active)
			effect[i].Draw();
	}
}
// —LŒø‰»
void ObjectMng::EnemyActivate(int t, int x, int y){
	// ’eŠÛ‚ð—LŒø‰»
	enemy[enemyID].Activate(t,x,y);
	// ID‚ðˆÚ“®
	enemyID = (enemyID+1) % NUM_ENEMY_OBJ;
}
// —LŒø‰»
void ObjectMng::BulletActivate(int t, int x, int y){
	// ’eŠÛ‚ð—LŒø‰»
	bullet[bulletID].Activate(t,x,y);
	// ID‚ðˆÚ“®
	bulletID = (bulletID+1) % NUM_ENEMY_BULLET_OBJ;
}
// —LŒø‰»
void ObjectMng::EffectActivate(int t, int x, int y){
	// ’eŠÛ‚ð—LŒø‰»
	effect[effectID].Activate(t,x,y);
	// ID‚ðˆÚ“®
	effectID = (effectID+1) % NUM_EFFECT_OBJ;
};