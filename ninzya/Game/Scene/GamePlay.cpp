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
	m_player->Update();
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
	for (int i = 0; i < )
}
