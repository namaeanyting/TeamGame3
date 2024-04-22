#pragma once
#include "../Player/player.h"
#include "../Enemy/enemy.h"
#define ATTACK_WAITE_TIME  75
//�摜���g���Ƃ��̖��O
enum PLAY_IMAGE
{
	PLAY_BACK,		//�^�C�g���̔w�i

	PLAY_IMEG_MAX,		//�摜�̖���
};

//�摜�̃p�X
const char PLAY_IMAGE_PATH[PLAY_IMEG_MAX][255] =
{
	"data/play/back.png",			//�^�C�g���w�i�摜
};

#define INVINCIBLE_BAR		"data/play/bar.png"		//���G�Q�[�W�o�[
#define INVINCIBLE_GAUGE	"data/play/�Q�[�W.png"	//���G�Q�[�W

#define KNIFE_PATH		"data/play/�i�C�t.png"

class ScenePlay
{
private:
	int imgHandl[PLAY_IMEG_MAX];	//�摜�n���h��
	int HitCount[ENEMY_NUM][2];					//�t���[���J�E���g

	int Invincible_Bar_Hndl;				//���G�Q�[�W�o�[�摜�n���h��
	int Invincible_Gauge_Hndl;				//���G�Q�[�W�摜�n���h��

	bool Invincible;				//���G�t���O
	float Invincible_Time;			//���G���ԕϐ�
	int Fox_Count;					//���˂�|�������̃J�E���g

	int KnifeHndl;
	int Knife_x, Knife_y;
	bool knife;
	float Knife_Count;
	
public:

	Player player;
	Enemy enemy[ENEMY_NUM];//�G�̐�
	Enemy enemy2[ENEMY_NUM2];//HP�������G�L����
	int flameCount;
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
	//�����_������
	void EnemyGeneration(int enemyNum);
	//�G�̂�݂�����ݒ�
	void Respawn();
	//HP�̐���
	void HPControl();
	//���G�Q�[�W�`��
	void DrawInvincibleGauge();
};