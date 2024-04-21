#pragma once
#include "../Scene/scene.h"
#define ENEMY_MAX_NUM	(5)						//弾の最大数（ハンドルの数）
const int WINDOW_H = 1280;
// 敵の画像サイズ
const int ENEMY_SIZE_Y = 200;
const int ENEMY_SIZE_X = 140;
const int ENEMY_NUM = 2;
const int ENEMY_NUM2 = 2;
//HPの最大値
const int ENEMY_HP_MAX = 6;
const int ENEMY2_HP_MAX = 18;

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
	"data/play/1.png",			//
	"data/play/3.png",			//
	"data/play/4.png",			//
};

class Enemy
{
private:
	int imgHandl[ENEMY_IMEG_MAX];
	int phese;					//ノックバックの場面進行用
public:
	int HP;
	int x, y;
	bool isActive;
	bool isLeft;				//true=左から来る

	int flameCount;
	
	void Init();//初期化
	void Step();//通常処理
	void Move();//移動
	void Draw();//描画
	void Fin();//終了処理
	void KnockBack();//ノックバック処理

};

