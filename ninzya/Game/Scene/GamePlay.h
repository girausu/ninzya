//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitle.h
//!
//! @brief  �v���C�����̃w�b�_�[�t�@�C��
//!
//! @date   ���t		2016/12/12
//!
//! @author ����Җ�	sugiura
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#include "GameBase.h"
#include "..//Object/ObjectBase.h"

#pragma once // ���d�C���N���[�h�̖h�~

class GamePlay : public GameBase
{
private:

public:
		GamePlay();
		~GamePlay();
		
		void Update();	//�A�b�v�f�[�g
		void Render();	//�����_�[
};

