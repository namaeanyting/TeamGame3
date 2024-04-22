#include "DxLib.h"
#include "Scene.h"
#include "Play.h"
#include "../Input/Input.h"
#include "../Collision/Collision.h"

//�^�C�g���̏�����
void ScenePlay::Init()
{	
	flameCount = 0;

	//�摜�ǂݍ���
	for (int i = 0; i < PLAY_IMEG_MAX; i++)
	{
		imgHandl[i] = LoadGraph(PLAY_IMAGE_PATH[i]);
	}

	KnifeHndl = LoadGraph(KNIFE_PATH);

	Knife_x = -50;
	Knife_y = 300;
	Knife_Count = 0.0f;
	knife = false;

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
		enemy[i].HP = ENEMY_HP_MAX;
		enemy[i].EnemyGeneration();//�����_���ɐ���

	}
	for (int i = 0; i < ENEMY_NUM2; i++)
	{
		enemy2[i].Init();
		enemy2[i].HP = ENEMY_HP_MAX;
		enemy2[i].EnemyGeneration();
	}
	
	//BGM
	Sound::BGM::PlayButton(BGM_PLAY);
	Sound::BGM::Volume(BGM_PLAY, 50);

	
	//���G�Q�[�W�o�[�摜�ǂݍ���
	Invincible_Bar_Hndl = LoadGraph(INVINCIBLE_BAR);
	//���G�Q�[�W�摜�ǂݍ���
	Invincible_Gauge_Hndl = LoadGraph(INVINCIBLE_GAUGE);
	//���G�t���O
	Invincible = false;
	//���G����
	Invincible_Time = 5.0f;
	//���˂�|�����J�E���g
	Fox_Count = 0;

	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}
// �^�C�g���ʏ폈��
void ScenePlay::Step()
{
	flameCount++;
	flameCountEne2++;

	//���t���[���U���{�^����false��
	player.BottunInit();

	////�L�[
	//Input::Step();
	//����
	player.Operation();

	//�G�i�s
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].Step();
	}
	for (int i = 0; i < ENEMY_NUM2; i++)
	{
		enemy2[i].Step();
	}
	Knife_Count++;
	if (Knife_Count == 300.0f)
	{
		if (knife == false)
		{
			Knife_x = 1300;
			knife = true;
		}
	}
	
	if (knife == true)
	{
		Knife_x -= 6;
		if (Knife_x < -110)
		{
			knife = false;
			Knife_Count = 0.0f;
		}
	}

	//�G�̃��X�|�[��
	Respawn();

	//�����蔻��
	PlyerToEnemyHit();
	PlyerToEnemy2Hit();
	player.Step();
	player.MoveImage();
	
	//�X�y�[�X�L�[�����������ʈړ�
	if (Input::IsKeyPush(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}
	//���G�t���O��true�̎����G�^�C�������炷
	if (Invincible == true)
	{
		if (flameCount % 50 == 0)
		{
			Invincible_Time -= 1.0f;
			if (Invincible_Time <= 0.0f)
			{
				Invincible = false;
				Fox_Count = 0;
			}
		}
		
	}
}

// �^�C�g���`�揈��
void ScenePlay::Draw()
{
	//�w�i�摜
	DrawGraph(0, 0, imgHandl[PLAY_BACK], true);

	//�v���C���[�`��
	player.Draw();

	DrawGraph(Knife_x, Knife_y, KnifeHndl, true);

	//�G�`��
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].Draw();
	}
	for (int i = 0; i < ENEMY_NUM2; i++)
	{
		enemy2[i].Draw();
	}
	//���G�֘A�`��
	DrawInvincibleGauge();

	////�f�o�b�O�p
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "flame:%d", flameCount);
	//DrawFormatString(0, 20, GetColor(255, 255, 255), "playerHP:%d",player.HP);
	//for (int i = 0; i < ENEMY_NUM; i++){
	//	DrawFormatString(0, 80+i*20, GetColor(255, 255, 255), "enemyHP:%d", enemy[i].HP);
	//}
	////���W
	//DrawFormatString(0, 160, GetColor(255, 255, 255), "�G0��x:%d", enemy[0].x);
	//DrawFormatString(0, 180, GetColor(255, 255, 255), "�G1��x:%d", enemy[1].x);
	//DrawFormatString(0, 200, GetColor(255, 255, 255), "�G2��x:%d", enemy[2].x);
	//DrawFormatString(0, 220, GetColor(255, 255, 255), "y:%d", player.GetPosY());
	//DrawFormatString(0, 40, GetColor(255, 255, 255), "�J�E���g:%d", HitCount[0][0]);
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "�J�E���g:%d", HitCount[0][1]);
	//DrawFormatString(0, 240, GetColor(255, 255, 255), "�J�E���g:%d", Fox_Count);
	//DrawFormatString(0, 260, GetColor(255, 255, 255), "�b:%f", Invincible_Time);
	//DrawFormatString(0, 280, GetColor(255, 255, 255), "�i�C�t�J�E���g:%f", Knife_Count);
	//DrawBox(player.collisionPosX - 140, player.collisionPosY, player.collisionPosX - 140 + (PLAYER_SIZE_X / 2), player.collisionPosY +( PLAYER_SIZE_Y / 2), GetColor(255, 255, 255), true);
	//DrawBox(player.collisionPosX + 80, player.collisionPosY, player.collisionPosX + 80 +( PLAYER_SIZE_X / 2), player.collisionPosY + (PLAYER_SIZE_Y / 2), GetColor(255, 255, 255), true);

}

