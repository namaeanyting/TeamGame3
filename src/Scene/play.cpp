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
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		HitCount[i][0] = 0;
		HitCount[i][1] = 0;
	}

	//�e�N���X������
	player.Init();
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].Init();
		//�i�s�����̏�����
		enemy[i].HP = ENEMY_HP_MAX;
	}
	flameCount = 0;

	//�����_���ɐ���
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		EnemyGeneration(i);
	}
	
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

	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}
// �^�C�g���ʏ폈��
void ScenePlay::Step()
{
	flameCount++;
	//���t���[���U���{�^����false��
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

	//�G�̃��X�|�[��
	Respawn();

	//�����蔻��
	PlyerToEnemyHit();
	player.Step();
	player.MoveImage();
	
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
	//DrawGraph(0, 0, imgHandl[PLAY_BACK], true);

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
	DrawFormatString(0, 220, GetColor(255, 255, 255), "y:%d", player.GetPosY());
	DrawFormatString(0, 40, GetColor(255, 255, 255), "�J�E���g:%d", HitCount[0][0]);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "�J�E���g:%d", HitCount[0][1]);

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
		//��--------------------------------------------------------------
		if (IsHitRect(enemy[i].x, enemy[i].y, ENEMY_SIZE_X, ENEMY_SIZE_Y,
			(WINDOW_WIDTH/2) - (PLAYER_SIZE_X/2), (WINDOW_HEIGHT/2)- (ENEMY_SIZE_Y/2), PLAYER_SIZE_X, PLAYER_SIZE_Y))
		{
			//�U������Ă��玞�Ԃ��J�E���g
			HitCount[i][0]++;

			//�v���C���[���������čU�� && �G������i�s
			if (player.attacDirection[3] && enemy[i].isLeft) {
				enemy[i].HP--;
				player.attckCount++;
				
				if (enemy[i].HP == 0) {
					enemy[i].isActive = false;//���S�O���t��܂�
				}
			}
			else if (HitCount[i][0] > ATTACK_WAITE_TIME) {
				player.HP--;			//200�̎������_���[�W��^����
				HitCount[i][0] = 0;		//�_���[�W��^������܂�0�ɖ߂��A�J�E���g�𓪂���ɂ���
			}
			DrawFormatString(0, 420, GetColor(255, 255, 255), "��hit");

		}
		//�������ĂȂ��Ȃ�
		else {
			HitCount[i][0] = 0;
		}

		//�E--------------------------------------------------------------
		if (IsHitRect(enemy[i].x, enemy[i].y, ENEMY_SIZE_X, ENEMY_SIZE_Y,
			(WINDOW_WIDTH / 2) + (PLAYER_SIZE_X / 2), (WINDOW_HEIGHT / 2) - (ENEMY_SIZE_Y / 2), PLAYER_SIZE_X, PLAYER_SIZE_Y))
		{
			//�U������Ă��玞�Ԃ��J�E���g
			HitCount[i][1]++;
			//�v���C���[���E�����Ă� && �E����i�s
			if (player.attacDirection[1] && !enemy[i].isLeft) {
				enemy[i].HP--;
				player.attckCount++;

				if (enemy[i].HP == 0) {
					enemy[i].isActive = false;//���S�O���t��܂�
				}
			}
			else if (HitCount[i][1] > ATTACK_WAITE_TIME) {
				player.HP--;			//200�̎������_���[�W��^����
				HitCount[i][1] = 0;		//�_���[�W��^������܂�0�ɖ߂��A�J�E���g�𓪂���ɂ���
			}

			////�f�o�b�O�p
			DrawFormatString(0, 440, GetColor(255, 255, 255), "�Ehit");
			//DrawFormatString(0, 40, GetColor(255, 255, 255), "�J�E���g:%d", HitCount[0]);
			//DrawFormatString(0, 60, GetColor(255, 255, 255), "�J�E���g:%d", HitCount[1]);
		}
		//�������ĂȂ��Ȃ�
		else {
			HitCount[i][1] = 0;
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