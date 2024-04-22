#include "DxLib.h"
#include "Scene.h"
#include "Play.h"
#include "../Input/Input.h"
#include "../Collision/Collision.h"

//タイトルの初期化
void ScenePlay::Init()
{	
	flameCount = 0;

	//画像読み込み
	for (int i = 0; i < PLAY_IMEG_MAX; i++)
	{
		imgHandl[i] = LoadGraph(PLAY_IMAGE_PATH[i]);
	}

	KnifeHndl = LoadGraph(KNIFE_PATH);

	Knife_x = -50;
	Knife_y = 300;
	Knife_Count = 0.0f;
	knife = false;

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
		enemy[i].HP = ENEMY_HP_MAX;
		enemy[i].EnemyGeneration();//ランダムに生成

	}
	for (int i = 0; i < ENEMY_NUM2; i++)
	{
		enemy2[i].Init();
		enemy2[i].HP = ENEMY_HP_MAX;
		enemy2[i].EnemyGeneration();
	}
	
	//BGM
	Sound::BGM::PlayButton(BGM_PLAY);
	Sound::BGM::Volume(BGM_PLAY, 50);

	
	//無敵ゲージバー画像読み込み
	Invincible_Bar_Hndl = LoadGraph(INVINCIBLE_BAR);
	//無敵ゲージ画像読み込み
	Invincible_Gauge_Hndl = LoadGraph(INVINCIBLE_GAUGE);
	//無敵フラグ
	Invincible = false;
	//無敵時間
	Invincible_Time = 5.0f;
	//きつねを倒したカウント
	Fox_Count = 0;

	//通常処理へ移動
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}
// タイトル通常処理
void ScenePlay::Step()
{
	flameCount++;
	flameCountEne2++;

	//毎フレーム攻撃ボタンをfalseに
	player.BottunInit();

	////キー
	//Input::Step();
	//操作
	player.Operation();

	//敵進行
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].Step();
	}
	for (int i = 0; i < ENEMY_NUM2; i++)
	{
		enemy2[i].Step();
	}
	Knife_Count++;
	if (Knife_Count == 300.0f)
	{
		if (knife == false)
		{
			Knife_x = 1300;
			knife = true;
		}
	}
	
	if (knife == true)
	{
		Knife_x -= 6;
		if (Knife_x < -110)
		{
			knife = false;
			Knife_Count = 0.0f;
		}
	}

	//敵のリスポーン
	Respawn();

	//当たり判定
	PlyerToEnemyHit();
	PlyerToEnemy2Hit();
	player.Step();
	player.MoveImage();
	
	//スペースキーを押したら画面移動
	if (Input::IsKeyPush(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}
	//無敵フラグがtrueの時無敵タイムを減らす
	if (Invincible == true)
	{
		if (flameCount % 50 == 0)
		{
			Invincible_Time -= 1.0f;
			if (Invincible_Time <= 0.0f)
			{
				Invincible = false;
				Fox_Count = 0;
			}
		}
		
	}
}

// タイトル描画処理
void ScenePlay::Draw()
{
	//背景画像
	DrawGraph(0, 0, imgHandl[PLAY_BACK], true);

	//プレイヤー描画
	player.Draw();

	DrawGraph(Knife_x, Knife_y, KnifeHndl, true);

	//敵描画
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].Draw();
	}
	for (int i = 0; i < ENEMY_NUM2; i++)
	{
		enemy2[i].Draw();
	}
	//無敵関連描画
	DrawInvincibleGauge();

	////デバッグ用
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "flame:%d", flameCount);
	//DrawFormatString(0, 20, GetColor(255, 255, 255), "playerHP:%d",player.HP);
	//for (int i = 0; i < ENEMY_NUM; i++){
	//	DrawFormatString(0, 80+i*20, GetColor(255, 255, 255), "enemyHP:%d", enemy[i].HP);
	//}
	////座標
	//DrawFormatString(0, 160, GetColor(255, 255, 255), "敵0のx:%d", enemy[0].x);
	//DrawFormatString(0, 180, GetColor(255, 255, 255), "敵1のx:%d", enemy[1].x);
	//DrawFormatString(0, 200, GetColor(255, 255, 255), "敵2のx:%d", enemy[2].x);
	//DrawFormatString(0, 220, GetColor(255, 255, 255), "y:%d", player.GetPosY());
	//DrawFormatString(0, 40, GetColor(255, 255, 255), "カウント:%d", HitCount[0][0]);
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "カウント:%d", HitCount[0][1]);
	//DrawFormatString(0, 240, GetColor(255, 255, 255), "カウント:%d", Fox_Count);
	//DrawFormatString(0, 260, GetColor(255, 255, 255), "秒:%f", Invincible_Time);
	//DrawFormatString(0, 280, GetColor(255, 255, 255), "ナイフカウント:%f", Knife_Count);
	//DrawBox(player.collisionPosX - 140, player.collisionPosY, player.collisionPosX - 140 + (PLAYER_SIZE_X / 2), player.collisionPosY +( PLAYER_SIZE_Y / 2), GetColor(255, 255, 255), true);
	//DrawBox(player.collisionPosX + 80, player.collisionPosY, player.collisionPosX + 80 +( PLAYER_SIZE_X / 2), player.collisionPosY + (PLAYER_SIZE_Y / 2), GetColor(255, 255, 255), true);

}

