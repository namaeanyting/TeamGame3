#pragma once
#define ENEMY_MAX_NUM	(5)						//弾の最大数（ハンドルの数）

// 敵の画像サイズ
const int ENEMY_SIZE_Y = 200;
const int ENEMY_SIZE_X = 140;
const int ENEMY_KAIND = 3;
//HPの最大値
const int ENEMY_HP_MAX = 6;

//敵の出現数
const int ENEMY_MAX = 6;

//画像を使うときの名前
enum ENEMY_IMAGE
{
	ENEMY_ENEMY1,		//敵の姿
	ENEMY_ENEMY2,		//敵の姿
	ENEMY_ENEMY3,		//敵の姿

	ENEMY_IMEG_MAX,		//画像の最大枚数
};

//画像のパス
const char ENEMY_IMAGE_PATH[ENEMY_IMEG_MAX][255] =
{
	"data/play/1.png",			//タイトル背景画像
	"data/play/3.png",			//タイトル背景画像
	"data/play/4.png",			//タイトル背景画像
};
//struct EnemyInfo
//{
//	int x, y;
//	int HP;
//	bool direction[2];			//敵が向いている方向
//	bool isDraw;				//HPが０になったら描画をやめる
//	int imgHandl[ENEMY_IMEG_MAX];
//
//};

class Enemy
{
private:
	//EnemyInfo enemyInfo[ENEMY_MAX_NUM] = { 0 };
	int x, y;
	int HP;
	bool direction[2];			//敵が向いている方向
	bool isDraw;				//HPが０になったら描画をやめる
	int imgHandl[ENEMY_IMEG_MAX];
public:
	//初期化
	void Init();

	//通常処理
	void Step();

	//移動
	void Move();
	//描画
	void Draw();

	//終了処理
	void Fin();
	
	//座標取得
	//int GetPosX(int num) { return enemyInfo[num].x; }
	//int GetPosY(int num) { return enemyInfo[num].y; }

};
