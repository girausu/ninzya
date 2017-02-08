//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.h
//!
//! @brief  �Q�[���֘A�̃w�b�_�t�@�C��
//!
//! @date   ���t
//!
//! @author ����Җ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#include <Windows.h>
#include <d3d11.h>
#include <SimpleMath.h>
#include "..\DirectXTK.h"
#include "..\Texture.h"
#include <string>

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

#ifndef _GAMEMAIN_
#define EXTERN extern
#else
#define EXTERN
#endif

// �萔�̒�` ==============================================================
static const int MAX_TIP = 300;

// �Q�[���^�C�g��
#define GAME_TITLE "thousand"

// �Q�[�����
#define SCREEN_WIDTH  640    // ��[pixel]
#define SCREEN_HEIGHT 480    // ����[pixel]

// �֐��̐錾 ==============================================================

// �Q�[���̏���������
void InitializeGame(void);

// �Q�[���̍X�V����
void UpdateGame(void);

// �Q�[���̕`�揈��
void RenderGame(void);

// �Q�[���̏I������
void FinalizeGame(void);

//�f�[�^�̓ǂݍ���
void importDate(std::string filename);

// �O���[�o���ϐ��̒�` ====================================================
EXTERN int g_key_code;					//�L�[���
EXTERN int g_key_old;					//�O�t���[���̃L�[���
									

