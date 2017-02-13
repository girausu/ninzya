//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   プレイヤーのソース
//!
//! @date   2017/02/07~
//!
//! @author sugiura	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#include "Player.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Player::Player()
	   :ObjectBase()
{
	//\Resources\Images\Character\Player
	//各変数の設定
	m_handle = new Texture(L"Resources\\Images\\Character\\Player\\moves.png");
	m_grp_w = 72;
	m_grp_h = 112;
	m_pos_x = 640 / 2;
	m_pos_y = 200;
	m_spd_x = 0;
	m_spd_y = 0;
	m_state = 2;
	m_rect = { m_grp_x, m_grp_y, m_grp_w, m_grp_h };

	m_gravity = 0.01f;
	m_time = 0;
}

//----------------------------------------------------------------------
//! @brief デストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Player::~Player()
{

}

//----------------------------------------------------------------------
//! @brief 更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Player::Update()
{
	//スペースキーでプレイヤーの初期化
	if (g_key.Space)
	{

	}

	//速度の初期化
	m_spd_x = 0;
	m_spd_y = 0;

	//キーボードで移動
	keyMove();
	
	//画像の切り抜き範囲を指定
	//setRect();

	//プレイヤーに重力を適用
	gravity();

	//移動
	m_pos_x += m_spd_x;
	m_pos_y += m_spd_y;
}

//----------------------------------------------------------------------
//! @brief 描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Player::Render()
{
	//DrawObject(m_handle, m_pos_x, m_pos_y, m_rect);

	//ハンドル 座標XY 切り出す範囲, 色, ラジアン値, 回転の中心座標, 拡大倍率
	//g_spriteBatch->Draw(m_handle->m_pTexture, Vector2(0, 0), &rect, Colors::White, 0.0f, Vector2(0, 0), Vector2(1, 1));

	if (m_state != 0)
	{
		g_spriteBatch->Draw(m_handle->m_pTexture, Vector2(m_pos_x, m_pos_y), &m_rect,
			Colors::White, 0.0f, Vector2(0, 0), Vector2(0.5f, 0.5f));
	}
}

//--------------------Update(),Render()以外の関数を定義---------------//

//----------------------------------------------------------------------
//! @brief キーボード操作で移動
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Player::keyMove()
{
	//// 移動中の入力
	//if (m_spd_x == 0 && m_spd_y == 0)
	//{	
		if (g_key.Right)
		{
			m_spd_x = 5;
		}
		
		if (g_key.Left)
		{
			m_spd_x = -5;
		}
	
		if (g_key.Up)
		{
			m_spd_y = -10;

			if (m_state == 1)
			{
				m_state = 2;
			}
		}
		
		if (g_key.Down)
		{
			m_spd_y = 5;
		}
	//}
}

//----------------------------------------------------------------------
//! @brief キーボードでの入力に応じて画像の切り抜き範囲を変える
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Player::setRect()
{
	if (g_key.Right)
	{
		//m_grp_x = 0;
		m_grp_y = 390;
	}
	else if (g_key.Left)
	{
		//m_grp_x = 0;
		m_grp_y = 260;
	}
	else if (g_key.Up)
	{
		//m_grp_x = 0;
		m_grp_y = 130;
	}
	else if (g_key.Down)
	{
		//m_grp_x = 0;
		m_grp_y = 0;
	}

	m_rect = { m_grp_x, m_grp_y, m_grp_w + m_grp_x, m_grp_h + m_grp_y};
}

//----------------------------------------------------------------------
//! @brief キーボードでの入力に応じて画像の切り抜き範囲を変える
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Player::gravity()
{
	//ジャンプしている場合
	if (m_state == 2)
	{
		//重力をYに足す
		m_spd_y   += m_gravity;
		m_gravity += 0.05f;
	}	//ジャンプしていない場合重力を初期化   
	else if (m_state == 1)
	{
		m_gravity = 0.01f;
	}
}

//----------------------------------------------------------------------
//! @brief ステージとの当たり判定
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
bool Player::collisionStage(StageBase * stage)
{
	//大きさを半分にしているので 2で割る

	if (stage->getPosX()					<= m_pos_x + m_grp_w / 2	&&	//右側
		stage->getPosX() + stage->getGrpW() >= m_pos_x				&&		//左側
		stage->getPosY()					<= m_pos_y + m_grp_h / 2	&&	//下側
		stage->getPosY() + stage->getGrpH() >= m_pos_y)						//上側
	{
		return true;
	}
	return false;
}

