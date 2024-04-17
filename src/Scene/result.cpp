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
	//�L�[�̏�����
	//Input::Init();

	//BGM
	//sound.bgm[BGM_ED] = LoadSoundMem("data/Sound/resulr.mp3");//OP
	//PlaySoundMem(sound.bgm[BGM_ED], DX_PLAYTYPE_LOOP, true);

	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_RESULT;

}

// �ʏ폈��
void SceneResult::Step()
{
	//�L�[
	Input::Step();

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
	//StopSoundMem(sound.bgm[BGM_ED]);
	//DeleteSoundMem(sound.bgm[BGM_ED]);

	//�^�C�g���ړ�
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}