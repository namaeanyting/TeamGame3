#pragma once
#include "../Sound/Sound.h"
//�E�B���h�E�̕��E����
#define WINDOW_HEIGHT	(720)
#define WINDOW_WIDTH	(1280)
// �G�̉摜�T�C�Y
const int ENEMY_SIZE_Y = 200;
const int ENEMY_SIZE_X = 140;
enum SCENE_ID
{
	//�^�C�g���V�[��ID���
	SCENE_ID_INIT_TITLE,	//������
	SCENE_ID_LOOP_TITLE,	//�J��Ԃ�
	SCENE_ID_FIN_TITLE,		//�I��

	//�v���C�V�[�����
	SCENE_ID_INIT_PLAY,
	SCENE_ID_LOOP_PLAY,
	SCENE_ID_FIN_PLAY,

	//�I���V�[�����
	SCENE_ID_INIT_RESULT,
	SCENE_ID_LOOP_RESULT,
	SCENE_ID_FIN_RESULT,

};

extern int g_CurrentSceneID;
