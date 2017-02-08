//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitle.h
//!
//! @brief  プレイ処理のヘッダーファイル
//!
//! @date   日付		2016/12/12
//!
//! @author 制作者名	sugiura
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#include "GameBase.h"
#include "..//Object//Character/Player//Player.h"
#include "..//Object//Stage//Floor.h"
#include "..//Object//Stage//Wall.h"

#pragma once // 多重インクルードの防止

class GamePlay : public GameBase
{
private:
	//Player* m_player;
	ObjectBase* m_player;

public:
		GamePlay();
		~GamePlay();
		
		void Update();	//アップデート
		void Render();	//レンダー

		void createMap();	//マップ生成
};

