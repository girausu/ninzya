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
	   :ObjectBase()
{
	//\Resources\Images\Character\Player
	//�e�ϐ��̐ݒ�
	m_handle = new Texture(L"Resources\\Images\\Character\\Player\\moves.png");
	m_grp_w = 72;
	m_grp_h = 112;
	m_pos_x = 640 / 2;
	m_pos_y = 200;
	m_spd_x = 0;
	m_spd_y = 0;
	m_state = 2;
	m_rect = { m_grp_x, m_grp_y, m_grp_w, m_grp_h };

	m_gravity = 0.01f;
	m_time = 0;
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
	//�X�y�[�X�L�[�Ńv���C���[�̏�����
	if (g_key.Space)
	{

	}

	//���x�̏�����
	m_spd_x = 0;
	m_spd_y = 0;

	//�L�[�{�[�h�ňړ�
	keyMove();
	
	//�摜�̐؂蔲���͈͂��w��
	//setRect();

	//�v���C���[�ɏd�͂�K�p
	gravity();

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
	//DrawObject(m_handle, m_pos_x, m_pos_y, m_rect);

	//�n���h�� ���WXY �؂�o���͈�, �F, ���W�A���l, ��]�̒��S���W, �g��{��
	//g_spriteBatch->Draw(m_handle->m_pTexture, Vector2(0, 0), &rect, Colors::White, 0.0f, Vector2(0, 0), Vector2(1, 1));

	if (m_state != 0)
	{
		g_spriteBatch->Draw(m_handle->m_pTexture, Vector2(m_pos_x, m_pos_y), &m_rect,
			Colors::White, 0.0f, Vector2(0, 0), Vector2(0.5f, 0.5f));
	}
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
	//// �ړ����̓���
	//if (m_spd_x == 0 && m_spd_y == 0)
	//{	
		if (g_key.Right)
		{
			m_spd_x = 5;
		}
		
		if (g_key.Left)
		{
			m_spd_x = -5;
		}
	
		if (g_key.Up)
		{
			m_spd_y = -10;

			if (m_state == 1)
			{
				m_state = 2;
			}
		}
		
		if (g_key.Down)
		{
			m_spd_y = 5;
		}
	//}
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
		m_grp_y = 390;
	}
	else if (g_key.Left)
	{
		//m_grp_x = 0;
		m_grp_y = 260;
	}
	else if (g_key.Up)
	{
		//m_grp_x = 0;
		m_grp_y = 130;
	}
	else if (g_key.Down)
	{
		//m_grp_x = 0;
		m_grp_y = 0;
	}

	m_rect = { m_grp_x, m_grp_y, m_grp_w + m_grp_x, m_grp_h + m_grp_y};
}

//----------------------------------------------------------------------
//! @brief �L�[�{�[�h�ł̓��͂ɉ����ĉ摜�̐؂蔲���͈͂�ς���
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Player::gravity()
{
	//�W�����v���Ă���ꍇ
	if (m_state == 2)
	{
		//�d�͂�Y�ɑ���
		m_spd_y   += m_gravity;
		m_gravity += 0.05f;
	}	//�W�����v���Ă��Ȃ��ꍇ�d�͂�������   
	else if (m_state == 1)
	{
		m_gravity = 0.01f;
	}
}

//----------------------------------------------------------------------
//! @brief �X�e�[�W�Ƃ̓����蔻��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
bool Player::collisionStage(StageBase * stage)
{
	//�傫���𔼕��ɂ��Ă���̂� 2�Ŋ���

	if (stage->getPosX()					<= m_pos_x + m_grp_w / 2	&&	//�E��
		stage->getPosX() + stage->getGrpW() >= m_pos_x				&&		//����
		stage->getPosY()					<= m_pos_y + m_grp_h / 2	&&	//����
		stage->getPosY() + stage->getGrpH() >= m_pos_y)						//�㑤
	{
		return true;
	}
	return false;
}

