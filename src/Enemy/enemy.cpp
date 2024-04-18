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
	direction[0]=false;	//左
	direction[1]=false;	//右

	
	
}

//通常処理
void Enemy::Step()
{
	if (isActive) {
		if (isLeft) {
			x += 3;	//右に行く
			if (x > (1280 / 2) - ENEMY_SIZE_X) {
				x = (1280 / 2) - ENEMY_SIZE_X;
				isActive = false;
			}
		}
		else {
			x -= 3;	//左に行く
			if (x < (1280 / 2) + ENEMY_SIZE_X) {
				x = (1280 / 2) + ENEMY_SIZE_X;
				isActive = false;
			}
		}
	}
}

//描画
void Enemy::Draw()
{
	if (isActive) {
		DrawRotaGraph(x, y, 1.0f, 0.0f, imgHandl[ENEMY_ENEMY1], true);
	}
	//デバッグ用
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "flame:%d", flameCount);
}

//終了処理
void Enemy::Fin()
{

}

