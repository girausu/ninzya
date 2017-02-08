//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   ステージベースのヘッダー
//!
//! @date   2017/02/08~
//!
//! @author sugiura	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once

#include "..//..//GameMain.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

struct MAX_TIP
{
	const static int MAX_TIP_W = 15;
	const static int MAX_TIP_H = 20;
};

class StageBase 
{
protected:
	int m_mapTip[15][20];

	Texture* m_handle;	
	float m_pos_x;
	float m_pos_y;
	float m_grp_x;
	float m_grp_y;
	float m_grp_h;
	float m_grp_w;
	int m_state;
	RECT m_rect;

public:
	StageBase();
	~StageBase();

};
