#include "DxLib.h"
#include "Title.h"
#include "scene.h"
#include "../Input/Input.h"


//�^�C�g���̏�����
void SceneTitle::Init()
{
	//�摜�ǂݍ���
	for (int i = 0; i < TITLE_IMEG_MAX; i++)
	{
		imgHandl[i] = LoadGraph(TITLE_IMAGE_PATH[i]);
	}

	nameHandl = LoadGraph(TITLE_NAME_PATH);
	

	//BGM
	Sound::BGM::PlayButton(BGM_TITLE);
	Sound::BGM::Volume(BGM_TITLE, 50);


	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;

}

// �^�C�g���ʏ폈��
void SceneTitle::Step()
{

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
	DrawRotaGraph(650, 100, 1.5f, 0.0f, nameHandl, true);
}

// �^�C�g���I������
void SceneTitle::Fin()
{
	//BGM�̍폜
	Sound::BGM::StopDelButton(BGM_TITLE);

	// �v���C�V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}