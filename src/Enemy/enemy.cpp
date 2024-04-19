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
	HP = ENEMY_HP_MAX;
}

//�ʏ폈��
void Enemy::Step()
{
	//�����Ă���Ȃ�i�s
	if (isActive) {
		if (isLeft) {
			x += 3;	//�E�ɍs��
			if (x > (1280 / 2) - ENEMY_SIZE_X) {
				x = (1280 / 2) - ENEMY_SIZE_X;
				//isActive = false;
			}
		}
		else {
			x -= 3;	//���ɍs��
			if (x < (1280 / 2) + ENEMY_SIZE_X) {
				x = (1280 / 2) + ENEMY_SIZE_X;
				//isActive = false;
			}
		}
	}
	//����ł���Ȃ畜��
	else {
		HP = ENEMY_HP_MAX;//HP���ď�����������
	}
}

//�`��
void Enemy::Draw()
{
	if (isActive) {
		DrawRotaGraph(x, y, 1.0f, 0.0f, imgHandl[ENEMY_ENEMY1], true);
	}
}

/*
* 
	//������i�s
	enemy[0].x = 0;
	enemy[0].y = 360;
	enemy[0].isLeft = true;
	enemy[0].isActive = true;

	//�E����i�s
	enemy[1].x = 1280;
	enemy[1].y = 360;
	enemy[1].isLeft = false;
	enemy[1].isActive = true;

	


*/
