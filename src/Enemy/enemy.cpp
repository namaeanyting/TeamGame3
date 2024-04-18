#include "DxLib.h"
#include "enemy.h"

void Enemy::Init()
{
	//�摜�̓ǂ݂���
	for (int i = 0; i < ENEMY_IMEG_MAX; i++) {
		imgHandl[i] = LoadGraph(ENEMY_IMAGE_PATH[i]);
	}

	flameCount = 0;

	//�i�s�����̏�����
	direction[0]=false;	//��
	direction[1]=false;	//�E

	
	
}

//�ʏ폈��
void Enemy::Step()
{
	if (isActive) {
		if (isLeft) {
			x += 3;	//�E�ɍs��
			if (x > (1280 / 2) - ENEMY_SIZE_X) {
				x = (1280 / 2) - ENEMY_SIZE_X;
				isActive = false;
			}
		}
		else {
			x -= 3;	//���ɍs��
			if (x < (1280 / 2) + ENEMY_SIZE_X) {
				x = (1280 / 2) + ENEMY_SIZE_X;
				isActive = false;
			}
		}
	}
}

//�`��
void Enemy::Draw()
{
	if (isActive) {
		DrawRotaGraph(x, y, 1.0f, 0.0f, imgHandl[ENEMY_ENEMY1], true);
	}
	//�f�o�b�O�p
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "flame:%d", flameCount);
}

//�I������
void Enemy::Fin()
{

}

