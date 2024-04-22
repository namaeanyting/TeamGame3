#include "DxLib.h"
#include "Scene.h"
#include "Result.h"

SceneResult::SceneResult() {}
SceneResult::~SceneResult() {}

//������
void SceneResult::Init()
{
	//�摜�ǂݍ���
	for (int i = 0; i < RESULT_IMEG_MAX; i++)
	{
		imgHandl[i] = LoadGraph(RESULT_IMAGE_PATH[i]);
	}

	//BGM
	Sound::BGM::PlayButton(BGM_RESULT);
	Sound::BGM::Volume(BGM_RESULT, 50);

	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_RESULT;

}

// �ʏ폈��
void SceneResult::Step()
{
	////�L�[
	//Input::Step();

	//�X�y�[�X�L�[�𗣂������ʈړ�
	if (Input::IsKeyPush(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_RESULT;
	}
}

// �`�揈��
void SceneResult::Draw()
{
	DrawGraph(0, 0, imgHandl[RESULT_BACK], true);
}

// �I������
void SceneResult::Fin()
{
	//BGM�̍폜
	Sound::BGM::StopDelButton(BGM_RESULT);


	//�^�C�g���ړ�
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}