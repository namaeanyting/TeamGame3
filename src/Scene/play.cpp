#include "DxLib.h"
#include "Scene.h"
#include "Play.h"
#include "../Input/Input.h"
#include "../Collision/Collision.h"

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

	//あたった時のカウント初期化
	HitCount = 0;

	//BGM
	//sound.bgm[BGM_PLAY] = LoadSoundMem("data/Sound/play.mp3");
	////音量調整
	//ChangeVolumeSoundMem(255 * 50 / 100, sound.bgm[BGM_PLAY]);
	//PlaySoundMem(sound.bgm[BGM_PLAY], DX_PLAYTYPE_LOOP, true);
	////SE
	//sound.InitPlay();

	//各クラス初期化
	player.Init();
	for (int i = 0; i < ENEMY_KAIND; i++)
	{
		enemy[i].Init();
	}
	flameCount = 0;

	//左から進行
	enemy[0].x = 0;
	enemy[0].y = 360;
	enemy[0].isLeft = true;
	enemy[0].isActive = true;

	//右から進行
	enemy[1].x = 1280;
	enemy[1].y = 360;
	enemy[1].isLeft = false;
	enemy[1].isActive = true;

	//右から進行
	enemy[2].x = 1280;
	enemy[2].y = 360;
	enemy[2].isLeft = false;
	enemy[2].isActive = false;
	//通常処理へ移動
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}
// タイトル通常処理
void ScenePlay::Step()
{
	flameCount++;

	for (int i = 0; i < 4; i++) {
		player.direction[i] = false;
	}

	//キー
	Input::Step();

	//操作
	player.Operation();

	//敵進行
	for (int i = 0; i < ENEMY_KAIND; i++)
	{
		enemy[i].Step();
	}

	if (flameCount >= 60) {
		for (int i = 0; i < ENEMY_KAIND; i++)
		{
			if (!enemy[i].isActive) {
				if (enemy[i].isLeft) {
					enemy[i].x = 0;
					enemy[i].y = 360;
				}
				else {
					enemy[i].x = 1280;
					enemy[i].y = 360;
				}

				enemy[i].isActive = true;
				flameCount = 0;
			}
		}
	}

	////DO
	//for (int i = 0; i < ENEMY_KAIND; i++)
	//{
	//	if (enemy[i].HP < 0) {
	//		enemy[i].HP = 0;
	//	}
	//}
	if (player.HP < 0) {
		player.HP = 0;
	}
	//当たり判定
	PlyerToEnemyHit();

	
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
	//DrawGraph(0, 0, imgHandl[PLAY_BACK], true);

	//プレイヤー描画
	player.Draw();

	//敵描画
	for (int i = 0; i < ENEMY_KAIND; i++)
	{
		enemy[i].Draw();
	}

	//デバッグ用
	DrawFormatString(0, 0, GetColor(255, 255, 255), "flame:%d", flameCount);

	/*DrawFormatString(0, 40, GetColor(255, 255, 255), "playerHP:%d",player.HP);
	for (int i = 0; i < ENEMY_KAIND; i++)
	{
		DrawFormatString(0, 80, GetColor(255, 255, 255), "enemyHP:%d", enemy[i].HP);
	}
	if (player.direction[1]) {
		DrawBox(player.GetPosX(), player.GetPosY(),
			player.GetPosX() + PLAYER_SIZE_X, player.GetPosY() + PLAYER_SIZE_Y, GetColor(255, 255, 255), true);
	}
	if (player.direction[3]) {
		DrawBox(player.GetPosX(), player.GetPosY(),
			player.GetPosX() - PLAYER_SIZE_X, player.GetPosY() + PLAYER_SIZE_Y, GetColor(255, 255, 255), true);
	}*/
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

//プレイヤーと敵当たり判定
void ScenePlay::PlyerToEnemyHit()
{
	for (int i = 0; i < ENEMY_KAIND; i++)
	{
		////左を向いている
		//if (player.direction[3]) {

		//	if (IsHitRect(player.GetPosX(), player.GetPosY(), PLAYER_SIZE_X, PLAYER_SIZE_Y,
		//		enemy[i].GetPosX(), enemy[i].GetPosY(), ENEMY_SIZE_X, ENEMY_SIZE_Y))
		//	{
		//		enemy[i].HP--;
		//		
		//	}
		//}
	}
	//for (int i = 0; i < ENEMY_KAIND; i++)
	//{
	//	if (IsHitRect(player.GetPosX(), player.GetPosY(), PLAYER_SIZE_X, PLAYER_SIZE_Y,
	//		enemy[i].GetPosX(), enemy[i].GetPosY(), ENEMY_SIZE_X, ENEMY_SIZE_Y))
	//	{
	//		//攻撃されてから時間をカウント
	//		HitCount++;

	//		if (player.direction[3] && enemy[i].direction[0]) {
	//			enemy[i].HP--;
	//		}
	//		else if (HitCount > 200) {
	//			player.HP--;		//100の時だけダメージを与える
	//			HitCount = 0;		//ダメージを与えたらまた0に戻し、カウントを頭からにする
	//		}
	//		//デバッグ用
	//		DrawFormatString(0, 20, GetColor(255, 255, 255), "hit");
	//		DrawFormatString(60, 20, GetColor(255, 255, 255), "カウント:%d",HitCount);
	//	}
	//}



}

