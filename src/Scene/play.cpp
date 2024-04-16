#include "DxLib.h"
#include "Scene.h"
#include "Play.h"
#include "../Input/Input.h"

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

	//�L�[�̏�����
	Input::Init();

	//BGM
	//sound.bgm[BGM_PLAY] = LoadSoundMem("data/Sound/play.mp3");
	////���ʒ���
	//ChangeVolumeSoundMem(255 * 50 / 100, sound.bgm[BGM_PLAY]);
	//PlaySoundMem(sound.bgm[BGM_PLAY], DX_PLAYTYPE_LOOP, true);

	////SE
	//sound.InitPlay();


	//�X�R�A������
	/*score.Init();
	score.Load();*/


	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
	//play�̒��̏����ړ�
	//g_CurrentScenePlayID = ID_PLAY_REDITION;
}
// �^�C�g���ʏ폈��
void ScenePlay::Step()
{
	//�L�[
	Input::Step();
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

	//score.Draw();

	//�f�o�b�O�p
	//DrawFormatString(0, 0, GetColor(255, 0, 0), "��@%d", BG_PosY[0]);
	//DrawFormatString(0, 20, GetColor(255, 0, 0), "���@%d", BG_PosY[1]);

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