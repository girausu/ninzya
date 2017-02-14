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
	//----------------------オブジェクトの生成-----------------------//
	m_player = new Player();
	m_enemy  = new Enemy();

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
	delete m_enemy;

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
					m_player->setJumpState(false);
				}
			}

			//ステージに当たっていない状態でステージよりも上にいたら
			if (m_stage[i][j] != nullptr && m_player->collisionStage(m_stage[i][j]) == false)
			{
				if (m_player->GetPosY() <= m_stage[i][j]->getPosY() && m_player->GetSpdY() == 0)
				{
					m_player->setJumpState(true);
				}
			}
		}
	}



	//------------------------------敵------------------------------------//
	
	m_enemy->Update();

	//当たり判定
	for (int i = 0; i < MAX_TIP::MAX_TIP_H; i++)
	{
		for (int j = 0; j < MAX_TIP::MAX_TIP_W; j++)
		{
			if (m_stage[i][j] != nullptr && m_enemy->collisionStage(m_stage[i][j]) == true)
			{
				//左に移動させる
				if (m_enemy->GetSpdX() > 0)
				{
					m_enemy->SetSpdX(-5);
				}	 //右に移動させる
				else 
				{
					m_enemy->SetSpdX(5);
				}
			}
		}
	}

	float spd;
	spd = m_player->GetSpdY();
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

	m_enemy->Render();

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
				m_stage[i][j]->setPosY(static_cast<float>(m_stage[i][j]->getGrpH()) * i);
				m_stage[i][j]->setPosX(static_cast<float>(m_stage[i][j]->getGrpW()) * j);
				break;
				
			case 2:
				m_stage[i][j] = new Wall();
				m_stage[i][j]->setPosY(static_cast<float>(m_stage[i][j]->getGrpH()) * i);
				m_stage[i][j]->setPosX(static_cast<float>(m_stage[i][j]->getGrpW()) * j);
				break;

			}
		}
	}
}
