#include "DxLib.h"
#include "Scene.h"
#include "Play.h"
#include "../Input/Input.h"
#include "../Collision/Collision.h"

//タイトルの初期化
void ScenePlay::Init()
{
	//画像読み込み
	for (int i = 0; i < PLAY_IMEG_MAX; i++)
	{
		imgHandl[i] = LoadGraph(PLAY_IMAGE_PATH[i]);
	}

	//あたった時のカウント初期化
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		HitCount[i][0] = 0;
		HitCount[i][1] = 0;
	}

	//各クラス初期化
	player.Init();
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].Init();
		//進行方向の初期化
		enemy[i].HP = ENEMY_HP_MAX;
	}
	flameCount = 0;

	//ランダムに生成
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		EnemyGeneration(i);
	}
	
	//無敵ゲージバー画像読み込み
	Invincible_Bar_Hndl = LoadGraph(INVINCIBLE_BAR);
	//無敵ゲージ画像読み込み
	Invincible_Gauge_Hndl = LoadGraph(INVINCIBLE_GAUGE);
	//無敵フラグ
	Invincible = false;
	//無敵時間
	Invincible_Time = 5;
	//きつねを倒したカウント
	Fox_Count = 0;

	//通常処理へ移動
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}
// タイトル通常処理
void ScenePlay::Step()
{
	flameCount++;
	//毎フレーム攻撃ボタンをfalseに
	player.BottunInit();

	//キー
	Input::Step();
	//操作
	player.Operation();

	//敵進行
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].Step();
	}

	//敵のリスポーン
	Respawn();

	//当たり判定
	PlyerToEnemyHit();
	player.Step();
	player.MoveImage();
	
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
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].Draw();
	}

	//無敵関連描画
	DrawInvincibleGauge();

	//デバッグ用
	DrawFormatString(0, 0, GetColor(255, 255, 255), "flame:%d", flameCount);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "playerHP:%d",player.HP);
	for (int i = 0; i < ENEMY_NUM; i++){
		DrawFormatString(0, 80+i*20, GetColor(255, 255, 255), "enemyHP:%d", enemy[i].HP);
	}
	//座標
	DrawFormatString(0, 160, GetColor(255, 255, 255), "敵0のx:%d", enemy[0].x);
	DrawFormatString(0, 180, GetColor(255, 255, 255), "敵1のx:%d", enemy[1].x);
	DrawFormatString(0, 200, GetColor(255, 255, 255), "敵2のx:%d", enemy[2].x);
	DrawFormatString(0, 220, GetColor(255, 255, 255), "y:%d", player.GetPosY());
	DrawFormatString(0, 40, GetColor(255, 255, 255), "カウント:%d", HitCount[0][0]);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "カウント:%d", HitCount[0][1]);

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
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//左--------------------------------------------------------------
		if (IsHitRect(enemy[i].x, enemy[i].y, ENEMY_SIZE_X, ENEMY_SIZE_Y,
			(WINDOW_WIDTH/2) - (PLAYER_SIZE_X/2), (WINDOW_HEIGHT/2)- (ENEMY_SIZE_Y/2), PLAYER_SIZE_X, PLAYER_SIZE_Y))
		{
			//攻撃されてから時間をカウント
			HitCount[i][0]++;

			//プレイヤーが左向いて攻撃 && 敵左から進行
			if (player.attacDirection[3] && enemy[i].isLeft) {
				enemy[i].HP--;
				player.attckCount++;
				
				if (enemy[i].HP == 0) {
					enemy[i].isActive = false;//死亡グラフを折る
				}
			}
			else if (HitCount[i][0] > ATTACK_WAITE_TIME) {
				player.HP--;			//200の時だけダメージを与える
				HitCount[i][0] = 0;		//ダメージを与えたらまた0に戻し、カウントを頭からにする
			}
			DrawFormatString(0, 420, GetColor(255, 255, 255), "左hit");

		}
		//当たってないなら
		else {
			HitCount[i][0] = 0;
		}

		//右--------------------------------------------------------------
		if (IsHitRect(enemy[i].x, enemy[i].y, ENEMY_SIZE_X, ENEMY_SIZE_Y,
			(WINDOW_WIDTH / 2) + (PLAYER_SIZE_X / 2), (WINDOW_HEIGHT / 2) - (ENEMY_SIZE_Y / 2), PLAYER_SIZE_X, PLAYER_SIZE_Y))
		{
			//攻撃されてから時間をカウント
			HitCount[i][1]++;
			//プレイヤーが右向いてる && 右から進行
			if (player.attacDirection[1] && !enemy[i].isLeft) {
				enemy[i].HP--;
				player.attckCount++;

				if (enemy[i].HP == 0) {
					enemy[i].isActive = false;//死亡グラフを折る
				}
			}
			else if (HitCount[i][1] > ATTACK_WAITE_TIME) {
				player.HP--;			//200の時だけダメージを与える
				HitCount[i][1] = 0;		//ダメージを与えたらまた0に戻し、カウントを頭からにする
			}

			////デバッグ用
			DrawFormatString(0, 440, GetColor(255, 255, 255), "右hit");
			//DrawFormatString(0, 40, GetColor(255, 255, 255), "カウント:%d", HitCount[0]);
			//DrawFormatString(0, 60, GetColor(255, 255, 255), "カウント:%d", HitCount[1]);
		}
		//当たってないなら
		else {
			HitCount[i][1] = 0;
		}
	}
}

//ランダム生成
void ScenePlay::EnemyGeneration(int enemyNum) {
	if (GetRand(1) == 0) {
		enemy[enemyNum].x = 0;
		enemy[enemyNum].y = 360;
		enemy[enemyNum].isLeft = true;
	}
	else {
		enemy[enemyNum].x = 1280;
		enemy[enemyNum].y = 360;
		enemy[enemyNum].isLeft = false;
	}
}

//敵のよみがえり設定
void ScenePlay::Respawn()
{
	if (flameCount >= 60) {
		for (int i = 0; i < ENEMY_NUM; i++)
		{
			if (!enemy[i].isActive) {

				EnemyGeneration(i);
				enemy[i].isActive = true;
				flameCount = 0;
			}
		}
	}
}

//無敵ゲージ描画
void ScenePlay::DrawInvincibleGauge()
{
	// 無敵ゲージバー描画
		DrawGraph(100, 100, Invincible_Bar_Hndl, true);

	//無敵ゲージを増やす描画
	if (Invincible == false)
	{
		DrawRectGraph(100, 100, 0, 0, 10 * Fox_Count, 100, Invincible_Gauge_Hndl, true, false);
	}
	//無敵だった場合、ゲージを減らす描画
	else
	{
		DrawRectGraph(100, 100, 0, 0, 20 * Invincible_Time, 100, Invincible_Gauge_Hndl, true, false);
	}
}