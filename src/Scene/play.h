#pragma once
#include "../Player/player.h"
#include "../Enemy/enemy.h"

//画像を使うときの名前
enum PLAY_IMAGE
{
	PLAY_BACK,		//タイトルの背景

	PLAY_IMEG_MAX,		//画像の枚数
};

//画像のパス
const char PLAY_IMAGE_PATH[PLAY_IMEG_MAX][255] =
{
	"data/play/back.png",			//タイトル背景画像
};

#define INVINCIBLE_BAR		"data/play/bar.png"		//無敵ゲージバー
#define INVINCIBLE_GAUGE	"data/play/ゲージ.png"	//無敵ゲージ

class ScenePlay
{
private:
	int imgHandl[PLAY_IMEG_MAX];	//画像ハンドル
	int HitCount;					//フレームカウント

	int Invincible_Bar_Hndl;				//無敵ゲージバー画像ハンドル
	int Invincible_Gauge_Hndl;				//無敵ゲージ画像ハンドル

	bool Invincible;				//無敵フラグ
	int Invincible_Time;			//無敵時間変数
	int Fox_Count;					//きつねを倒した時のカウント
	
public:
	ScenePlay();
	~ScenePlay();

	Player player;
	Enemy enemy[ENEMY_KAIND];

	//初期化
	void Init();

	//通常処理
	void Step();

	//描画
	void Draw();

	//終了処理
	void Fin();
	//プレイヤーと敵当たり判定
	void PlyerToEnemyHit();
	
};