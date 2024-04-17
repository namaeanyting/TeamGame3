#include "DxLib.h"
#include "enemy.h"

void Enemy::Init()
{
	//画像の読みこみ
	for (int i = 0; i < ENEMY_IMEG_MAX; i++) {
		imgHandl[i] = LoadGraph(ENEMY_IMAGE_PATH[i]);
	}

	//左から進行　DO
	posX = 0;
	posY = 360;
	HP = ENEMY_HP_MAX;
}

//通常処理
void Enemy::Step()
{
	if (posX < 520) {
		posX+=3;
	}
}

//描画
void Enemy::Draw()
{
	DrawRotaGraph(posX, posY, 1.0f, 0.0f, imgHandl[ENEMY_ENEMY], true);

	//デバッグ用
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", posX);
}

//終了処理
void Enemy::Fin()
{

}