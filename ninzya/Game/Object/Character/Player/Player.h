//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   プレイヤーのヘッダー
//!
//! @date   2017/02/07~
//!
//! @author sugiura	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once

#include "..//..//ObjectBase.h"
#include "..//..//Stage//StageBase.h"

class Player : public ObjectBase
{
private:
	float m_gravity; //重力
	bool  m_jump;	 //ジャンプしているか	t = している
	int   m_jumpCnt; //ジャンプしてからの時間のカウント

public:
	Player();	//コンストラクタ
	~Player();	//デストラクタ

	void Update();
	void Render();

	void keyMove();	//キーボード操作
	void setRect();	//切り出し範囲を変える
	void gravity();	//重力を反映させる

	bool collisionStage(StageBase* stage);	//あたり判定
	void setJumpState(bool tf);				//ジャンプ状態の切り替え
};
