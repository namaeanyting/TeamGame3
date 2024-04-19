#include "DxLib.h"
#include "Scene.h"
#include "Play.h"
#include "../Input/Input.h"
#include "../Collision/Collision.h"

//�^�C�g���̏�����
void ScenePlay::Init()
{
	//�摜�ǂݍ���
	for (int i = 0; i < PLAY_IMEG_MAX; i++)
	{
		imgHandl[i] = LoadGraph(PLAY_IMAGE_PATH[i]);
	}


	//�����������̃J�E���g������
	HitCount = 0;

	//���G�Q�[�W�o�[�摜�ǂݍ���
	Invincible_Bar_Hndl = LoadGraph(INVINCIBLE_BAR);

	//���G�Q�[�W�摜�ǂݍ���
	Invincible_Gauge_Hndl = LoadGraph(INVINCIBLE_GAUGE);

	//���G�t���O
	Invincible = false;

	//���G����
	Invincible_Time = 5;

	//���˂�|�����J�E���g
	Fox_Count = 0;

	//�e�N���X������
	player.Init();
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].Init();
	}
	flameCount = 0;

	//�����_���ɐ���
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		EnemyGeneration(i);
	}
	

	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}
// �^�C�g���ʏ폈��
void ScenePlay::Step()
{
	flameCount++;

	//���t���[���{�^���̏�����
	player.BottunInit();

	//�L�[
	Input::Step();

	//����
	player.Operation();

	//�G�i�s
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].Step();
	}

	//���X�|�[��
	Respawn();

	//HP����
	HPControl();

	//�����蔻��
	PlyerToEnemyHit();

	
	//�X�y�[�X�L�[�����������ʈړ�
	if (Input::IsKeyPush(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}
}

// �^�C�g���`�揈��
void ScenePlay::Draw()
{
	//�w�i�摜
	DrawGraph(0, 0, imgHandl[PLAY_BACK], true);

	//�v���C���[�`��
	player.Draw();

	//�G�`��
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].Draw();
	}

	//���G�֘A�`��
	DrawInvincibleGauge();

	//�f�o�b�O�p
	DrawFormatString(0, 0, GetColor(255, 255, 255), "flame:%d", flameCount);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "playerHP:%d",player.HP);
	for (int i = 0; i < ENEMY_NUM; i++){
		DrawFormatString(0, 80+i*20, GetColor(255, 255, 255), "enemyHP:%d", enemy[i].HP);
	}
	//���W
	DrawFormatString(0, 160, GetColor(255, 255, 255), "�G0��x:%d", enemy[0].x);
	DrawFormatString(0, 180, GetColor(255, 255, 255), "�G1��x:%d", enemy[1].x);
	DrawFormatString(0, 200, GetColor(255, 255, 255), "�G2��x:%d", enemy[2].x);

}

// �^�C�g���I������
void ScenePlay::Fin()
{
	////BGM�̍폜
	//StopSoundMem(sound.bgm[BGM_PLAY]);
	//DeleteSoundMem(sound.bgm[BGM_PLAY]);
	////SE�̍폜
	//for (int i = 0; i < ALL_SOUND; i++) {
	//	StopSoundMem(sound.se[i]);
	//	DeleteSoundMem(sound.se[i]);
	//}

	// �v���C�V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}

//�v���C���[�ƓG�����蔻��
void ScenePlay::PlyerToEnemyHit()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (IsHitRect(enemy[i].x, enemy[i].y, ENEMY_SIZE_X, ENEMY_SIZE_Y,
			(WINDOW_WIDTH/2) - (PLAYER_SIZE_X/2), (WINDOW_HEIGHT/2)- (ENEMY_SIZE_Y/2), PLAYER_SIZE_X, PLAYER_SIZE_Y))
		{
			//�U������Ă��玞�Ԃ��J�E���g
			HitCount++;

			//�v���C���[���������Ă� && ������i�s
			if (player.direction[3] && enemy[i].isLeft) {
				enemy[i].HP--;
				if (enemy[i].HP == 0) {
					enemy[i].isActive = false;//���S�O���t��܂�
				}
			}
			else if (HitCount > 200) {
				player.HP--;		//100�̎������_���[�W��^����
				HitCount = 0;		//�_���[�W��^������܂�0�ɖ߂��A�J�E���g�𓪂���ɂ���
			}
			DrawFormatString(0, 420, GetColor(255, 255, 255), "��hit");

		}	
		if (IsHitRect(enemy[i].x, enemy[i].y, ENEMY_SIZE_X, ENEMY_SIZE_Y,
			(WINDOW_WIDTH / 2) + (PLAYER_SIZE_X / 2), (WINDOW_HEIGHT / 2) - (ENEMY_SIZE_Y / 2), PLAYER_SIZE_X, PLAYER_SIZE_Y))
		{
			//�v���C���[���E�����Ă� && �E����i�s
			if (player.direction[1] && !enemy[i].isLeft) {
				enemy[i].HP--;
				if (enemy[i].HP == 0) {
					enemy[i].isActive = false;//���S�O���t��܂�
				}
			}
			else if (HitCount > 200) {
				player.HP--;		//100�̎������_���[�W��^����
				HitCount = 0;		//�_���[�W��^������܂�0�ɖ߂��A�J�E���g�𓪂���ɂ���
			}

			//�f�o�b�O�p
			DrawFormatString(0, 440, GetColor(255, 255, 255), "�Ehit");
			//DrawFormatString(0, 40, GetColor(255, 255, 255), "�J�E���g:%d", HitCount);
		}
	}



}

//�����_������
void ScenePlay::EnemyGeneration(int enemyNum) {
	if (GetRand(1) == 0) {
		enemy[enemyNum].x = 0;
		enemy[enemyNum].y = 360;
		enemy[enemyNum].isLeft = true;
	}
	else {
		enemy[enemyNum].x = 1280;
		enemy[enemyNum].y = 360;
		enemy[enemyNum].isLeft = false;
	}
}

//�G�̂�݂�����ݒ�
void ScenePlay::Respawn()
{
	if (flameCount >= 60) {
		for (int i = 0; i < ENEMY_NUM; i++)
		{
			if (!enemy[i].isActive) {

				EnemyGeneration(i);
				enemy[i].isActive = true;
				flameCount = 0;
			}
		}
	}
}

//HP�̐���
void ScenePlay::HPControl()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].HP < 0) {
			enemy[i].HP = 0;
		}
	}
	if (player.HP < 0) {
		player.HP = 0;
	}
}

//���G�Q�[�W�`��
void ScenePlay::DrawInvincibleGauge()
{
	// ���G�Q�[�W�o�[�`��
		DrawGraph(100, 100, Invincible_Bar_Hndl, true);

	//���G�Q�[�W�𑝂₷�`��
	if (Invincible == false)
	{
		DrawRectGraph(100, 100, 0, 0, 10 * Fox_Count, 100, Invincible_Gauge_Hndl, true, false);
	}
	//���G�������ꍇ�A�Q�[�W�����炷�`��
	else
	{
		DrawRectGraph(100, 100, 0, 0, 20 * Invincible_Time, 100, Invincible_Gauge_Hndl, true, false);
	}
}