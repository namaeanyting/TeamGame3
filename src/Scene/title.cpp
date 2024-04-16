#include "DxLib.h"
#include "Title.h"
#include "scene.h"
#include "../Input/Input.h"

SceneTitle::SceneTitle()
{
	//sound.bgm[BGM_OP] = 0;		//BGM�̏�����
}

SceneTitle::~SceneTitle() {}

//�^�C�g���̏�����
void SceneTitle::Init()
{
	//�摜�ǂݍ���
	for (int i = 0; i < TITLE_IMEG_MAX; i++)
	{
		imgHandl[i] = LoadGraph(TITLE_IMAGE_PATH[i]);
	}
	
	//�L�[�̏�����
	Input::Init();

	//BGM
	//sound.bgm[BGM_OP] = LoadSoundMem("data/Sound/title.mp3");//OP
	//PlaySoundMem(sound.bgm[BGM_OP], DX_PLAYTYPE_LOOP, true);


	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;

}

// �^�C�g���ʏ폈��
void SceneTitle::Step()
{
	//�L�[
	Input::Step();

	//�X�y�[�X�L�[�����������ʈړ�
	if (Input::IsKeyPush(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

// �^�C�g���`�揈��
void SceneTitle::Draw()
{
	DrawGraph(0, 0, imgHandl[TITLE_BACK], true);
}

// �^�C�g���I������
void SceneTitle::Fin()
{
	//BGM�̍폜
	//StopSoundMem(sound.bgm[BGM_OP]);
	//DeleteSoundMem(sound.bgm[BGM_OP]);

	// �v���C�V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}