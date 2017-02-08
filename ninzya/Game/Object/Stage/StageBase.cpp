//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   ステージベースのソースファイル
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
//! @brief ファイルの呼び出し
//!
//! @param[in] ファイル名
//!
//! @return なし
//----------------------------------------------------------------------
void StageBase::importDate(string filename)
{
	ifstream ifs(filename);
	string str;
	int i;

	// 読めないとき
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

		// 1行のうち、文字列よコンマを分割する
		while (getline(stream, token, ','))
		{
			// すべては文字列として読み込まれるため
			// 数値は変換が必要
			m_mapTip[i / 20][i % 20] = atoi(token.c_str());
			i++;
		}
		//g_map[i / 20][i % 20] = atoi(token. c_str());
	}
}

