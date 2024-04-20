#pragma once
#define ENEMY_MAX_NUM	(5)						//�e�̍ő吔�i�n���h���̐��j
const int WINDOW_H = 1280;
// �G�̉摜�T�C�Y
const int ENEMY_SIZE_Y = 200;
const int ENEMY_SIZE_X = 140;
const int ENEMY_NUM = 2;
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
	"data/play/1.png",			//
	"data/play/3.png",			//
	"data/play/4.png",			//
};

class Enemy
{
private:
	int imgHandl[ENEMY_IMEG_MAX];
	int phese;//�m�b�N�o�b�N�̏�ʐi�s�p
public:
	int HP;
	int x, y;
	bool isActive;
	bool isLeft;				//true=�����痈��

	int flameCount;
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

	//�m�b�N�o�b�N����
	void KnockBack();
	
};

