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
	"data/play/2.png",			//タイトル背景画像
};

class ScenePlay
{
private:
	int imgHandl[PLAY_IMEG_MAX];	//画像ハンドル

	
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