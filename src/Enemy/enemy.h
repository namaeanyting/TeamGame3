#pragma once
// �G�̉摜�T�C�Y
const int ENEMY_SIZE_Y = 200;
const int ENEMY_SIZE_X = 140;
const int ENEMY_KAIND = 3;
//HP�̍ő�l
const int ENEMY_HP_MAX = 6;

//�摜���g���Ƃ��̖��O
enum ENEMY_IMAGE
{
	ENEMY_ENEMY,		//�G�̎p

	ENEMY_IMEG_MAX,		//�摜�̍ő喇��
};

//�摜�̃p�X
const char ENEMY_IMAGE_PATH[ENEMY_IMEG_MAX][255] =
{
	"data/play/kari_enemy.png",			//�^�C�g���w�i�摜
};

class Enemy
{
private:
	int imgHandl[ENEMY_IMEG_MAX];
	int posX, posY;
	// int HP;
public:
	//������
	void Init();

	//�ʏ폈��
	void Step();

	//�`��
	void Draw();

	//�I������
	void Fin();
	
	//���W�擾
	int GetPosX() { return posX; }
	int GetPosY() { return posY; }

	//HP
	int HP;
};
