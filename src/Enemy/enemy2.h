#pragma once
#include "../Scene/scene.h"
#define ENEMY_SUIT	"data/enemy/Fox_sutu.png"

//HPの最大値
const int ENEMY2_HP_MAX = 6;

//出現数
const int ENEMY_NUM2 = 1;

class Enemy2
{
private:
	int phese;					//ノックバックの場面進行用
	int img_suit[3];
	int imgNum;

public:
	int HP;
	int x, y;
	bool isActive;
	bool isLeft;				//true=左から来る

	void Init();//初期化
	void Step();//通常処理
	void Move();//移動
	void Draw();//描画
	void Fin();//終了処理
	void KnockBack();//ノックバック処理
	void EnemyGeneration();//ランダム生成

};