// タイトル終了処理
void ScenePlay::Fin()
{
	//BGMの削除
	Sound::BGM::StopDelButton(BGM_TITLE);
	Sound::BGM::StopDelButton(SE_PUNCH);
	Sound::BGM::StopDelButton(SE_MONSTER);
	
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
				player.collisionPosX - 80, player.collisionPosY, PLAYER_SIZE_X / 2, PLAYER_SIZE_Y / 2))
			{
				//攻撃されてから時間をカウント
				HitCount[i][0]++;

				//プレイヤーが左向いて攻撃 && 敵左から進行
				if (player.attacDirection[3] && enemy[i].isLeft) {
					enemy[i].HP--;
					player.attckCount++;
					Sound::SE::PlayButton(SE_PUNCH);
					
					if (enemy[i].HP == 0) {
						/*Fox_Count = 10;*/
						Fox_Count++;
						enemy[i].isActive = false;//死亡グラフを折る
						Sound::SE::PlayButton(SE_MONSTER);
					}
				}
				else if (HitCount[i][0] > ATTACK_WAITE_TIME) {
					if (Invincible == true)
					{
						break;
					}
					else
					{
						player.HP--;			//200の時だけダメージを与える
						HitCount[i][0] = 0;		//ダメージを与えたらまた0に戻し、カウントを頭からにする
					}
					
				}
				if (Fox_Count == 10)
				{
					Invincible = true;
					Invincible_Time = 10.0f;
				}
				//DrawFormatString(0, 420, GetColor(255, 255, 255), "左hit");

			}
			//当たってないなら
			else {
				HitCount[i][0] = 0;
			}
		

		//右--------------------------------------------------------------
			if (IsHitRect(enemy[i].x, enemy[i].y, ENEMY_SIZE_X, ENEMY_SIZE_Y,
				player.collisionPosX + 80, player.collisionPosY, PLAYER_SIZE_X / 2, PLAYER_SIZE_Y / 2))
			{
				//攻撃されてから時間をカウント
				HitCount[i][1]++;
				//プレイヤーが右向いてる && 右から進行
				if (player.attacDirection[1] && !enemy[i].isLeft) {
					enemy[i].HP--;
					player.attckCount++;
					Sound::SE::PlayButton(SE_PUNCH);

					if (enemy[i].HP == 0) {
						//Fox_Count = 10;
						Fox_Count++;
						enemy[i].isActive = false;//死亡グラフを折る
						Sound::SE::PlayButton(SE_MONSTER);

					}
					
				}
				else if (HitCount[i][1] > ATTACK_WAITE_TIME) {
					if (Invincible == true)
					{
						break;
					}
					else
					{
						player.HP--;			//200の時だけダメージを与える
						HitCount[i][1] = 0;		//ダメージを与えたらまた0に戻し、カウントを頭からにする
					}
				}
				if (Fox_Count == 10)
				{
					Invincible = true;
					Invincible_Time = 10.0f;
				}
				////デバッグ用
			//	DrawFormatString(0, 440, GetColor(255, 255, 255), "右hit");
				//DrawFormatString(0, 40, GetColor(255, 255, 255), "カウント:%d", HitCount[0]);
				//DrawFormatString(0, 60, GetColor(255, 255, 255), "カウント:%d", HitCount[1]);
			}
			//当たってないなら
			else {
				HitCount[i][1] = 0;
			}
			
	}

	if (knife == true)
		{
			if (IsHitRect(Knife_x, Knife_y, 35, 35, player.GetPosX() - 70, player.GetPosY() - 100, 140, 100))
			{
				player.HP--;
				knife = false;
				Knife_Count = 0.0f;
			}
		}
	}

	//プレイヤーと敵2当たり判定
