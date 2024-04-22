#pragma once
#include "../Scene/scene.h"
#define ENEMY_SUIT	"data/enemy/Fox_sutu.png"

//HP�̍ő�l
const int ENEMY2_HP_MAX = 6;

//�o����
const int ENEMY_NUM2 = 1;

class Enemy2
{
private:
	int phese;					//�m�b�N�o�b�N�̏�ʐi�s�p
	int img_suit[3];
	int imgNum;

public:
	int HP;
	int x, y;
	bool isActive;
	bool isLeft;				//true=�����痈��

	void Init();//������
	void Step();//�ʏ폈��
	void Move();//�ړ�
	void Draw();//�`��
	void Fin();//�I������
	void KnockBack();//�m�b�N�o�b�N����
	void EnemyGeneration();//�����_������

};

