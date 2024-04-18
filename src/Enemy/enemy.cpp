#include "DxLib.h"
#include "enemy.h"

void Enemy::Init()
{
	//画像の読みこみ
	for (int i = 0; i < ENEMY_IMEG_MAX; i++) {
		imgHandl[i] = LoadGraph(ENEMY_IMAGE_PATH[i]);
	}
	//進行方向の初期化
	direction[0]=false;	//左
	direction[1]=false;	//右

	//左から進行　DO
	posX = 0;
	posY = 360;

	HP = ENEMY_HP_MAX;	
	//描画するか否か
	isDraw = true;
}

//通常処理
void Enemy::Step()
{
	if (posX < (1280 /2)-ENEMY_SIZE_X) {
		direction[0] = true;	//左から来る
		posX+=3;				//進行
	}

	//Hpが0になったら描画をやめる
	if (HP == 0) {
		isDraw = false;
	}
}

//描画
void Enemy::Draw()
{
	if (isDraw) {
		DrawRotaGraph(posX, posY, 1.0f, 0.0f, imgHandl[ENEMY_ENEMY], true);
	}
	//デバッグ用
	DrawFormatString(0, 0, GetColor(255, 255, 255), "enemyPosX:%d", posX);
}

//終了処理
void Enemy::Fin()
{

}