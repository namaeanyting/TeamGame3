#pragma once
#include "../Scene/scene.h"

#define GRAVITY			(1.5)	
#define YSPEED			(-30)	
#define YSPPED_MAX		(10)

// �v���C���[�̉摜�T�C�Y
const int PLAYER_SIZE_Y = 200; 
const int PLAYER_SIZE_X = 140; 

//HP�̍ő�l
const int PLAYER_HP_MAX = 6;
#define PLAYER_IMG "data/player/player.png"

//�摜���g���Ƃ��̖��O
enum PLAYER_IMAGE
{
	PLAYER_NOMAL,		//�N��
	PLAYER_KICK,		//���R��
	PLAYER_PUNCH,		//�p���`

	PLAYER_IMEG_MAX,		//�摜�̖���
};

//�摜�̃p�X
const char PLAYER_IMAGE_PATH[PLAYER_IMEG_MAX][255] =
{
	"data/player/usagi_normal.png",			
	"data/player/usagi_kick.png",			
	"data/player/usagi_attack.png",			
};
class Player
{
private:
	int imgHandl[PLAYER_IMEG_MAX];
	int posX, posY;
	float angle;		//�v���C���[�������Ă������
	int playerImg[3];
	int phese;			//�{�Ґi�s
	int Yspeed;			//�W�����v
	int collsionYspeed;			//�W�����v

public:
	bool direction[4];			//�v���C���[�������Ă���E�����Ă���L�[
	bool attacDirection[4];		//�U���v���C���[�������Ă���E�����Ă���L�[
	bool isHit;					//�P���ɓG�ɍU��������
	bool isDraw;				//���G���ԁ@�U�����ꒆ�_��
	int playerImgNum;			//�v���C���[�̉摜�Y����
	int HP;
	int attckCount;				//�r��L�΂������E�ő�R
	int collisionPosX;			//�����蔻��p�̍��W
	int collisionPosY;

	void Init();				//������
	void Step();				//�ʏ폈��
	void Draw();				//�`��
	void Fin();					//�I������
	void MoveImage();			//�U���摜�w��
	void Operation();			//�v���C���[����
	void Jump();				//�W�����v
	void BottunInit();			//�{�^���̏�����/���t���[��������������
	void directionSetting(int num);//�����ݒ�
	void InvincibleTime(int count);//���G����
	int GetPosX() { return posX; }//���W�擾
	int GetPosY() { return posY; }

};