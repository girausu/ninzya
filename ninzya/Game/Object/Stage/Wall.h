//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   �}�b�v�̃w�b�_�[
//!
//! @date   2017/02/07~
//!
//! @author sugiura	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once

#include "..//..//GameMain.h"
#include "..//ObjectBase.h"

class Wall : public ObjectBase
{
private:

protected:
	
public:
	Wall();
	~Wall();

	void Update();
	void Render();
};

//�p�������ϐ�
//Texture* m_handle;	//�O���t�B�b�N�n���h�� 
//int	   m_grp_x;	//���摜�̂����W 
//int	   m_grp_y;	//���摜�̂����W 
//int	   m_grp_w;	//���摜�̕� 
//int	   m_grp_h;	//���摜�̍��� 
//float	 m_pos_x;	//���Wx 
//float	 m_pos_y;	//���Wy 
//float	 m_spd_x;	//���xx 
//float	 m_spd_y;	//���xy 
//int		 m_state;	//���		
//RECT	 m_rect;	//�؂�o��
