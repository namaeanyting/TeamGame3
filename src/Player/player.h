#pragma once
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
	float directionAngle;		//�v���C���[�������Ă������
	int playerImg[3];
public:
	bool direction[4];			//�v���C���[�������Ă���E�����Ă���L�[
	bool attacDirection[4];			//�U���v���C���[�������Ă���E�����Ă���L�[
	bool isHit;//�P���ɓG�ɍU��������
	int playerImgNum;		//�v���C���[�̉摜�Y����
	int HP;
	int attckCount;				//�r��L�΂������E�ő�R

	//������
	void Init();

	//�ʏ폈��
	void Step();

	//�`��
	void Draw();

	//�I������
	void Fin();

	//�v���C���[����
	void Operation();

	//�{�^���̏�����/���t���[��������������
	void BottunInit();

	//�����ݒ�
	void directionSetting(int num);
	
	//���W�擾
	int GetPosX() { return posX; }
	int GetPosY() { return posY; }

};