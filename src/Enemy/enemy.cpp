#include "DxLib.h"
#include "enemy.h"

void Enemy::Init()
{
	//�摜�̓ǂ݂���
	for (int i = 0; i < ENEMY_IMEG_MAX; i++) {
		imgHandl[i] = LoadGraph(ENEMY_IMAGE_PATH[i]);
	}
	//�i�s�����̏�����
	direction[0]=false;	//��
	direction[1]=false;	//�E

	//������i�s�@DO
	posX = 0;
	posY = 360;

	HP = ENEMY_HP_MAX;	
	//�`�悷�邩�ۂ�
	isDraw = true;
}

//�ʏ폈��
void Enemy::Step()
{
	if (posX < (1280 /2)-ENEMY_SIZE_X) {
		direction[0] = true;	//�����痈��
		posX+=3;				//�i�s
	}

	//Hp��0�ɂȂ�����`�����߂�
	if (HP == 0) {
		isDraw = false;
	}
}

//�`��
void Enemy::Draw()
{
	if (isDraw) {
		DrawRotaGraph(posX, posY, 1.0f, 0.0f, imgHandl[ENEMY_ENEMY], true);
	}
	//�f�o�b�O�p
	DrawFormatString(0, 0, GetColor(255, 255, 255), "enemyPosX:%d", posX);
}

//�I������
void Enemy::Fin()
{

}