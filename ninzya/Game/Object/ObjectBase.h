//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   ObjectBase.h
//!
//! @brief  オブジェクト関連のヘッダーファイル
//!
//! @date   日付		
//!
//! @author 制作者名	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once

#include "..//GameMain.h"
#include <string>
#include <sstream>

class ObjectBase
{
private:

protected:
	Texture* m_handle;	//グラフィックハンドル 
	int		 m_grp_x;	//元画像のｘ座標 
	int		 m_grp_y;	//元画像のｙ座標 
	int		 m_grp_w;	//元画像の幅 
	int		 m_grp_h;	//元画像の高さ 
	float	 m_pos_x;	//座標x 
	float	 m_pos_y;	//座標y 
	float	 m_spd_x;	//速度x 
	float	 m_spd_y;	//速度y 
	int		 m_state;	//状態		
	RECT	 m_rect;	//切り出し
	
public:
	ObjectBase();
	~ObjectBase();

	virtual void Update();	//更新
	virtual void Render();	//描画

	void DrawObject(Texture* tex, float pos_x, float pos_y, RECT rect);	//表示

	//設定
	void SetPos(float x, float y);	//座標X,Yを同時に設定
	void SetPosX(float x);			//座標X
	void SetPosY(float y);			//座標Y
	void SetSpdX(float x);			//速度X
	void SetSpdY(float y);			//速度Y
	void SetState(int state);		//状態

	//取得
	float GetPosX();		//X座標
	float GetPosY();		//Y座標
	float GetSpdX();		//速度X
	float GetSpdY();		//速度Y
	int   GetGrpH();		//高さ
	int	  GetGrpW();		//幅
	int	  GetState();		//状態  
	
	//移動
	void keyMove();		//キーボード操作
	void mouseMove();	//マウス

};
