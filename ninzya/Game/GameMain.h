//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.h
//!
//! @brief  ゲーム関連のヘッダファイル
//!
//! @date   日付
//!
//! @author 制作者名
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#include <Windows.h>
#include <d3d11.h>
#include <SimpleMath.h>
#include "..\DirectXTK.h"
#include "..\Texture.h"
#include <string>

// 多重インクルードの防止 ==================================================
#pragma once

#ifndef _GAMEMAIN_
#define EXTERN extern
#else
#define EXTERN
#endif

// 定数の定義 ==============================================================
static const int MAX_TIP = 300;

// ゲームタイトル
#define GAME_TITLE "thousand"

// ゲーム画面
#define SCREEN_WIDTH  640    // 幅[pixel]
#define SCREEN_HEIGHT 480    // 高さ[pixel]

// 関数の宣言 ==============================================================

// ゲームの初期化処理
void InitializeGame(void);

// ゲームの更新処理
void UpdateGame(void);

// ゲームの描画処理
void RenderGame(void);

// ゲームの終了処理
void FinalizeGame(void);

//オブジェクトの描画
void DrawObject(Texture* tex, float pos_x, float pos_y, RECT rect);	//表示

//データの読み込み
void importDate(std::string filename);

// グローバル変数の定義 ====================================================
EXTERN int g_key_code;					//キー情報
EXTERN int g_key_old;					//前フレームのキー情報
EXTERN int g_map[15][20];				// マップ

