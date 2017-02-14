//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   �v���C���[�̃w�b�_�[
//!
//! @date   2017/02/07~
//!
//! @author sugiura	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once

#include "..//..//ObjectBase.h"
#include "..//..//Stage//StageBase.h"

class Player : public ObjectBase
{
private:
	float m_gravity; //�d��
	bool  m_jump;	 //�W�����v���Ă��邩	t = ���Ă���
	int   m_jumpCnt; //�W�����v���Ă���̎��Ԃ̃J�E���g

public:
	Player();	//�R���X�g���N�^
	~Player();	//�f�X�g���N�^

	void Update();
	void Render();

	void keyMove();	//�L�[�{�[�h����
	void setRect();	//�؂�o���͈͂�ς���
	void gravity();	//�d�͂𔽉f������

	bool collisionStage(StageBase* stage);	//�����蔻��
	void setJumpState(bool tf);				//�W�����v��Ԃ̐؂�ւ�
};
