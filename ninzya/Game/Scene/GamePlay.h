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
#include "..//Object/ObjectBase.h"

#pragma once // 多重インクルードの防止

class GamePlay : public GameBase
{
private:

public:
		GamePlay();
		~GamePlay();
		
		void Update();	//アップデート
		void Render();	//レンダー
};

