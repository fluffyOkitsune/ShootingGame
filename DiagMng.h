// Game -> DiagMng
#include "Task.h"

class DiagMng : public Task{
	
	DiagMng::DiagMng();

	// ������
	void Initialize() override;

	// �X�V
	void Update() override;

	// �`��
	void Draw() override;

};