#pragma once
#include "../Player/player.h"
#include "../Enemy/enemy.h"
#include "../Enemy/enemy2.h"

#define ATTACK_WAITE_TIME  75
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

#define KNIFE_PATH		"data/play/ナイフ.png"

class ScenePlay
{
private:
	int imgHandl[PLAY_IMEG_MAX];	//画像ハンドル
	int HitCount[ENEMY_NUM][2];					//フレームカウント

	int Invincible_Bar_Hndl;				//無敵ゲージバー画像ハンドル
	int Invincible_Gauge_Hndl;				//無敵ゲージ画像ハンドル

	bool Invincible;				//無敵フラグ
	float Invincible_Time;			//無敵時間変数
	int Fox_Count;					//きつねを倒した時のカウント

	int KnifeHndl;
	int Knife_x, Knife_y;
	bool knife;
	float Knife_Count;
	
public:

	Player player;
	Enemy enemy[ENEMY_NUM];//敵の数
	Enemy2 enemy2[ENEMY_NUM2];//HPが多い敵キャラ
	
	int flameCount;
	int flameCountEne2;		//敵２用

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
	void PlyerToEnemy2Hit();

	//敵のよみがえり設定
	void Respawn();
	//HPの制御
	void HPControl();
	//無敵ゲージ描画
	void DrawInvincibleGauge();
};