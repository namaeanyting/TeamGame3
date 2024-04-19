#include "DxLib.h"
#include "enemy.h"

void Enemy::Init()
{
	//画像の読みこみ
	for (int i = 0; i < ENEMY_IMEG_MAX; i++) {
		imgHandl[i] = LoadGraph(ENEMY_IMAGE_PATH[i]);
	}
	
	flameCount = 0;

	//進行方向の初期化
	HP = ENEMY_HP_MAX;
}

//通常処理
void Enemy::Step()
{
	//生きているなら進行
	if (isActive) {
		if (isLeft) {
			x += 3;	//右に行く
			if (x > (1280 / 2) - ENEMY_SIZE_X) {
				x = (1280 / 2) - ENEMY_SIZE_X;
				//isActive = false;
			}
		}
		else {
			x -= 3;	//左に行く
			if (x < (1280 / 2) + ENEMY_SIZE_X) {
				x = (1280 / 2) + ENEMY_SIZE_X;
				//isActive = false;
			}
		}
	}
	//死んでいるなら復活
	else {
		HP = ENEMY_HP_MAX;//HPを再所持させたい
	}
}

//描画
void Enemy::Draw()
{
	if (isActive) {
		DrawRotaGraph(x, y, 1.0f, 0.0f, imgHandl[ENEMY_ENEMY1], true);
	}
}

/*
* 
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

	


*/
