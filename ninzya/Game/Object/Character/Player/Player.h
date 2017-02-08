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

	void Update();
	void Render();

	void keyMove();	//キーボード操作
	void setRect();	//切り出し範囲を変える
};