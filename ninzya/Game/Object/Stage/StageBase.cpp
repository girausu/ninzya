//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   ステージベースのソースファイル
//!
//! @date   2017/02/08~
//!
//! @author sugiura	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#include "StageBase.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;

//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
StageBase::StageBase()
{
	importDate("Resources\\Map\\simpleStage.csv");
}

//----------------------------------------------------------------------
//! @brief デストラクタ
//!
//! @param[in]　なし
//!
//! @return なし
//----------------------------------------------------------------------
StageBase::~StageBase()
{
}

//----------------------------------------------------------------------
//! @brief データの読み込み
//!
//! @param[in]　ファイル名
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
			//g_map[i / 20][i % 20] = 4;
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
			//g_map[i / 20][i % 20] = atoi(token.c_str());
			m_mapTip[i / 20][i % 20] = atoi(token.c_str());
			i++;
		}
	}
}

//----------------------------------------------------------------------
//! @brief X座標の設定
//!
//! @param[in]　なし
//!
//! @return なし
//----------------------------------------------------------------------
void StageBase::setPosX(float x)
{
	m_pos_x = x;
}

//----------------------------------------------------------------------
//! @brief Y座標の設定
//!
//! @param[in]　
//!
//! @return なし
//----------------------------------------------------------------------
void StageBase::setPosY(float y)
{
	m_pos_y = y;
}

//----------------------------------------------------------------------
//! @brief 状態の設定
//!
//! @param[in]　state
//!
//! @return なし
//----------------------------------------------------------------------
void StageBase::setState(int state)
{
	m_state = state;
}

//----------------------------------------------------------------------
//! @brief X座標の取得
//!
//! @param[in]　なし
//!
//! @return X座標
//----------------------------------------------------------------------
float StageBase::getPosX()
{
	return m_pos_x;
}

//----------------------------------------------------------------------
//! @brief Y座標の取得
//!
//! @param[in]　なし
//!
//! @return Y座標
//----------------------------------------------------------------------
float StageBase::getPosY()
{
	return m_pos_y;
}

//----------------------------------------------------------------------
//! @brief 幅の取得
//!
//! @param[in]　なし
//!
//! @return 幅
//----------------------------------------------------------------------
int StageBase::getGrpW()
{
	return m_grp_w;
}

//----------------------------------------------------------------------
//! @brief 高さの取得
//!
//! @param[in]　なし
//!
//! @return 高さ
//----------------------------------------------------------------------
int StageBase::getGrpH()
{
	return m_grp_h;
}

//----------------------------------------------------------------------
//! @brief 状態の取得
//!
//! @param[in]　なし
//!
//! @return 状態
//----------------------------------------------------------------------
int StageBase::getState()
{
	return m_state;
}















