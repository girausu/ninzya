//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   プレイヤーのヘッダー
//!
//! @date   2017/02/07~
//!
//! @author sugiura	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once

#include "..//..//ObjectBase.h"

class Player : public ObjectBase
{
private:

public:
	Player();	//コンストラクタ
	~Player();	//デストラクタ

	//移動
	void keyMove();		//キーボード操作

	void Update();
	void Render();
};