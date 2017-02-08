//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   �X�e�[�W�x�[�X�̃\�[�X�t�@�C��
//!
//! @date   2017/02/08~
//!
//! @author sugiura	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#include "StageBase.h"

const int MAX_TIP::MAX_TIP_H = 15;
const int MAX_TIP::MAX_TIP_H = 20;

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;

StageBase::StageBase()
{
}

StageBase::~StageBase()
{
}

//----------------------------------------------------------------------
//! @brief �t�@�C���̌Ăяo��
//!
//! @param[in] �t�@�C����
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void StageBase::importDate(string filename)
{
	ifstream ifs(filename);
	string str;
	int i;

	// �ǂ߂Ȃ��Ƃ�
	if (!ifs)
	{
		for (i = 0; i < MAX_TIP; i++)
		{
			m_mapTip[i / 20][i % 20] = 4;
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
			m_mapTip[i / 20][i % 20] = atoi(token.c_str());
			i++;
		}
		//g_map[i / 20][i % 20] = atoi(token. c_str());
	}
}

