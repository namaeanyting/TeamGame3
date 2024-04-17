#include "DxLib.h"
#include "enemy.h"

void Enemy::Init()
{
	//�摜�̓ǂ݂���
	for (int i = 0; i < ENEMY_IMEG_MAX; i++) {
		imgHandl[i] = LoadGraph(ENEMY_IMAGE_PATH[i]);
	}

	//������i�s�@DO
	posX = 0;
	posY = 360;
	HP = ENEMY_HP_MAX;
}

//�ʏ폈��
void Enemy::Step()
{
	if (posX < 520) {
		posX+=3;
	}
}

//�`��
void Enemy::Draw()
{
	DrawRotaGraph(posX, posY, 1.0f, 0.0f, imgHandl[ENEMY_ENEMY], true);

	//�f�o�b�O�p
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", posX);
}

//�I������
void Enemy::Fin()
{

}