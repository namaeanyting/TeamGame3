#include "DxLib.h"
#include "Scene.h"
#include "Result.h"

SceneResult::SceneResult() {}
SceneResult::~SceneResult() {}

//初期化
void SceneResult::Init()
{
	//画像読み込み
	for (int i = 0; i < RESULT_IMEG_MAX; i++)
	{
		imgHandl[i] = LoadGraph(RESULT_IMAGE_PATH[i]);
	}

	//BGM
	Sound::BGM::PlayButton(BGM_RESULT);
	Sound::BGM::Volume(BGM_RESULT, 50);

	//通常処理へ移動
	g_CurrentSceneID = SCENE_ID_LOOP_RESULT;

}

// 通常処理
void SceneResult::Step()
{
	////キー
	//Input::Step();

	//スペースキーを離したら画面移動
	if (Input::IsKeyPush(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_RESULT;
	}
}

// 描画処理
void SceneResult::Draw()
{
	DrawGraph(0, 0, imgHandl[RESULT_BACK], true);
}

// 終了処理
void SceneResult::Fin()
{
	//BGMの削除
	Sound::BGM::StopDelButton(BGM_RESULT);


	//タイトル移動
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}