#include "DxLib.h"
#include "Title.h"
#include "scene.h"
#include "../Input/Input.h"

SceneTitle::SceneTitle()
{
	//sound.bgm[BGM_OP] = 0;		//BGMの初期化
}

SceneTitle::~SceneTitle() {}

//タイトルの初期化
void SceneTitle::Init()
{
	//画像読み込み
	for (int i = 0; i < TITLE_IMEG_MAX; i++)
	{
		imgHandl[i] = LoadGraph(TITLE_IMAGE_PATH[i]);
	}
	
	//キーの初期化
	Input::Init();

	//BGM
	//sound.bgm[BGM_OP] = LoadSoundMem("data/Sound/title.mp3");//OP
	//PlaySoundMem(sound.bgm[BGM_OP], DX_PLAYTYPE_LOOP, true);


	//通常処理へ移動
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;

}

// タイトル通常処理
void SceneTitle::Step()
{
	//キー
	Input::Step();

	//スペースキーを押したら画面移動
	if (Input::IsKeyPush(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

// タイトル描画処理
void SceneTitle::Draw()
{
	DrawGraph(0, 0, imgHandl[TITLE_BACK], true);
}

// タイトル終了処理
void SceneTitle::Fin()
{
	//BGMの削除
	//StopSoundMem(sound.bgm[BGM_OP]);
	//DeleteSoundMem(sound.bgm[BGM_OP]);

	// プレイシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}