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
	float m_gravity; //重力
	int m_time;

public:
	Player();	//コンストラクタ
	~Player();	//デストラクタ

	void Update();
	void Render();

	void keyMove();	//キーボード操作
	void setRect();	//切り出し範囲を変える
	void gravity();	//重力を反映させる
};
