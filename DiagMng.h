// Game -> DiagMng
#include "Task.h"

class DiagMng : public Task{
	
	DiagMng::DiagMng();

	// 初期化
	void Initialize() override;

	// 更新
	void Update() override;

	// 描画
	void Draw() override;

};