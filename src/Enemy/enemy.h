#pragma once
#define ENEMY_MAX_NUM	(5)						//�e�̍ő吔�i�n���h���̐��j

// �G�̉摜�T�C�Y
const int ENEMY_SIZE_Y = 200;
const int ENEMY_SIZE_X = 140;
const int ENEMY_KAIND = 3;
//HP�̍ő�l
const int ENEMY_HP_MAX = 6;

//�G�̏o����
const int ENEMY_MAX = 6;

//�摜���g���Ƃ��̖��O
enum ENEMY_IMAGE
{
	ENEMY_ENEMY1,		//�G�̎p
	ENEMY_ENEMY2,		//�G�̎p
	ENEMY_ENEMY3,		//�G�̎p

	ENEMY_IMEG_MAX,		//�摜�̍ő喇��
};

//�摜�̃p�X
const char ENEMY_IMAGE_PATH[ENEMY_IMEG_MAX][255] =
{
	"data/play/1.png",			//�^�C�g���w�i�摜
	"data/play/3.png",			//�^�C�g���w�i�摜
	"data/play/4.png",			//�^�C�g���w�i�摜
};
//struct EnemyInfo
//{
//	int x, y;
//	int HP;
//	bool direction[2];			//�G�������Ă������
//	bool isDraw;				//HP���O�ɂȂ�����`�����߂�
//	int imgHandl[ENEMY_IMEG_MAX];
//
//};

class Enemy
{
private:
	//EnemyInfo enemyInfo[ENEMY_MAX_NUM] = { 0 };
	int x, y;
	int HP;
	bool direction[2];			//�G�������Ă������
	bool isDraw;				//HP���O�ɂȂ�����`�����߂�
	int imgHandl[ENEMY_IMEG_MAX];
public:
	//������
	void Init();

	//�ʏ폈��
	void Step();

	//�ړ�
	void Move();
	//�`��
	void Draw();

	//�I������
	void Fin();
	
	//���W�擾
	//int GetPosX(int num) { return enemyInfo[num].x; }
	//int GetPosY(int num) { return enemyInfo[num].y; }

};
