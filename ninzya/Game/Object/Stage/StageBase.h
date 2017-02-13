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
	const static int MAX_TIP_W = 20;
	const static int MAX_TIP_H = 15;
};

class StageBase 
{
protected:
	//int m_mapTip[15][20];

	Texture* m_handle;	
	float m_pos_x;
	float m_pos_y;
	int m_grp_x;
	int m_grp_y;
	int m_grp_h;
	int m_grp_w;
	int   m_state;
	RECT  m_rect;

public:
	StageBase();
	~StageBase();

	virtual void Update() = 0;
	virtual void Render() = 0;

	void setPosX(float x);	  //X座標の設定
	void setPosY(float y);	  //Y座標の設定
	void setState(int state); //状態の設定

	float getPosX();	//X座標の取得
	float getPosY();	//Y座標の取得
	int	  getGrpW();	//幅の取得
	int   getGrpH();	//高さの取得	
	int   getState();	//状態の取得
};
