	//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
	//! @file   GameMain.cpp
	//!
	//! @brief  �Q�[���֘A�̃\�[�X�t�@�C��
	//!
	//! @date   ���t		
	//!
	//! @author ����Җ�	
	//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#define _GAMEMAIN_
#include "GameMain.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Scene\GamePlay.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;

// �v���g�^�C�v�錾 ====================================================

// �O���[�o���ϐ��̒�` ====================================================
GameBase* base;

// �֐��̒�` ==============================================================

//----------------------------------------------------------------------
//! @brief �Q�[���̏���������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void InitializeGame(void)
{
	//�}�b�v�̓ǂݍ���
	importDate("Resources\\Map\\simpleStage.csv");

	//�V�[���̏�����
	base = new GamePlay();
}

//----------------------------------------------------------------------
//! @brief �Q�[���̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void UpdateGame(void)
{
	base->Update();
}

//----------------------------------------------------------------------
//! @brief �Q�[���̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void RenderGame(void)
{
	base->Render();
}

//----------------------------------------------------------------------
//! @brief �Q�[���̏I������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void FinalizeGame(void)
{
	delete base;
}

//----------------------------------------------------------------------
//! @brief �؂�o���ĕ\��
//!
//! @param[in] �n���h��, �؂�o�����摜
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void DrawObject(Texture* tex, float pos_x, float pos_y, RECT rect)
{
	//�n���h�� ���WXY �؂�o���͈�, �F, ���W�A���l, ��]�̒��S���W, �g��{��
	g_spriteBatch->Draw(tex->m_pTexture, Vector2(pos_x, pos_y),
		&rect, Colors::White, 0.0f, Vector2(0, 0), Vector2(1, 1));
}

//----------------------------------------------------------------------
//! @brief �t�@�C���̌Ăяo��
//!
//! @param[in]	�Ȃ�	
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void importDate(string filename)
{
	ifstream ifs(filename);
	string str;
	int i;

	// �ǂ߂Ȃ��Ƃ�
	if (!ifs)
	{
		for (i = 0; i < MAX_TIP; i++)
		{
			g_map[i / 20][i % 20] = 4;
		}
		return;
	}
	i = 0;
	while (getline(ifs, str))
	{
		string token;
		istringstream stream(str);

		// 1�s�̂����A�������R���}�𕪊�����
		while (getline(stream, token, ','))
		{
			// ���ׂĂ͕�����Ƃ��ēǂݍ��܂�邽��
			// ���l�͕ϊ����K�v
			g_map[i / 20][i % 20] = atoi(token.c_str());
			i++;
		}
		//g_map[i / 20][i % 20] = atoi(token. c_str());
	}
}


