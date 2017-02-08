//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   �v���C���[�̃\�[�X
//!
//! @date   2017/02/07~
//!
//! @author sugiura	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#include "Player.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Player::Player()
{
	//\Resources\Images\Character\Player
	//�e�ϐ��̐ݒ�
	m_handle = new Texture(L"Resources\\Images\\Character\\Player\\move.png");
	m_grp_x = 0;
	m_grp_y = 0;
	m_grp_w = 90;
	m_grp_h = 130;
	m_pos_x = 0;
	m_pos_y = 0;
	m_spd_x = 0;
	m_spd_y = 0;
	m_state = 1;
	m_rect = { m_grp_x, m_grp_y, m_grp_w, m_grp_h };
}

//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Player::~Player()
{

}

//----------------------------------------------------------------------
//! @brief �X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Player::Update()
{
	//���x�̏�����
	m_spd_x = 0;
	m_spd_y = 0;

	//�L�[�{�[�h�ňړ�
	keyMove();
	
	//�摜�̐؂蔲���͈͂��w��
	setRect();

	//�ړ�
	m_pos_x += m_spd_x;
	m_pos_y += m_spd_y;
}

//----------------------------------------------------------------------
//! @brief �`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Player::Render()
{
	m_rect = { m_grp_x, m_grp_y, m_grp_w, m_grp_h };

	DrawObject(m_handle, m_pos_x, m_pos_y, m_rect);

	//�n���h�� ���WXY �؂�o���͈�, �F, ���W�A���l, ��]�̒��S���W, �g��{��
	//g_spriteBatch->Draw(m_handle->m_pTexture, Vector2(0, 0), &rect, Colors::White, 0.0f, Vector2(0, 0), Vector2(1, 1));

	//g_spriteBatch->Draw(m_handle->m_pTexture, Vector2(m_pos_x, m_pos_y), &m_rect, 
	//					Colors::White, 0.0f,  Vector2(0, 0), Vector2(0.5f, 0.5f));
}

//--------------------Update(),Render()�ȊO�̊֐����`---------------//

//----------------------------------------------------------------------
//! @brief �L�[�{�[�h����ňړ�
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Player::keyMove()
{
	// �ړ����̓���
	if (m_spd_x == 0 && m_spd_y == 0)
	{	
		if (g_key.Right)
		{
			m_spd_x = 5;
		}
		else if (g_key.Left)
		{
			m_spd_x = -5;
		}
		else if (g_key.Up)
		{
			m_spd_y = -5;
		}
		else if (g_key.Down)
		{
			m_spd_y = 5;
		}
	}
}

//----------------------------------------------------------------------
//! @brief �L�[�{�[�h�ł̓��͂ɉ����ĉ摜�̐؂蔲���͈͂�ς���
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Player::setRect()
{
	if (g_key.Right)
	{
		//m_grp_x = 0;
		m_grp_y = 270;
	}
	else if (g_key.Left)
	{
		//m_grp_x = 0;
		m_grp_y = 0;
	}
	else if (g_key.Up)
	{
		//m_grp_x = 0;
		m_grp_y = 90;
	}
	else if (g_key.Down)
	{
		//m_grp_x = 0;
		m_grp_y = 0;
	}

}
