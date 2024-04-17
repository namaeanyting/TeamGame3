#pragma once
#include "../Player/player.h"
#include "../Enemy/enemy.h"

//�摜���g���Ƃ��̖��O
enum PLAY_IMAGE
{
	PLAY_BACK,		//�^�C�g���̔w�i

	PLAY_IMEG_MAX,		//�摜�̖���
};

//�摜�̃p�X
const char PLAY_IMAGE_PATH[PLAY_IMEG_MAX][255] =
{
	"data/play/2.png",			//�^�C�g���w�i�摜
};

class ScenePlay
{
private:
	int imgHandl[PLAY_IMEG_MAX];	//�摜�n���h��

	
public:
	ScenePlay();
	~ScenePlay();

	Player player;
	Enemy enemy[ENEMY_KAIND];

	//������
	void Init();

	//�ʏ폈��
	void Step();

	//�`��
	void Draw();

	//�I������
	void Fin();
	//�v���C���[�ƓG�����蔻��
	void PlyerToEnemyHit();
};