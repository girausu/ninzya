//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   マップのヘッダー
//!
//! @date   2017/02/07~
//!
//! @author sugiura	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once

#include "..//..//GameMain.h"
#include "..//ObjectBase.h"

class Wall : public ObjectBase
{
private:

protected:
	
public:
	Wall();
	~Wall();

	void Update();
	void Render();
};

//継承した変数
//Texture* m_handle;	//グラフィックハンドル 
//int	   m_grp_x;	//元画像のｘ座標 
//int	   m_grp_y;	//元画像のｙ座標 
//int	   m_grp_w;	//元画像の幅 
//int	   m_grp_h;	//元画像の高さ 
//float	 m_pos_x;	//座標x 
//float	 m_pos_y;	//座標y 
//float	 m_spd_x;	//速度x 
//float	 m_spd_y;	//速度y 
//int		 m_state;	//状態		
//RECT	 m_rect;	//切り出し