// �^�C�g���I������
void ScenePlay::Fin()
{
	//BGM�̍폜
	Sound::BGM::StopDelButton(BGM_TITLE);
	Sound::BGM::StopDelButton(SE_PUNCH);
	Sound::BGM::StopDelButton(SE_MONSTER);
	
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
				player.collisionPosX - 80, player.collisionPosY, PLAYER_SIZE_X / 2, PLAYER_SIZE_Y / 2))
			{
				//�U������Ă��玞�Ԃ��J�E���g
				HitCount[i][0]++;

				//�v���C���[���������čU�� && �G������i�s
				if (player.attacDirection[3] && enemy[i].isLeft) {
					enemy[i].HP--;
					player.attckCount++;
					Sound::SE::PlayButton(SE_PUNCH);
					
					if (enemy[i].HP == 0) {
						/*Fox_Count = 10;*/
						Fox_Count++;
						enemy[i].isActive = false;//���S�O���t��܂�
						Sound::SE::PlayButton(SE_MONSTER);
					}
				}
				else if (HitCount[i][0] > ATTACK_WAITE_TIME) {
					if (Invincible == true)
					{
						break;
					}
					else
					{
						player.HP--;			//200�̎������_���[�W��^����
						HitCount[i][0] = 0;		//�_���[�W��^������܂�0�ɖ߂��A�J�E���g�𓪂���ɂ���
					}
					
				}
				if (Fox_Count == 10)
				{
					Invincible = true;
					Invincible_Time = 10.0f;
				}
				//DrawFormatString(0, 420, GetColor(255, 255, 255), "��hit");

			}
			//�������ĂȂ��Ȃ�
			else {
				HitCount[i][0] = 0;
			}
		

		//�E--------------------------------------------------------------
			if (IsHitRect(enemy[i].x, enemy[i].y, ENEMY_SIZE_X, ENEMY_SIZE_Y,
				player.collisionPosX + 80, player.collisionPosY, PLAYER_SIZE_X / 2, PLAYER_SIZE_Y / 2))
			{
				//�U������Ă��玞�Ԃ��J�E���g
				HitCount[i][1]++;
				//�v���C���[���E�����Ă� && �E����i�s
				if (player.attacDirection[1] && !enemy[i].isLeft) {
					enemy[i].HP--;
					player.attckCount++;
					Sound::SE::PlayButton(SE_PUNCH);

					if (enemy[i].HP == 0) {
						//Fox_Count = 10;
						Fox_Count++;
						enemy[i].isActive = false;//���S�O���t��܂�
						Sound::SE::PlayButton(SE_MONSTER);

					}
					
				}
				else if (HitCount[i][1] > ATTACK_WAITE_TIME) {
					if (Invincible == true)
					{
						break;
					}
					else
					{
						player.HP--;			//200�̎������_���[�W��^����
						HitCount[i][1] = 0;		//�_���[�W��^������܂�0�ɖ߂��A�J�E���g�𓪂���ɂ���
					}
				}
				if (Fox_Count == 10)
				{
					Invincible = true;
					Invincible_Time = 10.0f;
				}
				////�f�o�b�O�p
			//	DrawFormatString(0, 440, GetColor(255, 255, 255), "�Ehit");
				//DrawFormatString(0, 40, GetColor(255, 255, 255), "�J�E���g:%d", HitCount[0]);
				//DrawFormatString(0, 60, GetColor(255, 255, 255), "�J�E���g:%d", HitCount[1]);
			}
			//�������ĂȂ��Ȃ�
			else {
				HitCount[i][1] = 0;
			}
			
	}

	if (knife == true)
		{
			if (IsHitRect(Knife_x, Knife_y, 35, 35, player.GetPosX() - 70, player.GetPosY() - 100, 140, 100))
			{
				player.HP--;
				knife = false;
				Knife_Count = 0.0f;
			}
		}
	}

	//�v���C���[�ƓG2�����蔻��
