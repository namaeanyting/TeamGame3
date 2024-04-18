#pragma once
// �v���C���[�̉摜�T�C�Y
const int PLAYER_SIZE_Y = 200; 
const int PLAYER_SIZE_X = 140; 

//HP�̍ő�l
const int PLAYER_HP_MAX = 6;

//�摜���g���Ƃ��̖��O
enum PLAYER_IMAGE
{
	PLAYER_PLAYER,		//�^�C�g���̔w�i

	PLAYER_IMEG_MAX,		//�摜�̖���
};

//�摜�̃p�X
const char PLAYER_IMAGE_PATH[PLAYER_IMEG_MAX][255] =
{
	"data/play/2.png",			//�^�C�g���w�i�摜
};
class Player
{
private:
	int imgHandl[PLAYER_IMEG_MAX];
	int posX, posY;
	float directionAngle;		//�v���C���[�������Ă������
	
public:
	bool direction[4];			//�v���C���[�������Ă���E�����Ă���L�[
	int HP;
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

	//���W�擾
	int GetPosX() { return posX; }
	int GetPosY() { return posY; }

};