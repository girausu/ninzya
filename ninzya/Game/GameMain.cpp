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
#include "GamePlay.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;

// 画面解像度
static const int WINDOW_W = 640;
static const int WINDOW_H = 480;

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
	//シーンの初期化
	base = new GamePlay();

	//　画像の読み込み 
	g_grpHandle = new Texture(L"Resources\\Images\\TridentLogo.png");
	g_PongImage = new Texture(L"Resources\\Images\\PongImage.png");
	g_logo		= new Texture(L"Resources\\Images\\TridentLogo.png");

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

