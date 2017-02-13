//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.cpp
//!
//! @brief  ゲームプレイ処理のソースファイル
//!
//! @date   日付		
//!
//! @author 制作者名	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "..//GameMain.h"
#include "GamePlay.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
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

	//マップの生成
	createMap();
}

//----------------------------------------------------------------------
//! @brief デストラクタ
//!
//! @param[in] なし
//!
//! @return なし
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
//! @brief 更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GamePlay::Update()
{
	//------------------------プレイヤー----------------------------------//
	m_player->Update();	//更新

	//プレイヤーとステージのあたり判定
	for (int i = 0; i < MAX_TIP::MAX_TIP_H; i++)
	{
		for (int j = 0; j < MAX_TIP::MAX_TIP_W; j++)
		{
			//ステージとプレイヤーのあたり判定
			if (m_stage[i][j] != nullptr && m_player->collisionStage(m_stage[i][j]) == true)
			{
				if (m_player->GetSpdY() > 0)
				{
					//プレイヤーをステージの上に移動させる
					m_player->SetPosY(m_stage[i][j]->getPosY() - m_player->GetGrpH() / 2);

					//プレイヤーを着地している状態にする
					m_player->SetState(1);
				}
			}	 

			//ステージに当たっていない状態でステージよりも上にいたら
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
//! @brief 描画処理
//!
//! @param[in] なし
//!
//! @return なし
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
//! @brief マップ生成
//!
//! @param[in] なし
//!
//! @return なし
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
