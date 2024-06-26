#include "DxLib.h"
#include "Title.h"
#include "scene.h"
#include "../Input/Input.h"


//タイトルの初期化
void SceneTitle::Init()
{
	//画像読み込み
	for (int i = 0; i < TITLE_IMEG_MAX; i++)
	{
		imgHandl[i] = LoadGraph(TITLE_IMAGE_PATH[i]);
	}

	nameHandl = LoadGraph(TITLE_NAME_PATH);
	

	//BGM
	Sound::BGM::PlayButton(BGM_TITLE);
	Sound::BGM::Volume(BGM_TITLE, 50);


	//通常処理へ移動
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;

}

// タイトル通常処理
void SceneTitle::Step()
{

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
	DrawRotaGraph(650, 100, 1.5f, 0.0f, nameHandl, true);
}

// タイトル終了処理
void SceneTitle::Fin()
{
	//BGMの削除
	Sound::BGM::StopDelButton(BGM_TITLE);

	// プレイシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}