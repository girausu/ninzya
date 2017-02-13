	//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
	//! @file   GameMain.cpp
	//!
	//! @brief  ゲーム関連のソースファイル
	//!
	//! @date   日付		
	//!
	//! @author 制作者名	
	//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#define _GAMEMAIN_
#include "GameMain.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Scene\GamePlay.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;

// プロトタイプ宣言 ====================================================

// グローバル変数の定義 ====================================================
GameBase* base;

// 関数の定義 ==============================================================

//----------------------------------------------------------------------
//! @brief ゲームの初期化処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void InitializeGame(void)
{
	//マップの読み込み
	importDate("Resources\\Map\\simpleStage.csv");

	//シーンの初期化
	base = new GamePlay();
}

//----------------------------------------------------------------------
//! @brief ゲームの更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void UpdateGame(void)
{
	base->Update();
}

//----------------------------------------------------------------------
//! @brief ゲームの描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void RenderGame(void)
{
	base->Render();
}

//----------------------------------------------------------------------
//! @brief ゲームの終了処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void FinalizeGame(void)
{
	delete base;
}

//----------------------------------------------------------------------
//! @brief 切り出して表示
//!
//! @param[in] ハンドル, 切り出した画像
//!
//! @return なし
//----------------------------------------------------------------------
void DrawObject(Texture* tex, float pos_x, float pos_y, RECT rect)
{
	//ハンドル 座標XY 切り出す範囲, 色, ラジアン値, 回転の中心座標, 拡大倍率
	g_spriteBatch->Draw(tex->m_pTexture, Vector2(pos_x, pos_y),
		&rect, Colors::White, 0.0f, Vector2(0, 0), Vector2(1, 1));
}

//----------------------------------------------------------------------
//! @brief ファイルの呼び出し
//!
//! @param[in]	なし	
//!
//! @return なし
//----------------------------------------------------------------------
void importDate(string filename)
{
	ifstream ifs(filename);
	string str;
	int i;

	// 読めないとき
	if (!ifs)
	{
		for (i = 0; i < MAX_TIP; i++)
		{
			g_map[i / 20][i % 20] = 4;
		}
		return;
	}
	i = 0;
	while (getline(ifs, str))
	{
		string token;
		istringstream stream(str);

		// 1行のうち、文字列よコンマを分割する
		while (getline(stream, token, ','))
		{
			// すべては文字列として読み込まれるため
			// 数値は変換が必要
			g_map[i / 20][i % 20] = atoi(token.c_str());
			i++;
		}
		//g_map[i / 20][i % 20] = atoi(token. c_str());
	}
}


