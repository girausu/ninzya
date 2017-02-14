//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   敵のヘッダー
//!
//! @date   2017/02/07~
//!
//! @author sugiura	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once // 多重インクルードの防止

#include "..//..//ObjectBase.h"
#include "..//..//Stage//StageBase.h"

class Enemy : public ObjectBase
{
private:

public:
	Enemy();
	~Enemy();

	void Update();
	void Render();

	void move();	//移動
	bool collisionStage(StageBase* stage);	//あたり判定
};