//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   �v���C���[�̃w�b�_�[
//!
//! @date   2017/02/07~
//!
//! @author sugiura	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once

#include "..//..//ObjectBase.h"

class Player : public ObjectBase
{
private:
	float m_gravity; //�d��
	int m_time;

public:
	Player();	//�R���X�g���N�^
	~Player();	//�f�X�g���N�^

	void Update();
	void Render();

	void keyMove();	//�L�[�{�[�h����
	void setRect();	//�؂�o���͈͂�ς���
	void gravity();	//�d�͂𔽉f������
};
