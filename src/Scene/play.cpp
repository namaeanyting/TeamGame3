#include "DxLib.h"
#include "Scene.h"
#include "Play.h"
#include "../Input/Input.h"

ScenePlay::ScenePlay(){}
ScenePlay::~ScenePlay() {}

//タイトルの初期化
void ScenePlay::Init()
{
	//画像読み込み
	for (int i = 0; i < PLAY_IMEG_MAX; i++)
	{
		imgHandl[i] = LoadGraph(PLAY_IMAGE_PATH[i]);
	}

	//キーの初期化
	Input::Init();

	//BGM
	//sound.bgm[BGM_PLAY] = LoadSoundMem("data/Sound/play.mp3");
	////音量調整
	//ChangeVolumeSoundMem(255 * 50 / 100, sound.bgm[BGM_PLAY]);
	//PlaySoundMem(sound.bgm[BGM_PLAY], DX_PLAYTYPE_LOOP, true);

	////SE
	//sound.InitPlay();


	//スコア初期化
	/*score.Init();
	score.Load();*/


	//通常処理へ移動
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
	//playの中の処理移動
	//g_CurrentScenePlayID = ID_PLAY_REDITION;
}
// タイトル通常処理
void ScenePlay::Step()
{
	//キー
	Input::Step();
	//スペースキーを押したら画面移動
	if (Input::IsKeyPush(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}
}

// タイトル描画処理
void ScenePlay::Draw()
{
	//背景画像
	DrawGraph(0, 0, imgHandl[PLAY_BACK], true);

	//score.Draw();

	//デバッグ用
	//DrawFormatString(0, 0, GetColor(255, 0, 0), "上　%d", BG_PosY[0]);
	//DrawFormatString(0, 20, GetColor(255, 0, 0), "下　%d", BG_PosY[1]);

}

// タイトル終了処理
void ScenePlay::Fin()
{
	////BGMの削除
	//StopSoundMem(sound.bgm[BGM_PLAY]);
	//DeleteSoundMem(sound.bgm[BGM_PLAY]);
	////SEの削除
	//for (int i = 0; i < ALL_SOUND; i++) {
	//	StopSoundMem(sound.se[i]);
	//	DeleteSoundMem(sound.se[i]);
	//}

	// プレイシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}