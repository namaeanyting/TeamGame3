#include "DxLib.h"
#include "Scene.h"
#include "Play.h"
#include "../Input/Input.h"
#include "../Collision/Collision.h"

ScenePlay::ScenePlay(){}
ScenePlay::~ScenePlay() {}

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

	//BGM
	//sound.bgm[BGM_PLAY] = LoadSoundMem("data/Sound/play.mp3");
	////���ʒ���
	//ChangeVolumeSoundMem(255 * 50 / 100, sound.bgm[BGM_PLAY]);
	//PlaySoundMem(sound.bgm[BGM_PLAY], DX_PLAYTYPE_LOOP, true);
	////SE
	//sound.InitPlay();

	//�e�N���X������
	player.Init();
	for (int i = 0; i < ENEMY_KAIND; i++)
	{
		enemy[i].Init();
	}
	flameCount = 0;

	//������i�s
	enemy[0].x = 0;
	enemy[0].y = 360;
	enemy[0].isLeft = true;
	enemy[0].isActive = true;

	//�E����i�s
	enemy[1].x = 1280;
	enemy[1].y = 360;
	enemy[1].isLeft = false;
	enemy[1].isActive = true;

	//�E����i�s
	enemy[2].x = 1280;
	enemy[2].y = 360;
	enemy[2].isLeft = false;
	enemy[2].isActive = false;
	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}
// �^�C�g���ʏ폈��
void ScenePlay::Step()
{
	flameCount++;

	for (int i = 0; i < 4; i++) {
		player.direction[i] = false;
	}

	//�L�[
	Input::Step();

	//����
	player.Operation();

	//�G�i�s
	for (int i = 0; i < ENEMY_KAIND; i++)
	{
		enemy[i].Step();
	}

	if (flameCount >= 60) {
		for (int i = 0; i < ENEMY_KAIND; i++)
		{
			if (!enemy[i].isActive) {
				if (enemy[i].isLeft) {
					enemy[i].x = 0;
					enemy[i].y = 360;
				}
				else {
					enemy[i].x = 1280;
					enemy[i].y = 360;
				}

				enemy[i].isActive = true;
				flameCount = 0;
			}
		}
	}

	////DO
	//for (int i = 0; i < ENEMY_KAIND; i++)
	//{
	//	if (enemy[i].HP < 0) {
	//		enemy[i].HP = 0;
	//	}
	//}
	if (player.HP < 0) {
		player.HP = 0;
	}
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
	//DrawGraph(0, 0, imgHandl[PLAY_BACK], true);

	//�v���C���[�`��
	player.Draw();

	//�G�`��
	for (int i = 0; i < ENEMY_KAIND; i++)
	{
		enemy[i].Draw();
	}

	//�f�o�b�O�p
	DrawFormatString(0, 0, GetColor(255, 255, 255), "flame:%d", flameCount);

	/*DrawFormatString(0, 40, GetColor(255, 255, 255), "playerHP:%d",player.HP);
	for (int i = 0; i < ENEMY_KAIND; i++)
	{
		DrawFormatString(0, 80, GetColor(255, 255, 255), "enemyHP:%d", enemy[i].HP);
	}
	if (player.direction[1]) {
		DrawBox(player.GetPosX(), player.GetPosY(),
			player.GetPosX() + PLAYER_SIZE_X, player.GetPosY() + PLAYER_SIZE_Y, GetColor(255, 255, 255), true);
	}
	if (player.direction[3]) {
		DrawBox(player.GetPosX(), player.GetPosY(),
			player.GetPosX() - PLAYER_SIZE_X, player.GetPosY() + PLAYER_SIZE_Y, GetColor(255, 255, 255), true);
	}*/
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
	for (int i = 0; i < ENEMY_KAIND; i++)
	{
		////���������Ă���
		//if (player.direction[3]) {

		//	if (IsHitRect(player.GetPosX(), player.GetPosY(), PLAYER_SIZE_X, PLAYER_SIZE_Y,
		//		enemy[i].GetPosX(), enemy[i].GetPosY(), ENEMY_SIZE_X, ENEMY_SIZE_Y))
		//	{
		//		enemy[i].HP--;
		//		
		//	}
		//}
	}
	//for (int i = 0; i < ENEMY_KAIND; i++)
	//{
	//	if (IsHitRect(player.GetPosX(), player.GetPosY(), PLAYER_SIZE_X, PLAYER_SIZE_Y,
	//		enemy[i].GetPosX(), enemy[i].GetPosY(), ENEMY_SIZE_X, ENEMY_SIZE_Y))
	//	{
	//		//�U������Ă��玞�Ԃ��J�E���g
	//		HitCount++;

	//		if (player.direction[3] && enemy[i].direction[0]) {
	//			enemy[i].HP--;
	//		}
	//		else if (HitCount > 200) {
	//			player.HP--;		//100�̎������_���[�W��^����
	//			HitCount = 0;		//�_���[�W��^������܂�0�ɖ߂��A�J�E���g�𓪂���ɂ���
	//		}
	//		//�f�o�b�O�p
	//		DrawFormatString(0, 20, GetColor(255, 255, 255), "hit");
	//		DrawFormatString(60, 20, GetColor(255, 255, 255), "�J�E���g:%d",HitCount);
	//	}
	//}



}