void ScenePlay::PlyerToEnemy2Hit()
{
	for (int i = 0; i < ENEMY_NUM2; i++)
	{
		//��--------------------------------------------------------------
		if (IsHitRect(enemy2[i].x, enemy2[i].y, ENEMY_SIZE_X, ENEMY_SIZE_Y,
			(WINDOW_WIDTH / 2) - (PLAYER_SIZE_X / 2), (WINDOW_HEIGHT / 2) - (ENEMY_SIZE_Y / 2), PLAYER_SIZE_X, PLAYER_SIZE_Y))
		{
			//�U������Ă��玞�Ԃ��J�E���g
			HitCount[i][0]++;

			//�v���C���[���������čU�� && �G������i�s
			if (player.attacDirection[3] && enemy2[i].isLeft) {
				enemy2[i].HP--;
				player.attckCount++;
				Sound::SE::PlayButton(SE_PUNCH);

				if (enemy2[i].HP == 0) {
					enemy2[i].isActive = false;//���S�O���t��܂�
					Fox_Count++;				//�|������
					Sound::SE::PlayButton(SE_MONSTER);

				}
			}
			else if (HitCount[i][0] > ATTACK_WAITE_TIME) {
				player.HP--;			//200�̎������_���[�W��^����
				HitCount[i][0] = 0;		//�_���[�W��^������܂�0�ɖ߂��A�J�E���g�𓪂���ɂ���
			}
			//DrawFormatString(0, 420, GetColor(255, 255, 255), "��hit");

		}
		//�������ĂȂ��Ȃ�
		else {
			HitCount[i][0] = 0;
		}

		//�E--------------------------------------------------------------
		if (IsHitRect(enemy2[i].x, enemy2[i].y, ENEMY_SIZE_X, ENEMY_SIZE_Y,
			(WINDOW_WIDTH / 2) + (PLAYER_SIZE_X / 2), (WINDOW_HEIGHT / 2) - (ENEMY_SIZE_Y / 2), PLAYER_SIZE_X, PLAYER_SIZE_Y))
		{
			//�U������Ă��玞�Ԃ��J�E���g
			HitCount[i][1]++;
			//�v���C���[���E�����Ă� && �E����i�s
			if (player.attacDirection[1] && !enemy2[i].isLeft) {
				enemy2[i].HP--;
				player.attckCount++;
				Sound::SE::PlayButton(SE_PUNCH);

				if (enemy2[i].HP == 0) {
					enemy2[i].isActive = false;	//���S�O���t��܂�
					Fox_Count++;				//�|������
					Sound::SE::PlayButton(SE_MONSTER);

				}
			}
			else if (HitCount[i][1] > ATTACK_WAITE_TIME) {
				player.HP--;			//200�̎������_���[�W��^����
				HitCount[i][1] = 0;		//�_���[�W��^������܂�0�ɖ߂��A�J�E���g�𓪂���ɂ���
			}

			////�f�o�b�O�p
			//DrawFormatString(0, 440, GetColor(255, 255, 255), "�Ehit");
			//DrawFormatString(0, 40, GetColor(255, 255, 255), "�J�E���g:%d", HitCount[0]);
			//DrawFormatString(0, 60, GetColor(255, 255, 255), "�J�E���g:%d", HitCount[1]);
		}
		//�������ĂȂ��Ȃ�
		else {
			HitCount[i][1] = 0;
		}
	}
}


//�G�̂�݂�����ݒ�
void ScenePlay::Respawn()
{
	if (flameCount >= 60) {
		for (int i = 0; i < ENEMY_NUM; i++)
		{
			if (!enemy[i].isActive) {

				enemy[i].EnemyGeneration();
				enemy[i].isActive = true;
				flameCount = 0;
			}
		}
	}

	if (flameCountEne2 >= 80) {
		for (int i = 0; i < ENEMY_NUM2; i++)
		{
			if (!enemy2[i].isActive) {

				enemy2[i].EnemyGeneration();
				enemy2[i].isActive = true;
				flameCountEne2 = 0;
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
		DrawRectGraph(100, 100, 0, 0, 40 * Fox_Count, 100, Invincible_Gauge_Hndl, true, false);
	}
	//���G�������ꍇ�A�Q�[�W�����炷�`��
	else
	{
		DrawRectGraph(100, 100, 0, 0, 80 * Invincible_Time, 100, Invincible_Gauge_Hndl, true, false);
	}
}