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
	"data/play/back.png",			//�^�C�g���w�i�摜
};

#define INVINCIBLE_BAR		"data/play/bar.png"		//���G�Q�[�W�o�[
#define INVINCIBLE_GAUGE	"data/play/�Q�[�W.png"	//���G�Q�[�W


#define PLAYER_ATTACK_MAX_NUM	(3)		//�G�t�F�N�g�̍ő吔
#define ENEMY_ATTACK_MAX_NUM	(3)

#define PLAYER_ATTACK_EFFECT1		"data/play/�����[.png"
#define PLAYER_ATTACK_EFFECT2		"data/play/�ӂ���.png"
#define PLAYER_ATTACK_EFFECT3		"data/play/��[.png"

#define ENEMY_ATTACK_EFFECT1		"data/play/������.png"
#define ENEMY_ATTACK_EFFECT2		"data/play/�������߂��[.png"
#define ENEMY_ATTACK_EFFECT3		"data/play/������߂�.png"

class ScenePlay
{
private:
	int imgHandl[PLAY_IMEG_MAX];	//�摜�n���h��
	int HitCount;					//�t���[���J�E���g

	int Invincible_Bar_Hndl;				//���G�Q�[�W�o�[�摜�n���h��
	int Invincible_Gauge_Hndl;				//���G�Q�[�W�摜�n���h��

	bool Invincible;				//���G�t���O
	int Invincible_Time;			//���G���ԕϐ�
	int Fox_Count;					//���˂�|�������̃J�E���g

	int player_attack_Hndl[PLAYER_ATTACK_MAX_NUM];

	int enemy_attack_Hndl[ENEMY_ATTACK_MAX_NUM];

	int Player_Effect_Num;

	int Enemy_Effect_Num;

	bool Player_Attack;
	
	bool Enemy_Attack;

	
public:
	ScenePlay();
	~ScenePlay();

	Player player;
	Enemy enemy[ENEMY_KAIND];

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
	
};