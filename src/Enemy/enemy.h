#pragma once
#include "../Scene/scene.h"
#define ENEMY_MAX_NUM	(5)						//�e�̍ő吔�i�n���h���̐��j
#define ENEMY_NOMAL "data/enemy/Fox_nomal.png"
#define ENEMY_ZOMB	 "data/enemy/Fox_zomb.png"

const int WINDOW_H = 1280;
const int ENEMY_NUM = 2;

//HP�̍ő�l
const int ENEMY_HP_MAX = 6;

//�G�̏o����
const int ENEMY_MAX = 6;

class Enemy
{
private:
	int phese;					//�m�b�N�o�b�N�̏�ʐi�s�p
	int img_nomal[3];				//�摜�ϐ�
	int imgNum;
	int img_zomb[3];

public:
	int HP;
	int x, y;
	
	bool isActive;
	bool isLeft;				//true=�����痈��
	int flameCount;
	
	void Init();//������
	void Step();//�ʏ폈��
	void Move();//�ړ�
	void Draw();//�`��s
	void Fin();//�I������
	void KnockBack();//�m�b�N�o�b�N����
	void EnemyGeneration();//�����_������
};

