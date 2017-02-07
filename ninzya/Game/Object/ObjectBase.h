//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   ObjectBase.h
//!
//! @brief  �I�u�W�F�N�g�֘A�̃w�b�_�[�t�@�C��
//!
//! @date   ���t		
//!
//! @author ����Җ�	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once

#include "..//GameMain.h"
#include <string>
#include <sstream>

class ObjectBase
{
private:

protected:
	Texture* m_handle;	//�O���t�B�b�N�n���h�� 
	int		 m_grp_x;	//���摜�̂����W 
	int		 m_grp_y;	//���摜�̂����W 
	int		 m_grp_w;	//���摜�̕� 
	int		 m_grp_h;	//���摜�̍��� 
	float	 m_pos_x;	//���Wx 
	float	 m_pos_y;	//���Wy 
	float	 m_spd_x;	//���xx 
	float	 m_spd_y;	//���xy 
	int		 m_state;	//���		
	RECT	 m_rect;	//�؂�o��
	
public:
	ObjectBase();
	~ObjectBase();

	virtual void Update();	//�X�V
	virtual void Render();	//�`��

	void DrawObject(Texture* tex, float pos_x, float pos_y, RECT rect);	//�\��

	//�ݒ�
	void SetPos(float x, float y);	//���WX,Y�𓯎��ɐݒ�
	void SetPosX(float x);			//���WX
	void SetPosY(float y);			//���WY
	void SetSpdX(float x);			//���xX
	void SetSpdY(float y);			//���xY
	void SetState(int state);		//���

	//�擾
	float GetPosX();		//X���W
	float GetPosY();		//Y���W
	float GetSpdX();		//���xX
	float GetSpdY();		//���xY
	int   GetGrpH();		//����
	int	  GetGrpW();		//��
	int	  GetState();		//���  
	
	//�ړ�
	void keyMove();		//�L�[�{�[�h����
	void mouseMove();	//�}�E�X

};
