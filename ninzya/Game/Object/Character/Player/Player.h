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

public:
	Player();	//�R���X�g���N�^
	~Player();	//�f�X�g���N�^

	//�ړ�
	void keyMove();		//�L�[�{�[�h����

	void Update();
	void Render();
};