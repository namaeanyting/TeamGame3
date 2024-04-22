#pragma once
#include "../Scene/scene.h"
#define ENEMY_MAX_NUM	(5)						//弾の最大数（ハンドルの数）
#define ENEMY_NOMAL "data/enemy/Fox_nomal.png"
#define ENEMY_ZOMB	 "data/enemy/Fox_zomb.png"

const int WINDOW_H = 1280;
const int ENEMY_NUM = 2;

//HPの最大値
const int ENEMY_HP_MAX = 6;

//敵の出現数
const int ENEMY_MAX = 6;

class Enemy
{
private:
	int phese;					//ノックバックの場面進行用
	int img_nomal[3];				//画像変数
	int imgNum;
	int img_zomb[3];

public:
	int HP;
	int x, y;
	
	bool isActive;
	bool isLeft;				//true=左から来る
	int flameCount;
	
	void Init();//初期化
	void Step();//通常処理
	void Move();//移動
	void Draw();//描画s
	void Fin();//終了処理
	void KnockBack();//ノックバック処理
	void EnemyGeneration();//ランダム生成
};