void ScenePlay::PlyerToEnemy2Hit()
{
	for (int i = 0; i < ENEMY_NUM2; i++)
	{
		//左--------------------------------------------------------------
		if (IsHitRect(enemy2[i].x, enemy2[i].y, ENEMY_SIZE_X, ENEMY_SIZE_Y,
			(WINDOW_WIDTH / 2) - (PLAYER_SIZE_X / 2), (WINDOW_HEIGHT / 2) - (ENEMY_SIZE_Y / 2), PLAYER_SIZE_X, PLAYER_SIZE_Y))
		{
			//攻撃されてから時間をカウント
			HitCount[i][0]++;

			//プレイヤーが左向いて攻撃 && 敵左から進行
			if (player.attacDirection[3] && enemy2[i].isLeft) {
				enemy2[i].HP--;
				player.attckCount++;
				Sound::SE::PlayButton(SE_PUNCH);

				if (enemy2[i].HP == 0) {
					enemy2[i].isActive = false;//死亡グラフを折る
					Fox_Count++;				//倒した数
					Sound::SE::PlayButton(SE_MONSTER);

				}
			}
			else if (HitCount[i][0] > ATTACK_WAITE_TIME) {
				player.HP--;			//200の時だけダメージを与える
				HitCount[i][0] = 0;		//ダメージを与えたらまた0に戻し、カウントを頭からにする
			}
			//DrawFormatString(0, 420, GetColor(255, 255, 255), "左hit");

		}
		//当たってないなら
		else {
			HitCount[i][0] = 0;
		}

		//右--------------------------------------------------------------
		if (IsHitRect(enemy2[i].x, enemy2[i].y, ENEMY_SIZE_X, ENEMY_SIZE_Y,
			(WINDOW_WIDTH / 2) + (PLAYER_SIZE_X / 2), (WINDOW_HEIGHT / 2) - (ENEMY_SIZE_Y / 2), PLAYER_SIZE_X, PLAYER_SIZE_Y))
		{
			//攻撃されてから時間をカウント
			HitCount[i][1]++;
			//プレイヤーが右向いてる && 右から進行
			if (player.attacDirection[1] && !enemy2[i].isLeft) {
				enemy2[i].HP--;
				player.attckCount++;
				Sound::SE::PlayButton(SE_PUNCH);

				if (enemy2[i].HP == 0) {
					enemy2[i].isActive = false;	//死亡グラフを折る
					Fox_Count++;				//倒した数
					Sound::SE::PlayButton(SE_MONSTER);

				}
			}
			else if (HitCount[i][1] > ATTACK_WAITE_TIME) {
				player.HP--;			//200の時だけダメージを与える
				HitCount[i][1] = 0;		//ダメージを与えたらまた0に戻し、カウントを頭からにする
			}

			////デバッグ用
			//DrawFormatString(0, 440, GetColor(255, 255, 255), "右hit");
			//DrawFormatString(0, 40, GetColor(255, 255, 255), "カウント:%d", HitCount[0]);
			//DrawFormatString(0, 60, GetColor(255, 255, 255), "カウント:%d", HitCount[1]);
		}
		//当たってないなら
		else {
			HitCount[i][1] = 0;
		}
	}
}


//敵のよみがえり設定
void ScenePlay::Respawn()
{
	if (flameCount >= 60) {
		for (int i = 0; i < ENEMY_NUM; i++)
		{
			if (!enemy[i].isActive) {

				enemy[i].EnemyGeneration();
				enemy[i].isActive = true;
				flameCount = 0;
			}
		}
	}

	if (flameCountEne2 >= 80) {
		for (int i = 0; i < ENEMY_NUM2; i++)
		{
			if (!enemy2[i].isActive) {

				enemy2[i].EnemyGeneration();
				enemy2[i].isActive = true;
				flameCountEne2 = 0;
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
		DrawRectGraph(100, 100, 0, 0, 40 * Fox_Count, 100, Invincible_Gauge_Hndl, true, false);
	}
	//無敵だった場合、ゲージを減らす描画
	else
	{
		DrawRectGraph(100, 100, 0, 0, 80 * Invincible_Time, 100, Invincible_Gauge_Hndl, true, false);
	}
}