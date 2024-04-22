#include "DxLib.h"
#include "enemy2.h"

void Enemy2::Init()
{
	phese = 0;
	LoadDivGraph(ENEMY_SUIT, 3, 3, 1, 140, 200, img_suit);
	imgNum = 0;	//�摜�̓Y�����ݒ�

	////�i�s�����̏�����
	//HP = ENEMY_HP_MAX;
}

//�ʏ폈��
void Enemy2::Step()
{
	//�����Ă���Ȃ�i�s
	if (isActive) {
		KnockBack();
		if (HP > 3 && isLeft) {
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
		HP = ENEMY2_HP_MAX;//HP���ď���
	}

	//HP����
	if (HP < 0) {
		HP = 0;
	}
	if (x < 0) {
		isActive = false;
	}
}

//�`��
void Enemy2::Draw()
{
	if (isActive) {
		//���ɐi�s
		if (isLeft) {
			DrawRotaGraph(x, y, 1.0f, 0.0f, img_suit[imgNum], true, true);
		}
		//�E�ɐN�U
		else {
			DrawRotaGraph(x, y, 1.0f, 0.0f, img_suit[imgNum], true, false);
		}
	}
}

//�m�b�N�o�b�N����
void Enemy2::KnockBack()
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

//�����_������
void Enemy2::EnemyGeneration() {
	if (GetRand(1) == 0) {
		x = 0;
		y = 360;
		isLeft = true;
	}
	else {
		x = 1280;
		y = 360;
		isLeft = false;
	}
}
