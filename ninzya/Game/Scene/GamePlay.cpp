//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.cpp
//!
//! @brief  �Q�[���v���C�����̃\�[�X�t�@�C��
//!
//! @date   ���t		
//!
//! @author ����Җ�	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "..//GameMain.h"
#include "GamePlay.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
GamePlay::GamePlay()
{
	m_player = new Player();

	for (int i = 0; i < MAX_TIP::MAX_TIP_H; i++)
	{
		for (int j = 0; j < MAX_TIP::MAX_TIP_W; j++)
		{
			m_stage[i][j] = nullptr;
		}
	}

	//�}�b�v�̐���
	createMap();
}

//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
GamePlay::~GamePlay()
{
	delete m_player;

	for (int i = 0; i < MAX_TIP::MAX_TIP_H; i++)
	{
		for (int j = 0; j < MAX_TIP::MAX_TIP_W; j++)
		{
			if (m_stage != nullptr)
			{
				delete m_stage[i][j];
			}
		}
	}
}

//----------------------------------------------------------------------
//! @brief �X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void GamePlay::Update()
{
	//------------------------�v���C���[----------------------------------//
	m_player->Update();	//�X�V

	//�v���C���[�ƃX�e�[�W�̂����蔻��
	for (int i = 0; i < MAX_TIP::MAX_TIP_H; i++)
	{
		for (int j = 0; j < MAX_TIP::MAX_TIP_W; j++)
		{
			//�X�e�[�W�ƃv���C���[�̂����蔻��
			if (m_stage[i][j] != nullptr && m_player->collisionStage(m_stage[i][j]) == true)
			{
				if (m_player->GetSpdY() > 0)
				{
					//�v���C���[���X�e�[�W�̏�Ɉړ�������
					m_player->SetPosY(m_stage[i][j]->getPosY() - m_player->GetGrpH() / 2);

					//�v���C���[�𒅒n���Ă����Ԃɂ���
					m_player->SetState(1);
				}
			}	 

			//�X�e�[�W�ɓ������Ă��Ȃ���ԂŃX�e�[�W������ɂ�����
			if (m_stage[i][j] != nullptr &&m_player->collisionStage(m_stage[i][j]) == false )
			{
				m_player->SetState(2);
			}
		}
	}

	float spd;
	spd = m_player->GetSpdY();
	//for (int i = 0; i < MAX_TIP::MAX_TIP_H; i++)
	//{
	//	for (int j = 0; i < MAX_TIP::MAX_TIP_W; j++)
	//	{
	//		m_stage[i][j]->Update();
	//	}
	//}
}

//----------------------------------------------------------------------
//! @brief �`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void GamePlay::Render()
{
	m_player->Render();

	for (int i = 0; i < MAX_TIP::MAX_TIP_H; i++)
	{
		for (int j = 0; j < MAX_TIP::MAX_TIP_W; j++)
		{
			if (m_stage[i][j] != nullptr)
			{
				m_stage[i][j]->Render();
			}
		}
	}

}

//----------------------------------------------------------------------
//! @brief �}�b�v����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void GamePlay::createMap()
{

	for (int i = 0; i < MAX_TIP::MAX_TIP_H; i++)
	{
		for (int j = 0; j < MAX_TIP::MAX_TIP_W; j++)
		{
			switch (g_map[i][j])
			{
			default:
				break;	
			
			case 1:
				m_stage[i][j] = new Floor();
				m_stage[i][j]->setPosY(m_stage[i][j]->getGrpH() * i);
				m_stage[i][j]->setPosX(m_stage[i][j]->getGrpW() * j);
				break;
				
			case 2:
				m_stage[i][j] = new Wall();
				m_stage[i][j]->setPosY(m_stage[i][j]->getGrpH() * i);
				m_stage[i][j]->setPosX(m_stage[i][j]->getGrpW() * j);
				break;

			}
		}
	}
}
