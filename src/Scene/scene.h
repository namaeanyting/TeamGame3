#pragma once
#include "../Sound/Sound.h"
//ウィンドウの幅・高さ
#define WINDOW_HEIGHT	(720)
#define WINDOW_WIDTH	(1280)
// 敵の画像サイズ
const int ENEMY_SIZE_Y = 200;
const int ENEMY_SIZE_X = 140;
enum SCENE_ID
{
	//タイトルシーンID情報
	SCENE_ID_INIT_TITLE,	//初期化
	SCENE_ID_LOOP_TITLE,	//繰り返し
	SCENE_ID_FIN_TITLE,		//終了

	//プレイシーン情報
	SCENE_ID_INIT_PLAY,
	SCENE_ID_LOOP_PLAY,
	SCENE_ID_FIN_PLAY,

	//終了シーン情報
	SCENE_ID_INIT_RESULT,
	SCENE_ID_LOOP_RESULT,
	SCENE_ID_FIN_RESULT,

};

extern int g_CurrentSceneID;
