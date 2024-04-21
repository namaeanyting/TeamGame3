#include "DxLib.h"
#include "enemy.h"

void Enemy::Init()
{
	//�摜�̓ǂ݂���
	for (int i = 0; i < ENEMY_IMEG_MAX; i++) {
		imgHandl[i] = LoadGraph(ENEMY_IMAGE_PATH[i]);
	}
	
	flameCount = 0;
	phese = 0;

	////�i�s�����̏�����
	//HP = ENEMY_HP_MAX;
}

//�ʏ폈��
void Enemy::Step()
{
	//�����Ă���Ȃ�i�s
	if (isActive) {
		KnockBack();
		if (HP>3&&isLeft) {
			x += 3;	//�E�ɍs��
			if (x > (1280 / 2) - ENEMY_SIZE_X) {
				x = (1280 / 2) - ENEMY_SIZE_X;
			}
		}
		else if (HP > 3 && !isLeft) {
			x -= 3;	//���ɍs��
			if (x < (1280 / 2) + ENEMY_SIZE_X) {
				x = (1280 / 2) + ENEMY_SIZE_X;
			}
		}
	}
	//����ł���Ȃ畜��
	else {
		HP = ENEMY_HP_MAX;//HP���ď�����������
	}
	//HP����
	if (HP < 0) {
		HP = 0;
	}
}

//�`��
void Enemy::Draw()
{
	if (isActive) {
		DrawRotaGraph(x, y, 1.0f, 0.0f, imgHandl[ENEMY_ENEMY1], true);
	}
}

//�m�b�N�o�b�N����
void Enemy::KnockBack()
{
	//HP��������ꂽ����ɉ�����
	if (HP == 3) {
		switch (phese)
		{
		case 0:
			//���܂ŉ�����܂�
			if (isLeft) {
				x -= 8;
				//���̃t�F�[�Y�֐i
				if (x == 324) {
					phese = 1;
				}
			}
			else {
				x += 8;
				if (x == 956) {
					phese = 1;
				}
			}
			
			break;
		case 1:
			if (isLeft) {
				x += 3;	//�E�ɍs��
				if (x > (1280 / 2) - ENEMY_SIZE_X) {
					x = (1280 / 2) - ENEMY_SIZE_X;
					phese = 0;
				}
			}
			else {
				x -= 3;	//���ɍs��
				if (x < (1280 / 2) + ENEMY_SIZE_X) {
					x = (1280 / 2) + ENEMY_SIZE_X;
					phese = 0;

				}
			}
			break;
		default:
			break;
		}
	}
}

/*
* ����
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

	//�ꏊ�̐���
void Enemy::PosXControl(bool isLeft)
{
	if (isLeft) {
		if (x > (1280 / 2) - ENEMY_SIZE_X) {
			x = (1280 / 2) - ENEMY_SIZE_X;
		}
	}
	else {
		if (x < (1280 / 2) + ENEMY_SIZE_X) {
			x = (1280 / 2) + ENEMY_SIZE_X;
		}
	}
}
	


*/
