//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   �G�̃w�b�_�[
//!
//! @date   2017/02/07~
//!
//! @author sugiura	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once // ���d�C���N���[�h�̖h�~

#include "..//..//ObjectBase.h"
#include "..//..//Stage//StageBase.h"

class Enemy : public ObjectBase
{
private:

public:
	Enemy();
	~Enemy();

	void Update();
	void Render();

	void move();	//�ړ�
	bool collisionStage(StageBase* stage);	//�����蔻��
};