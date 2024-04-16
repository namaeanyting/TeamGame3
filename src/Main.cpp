//�E�B���h�E��\������v���O�����i�ЂȌ`�j

#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include"Scene/Scene.h"
#include"Scene/Title.h"
#include"Scene/Play.h"
#include"Scene/Result.h"

int g_CurrentSceneID = SCENE_ID_INIT_TITLE;
// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	// ��ʃT�C�Y��ύX
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT ,32);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	
	//�N���X�̌Ăяo��
	SceneTitle title;
	ScenePlay play;
	SceneResult result;

	//-----------------------------------------

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//�G�X�P�[�v�L�[�������ꂽ��I��
			break;
		}

		//��ʂɕ\�����ꂽ���̂�������
		ClearDrawScreen();
		
		switch (g_CurrentSceneID)
		{

		case SCENE_ID_INIT_TITLE:
		{
			title.Init();
		}
		break;

		case SCENE_ID_LOOP_TITLE:
		{
			title.Step();
			title.Draw();
		}
		break;

		case SCENE_ID_FIN_TITLE:
		{
			title.Fin();
		}
		break;

		case SCENE_ID_INIT_PLAY:
		{
			
			play.Init();

		}
		break;

		case SCENE_ID_LOOP_PLAY:
		{
			play.Step();
			

			//�`��
			play.Draw();				//�w�i�̕`��
			
		}
		break;

		case SCENE_ID_FIN_PLAY:
		{
			play.Fin();
		}
		break;

		case SCENE_ID_INIT_RESULT:
		{
			result.Init();
		}
		break;

		case SCENE_ID_LOOP_RESULT:
		{
			result.Step();
			result.Draw();

		}
		break;

		case SCENE_ID_FIN_RESULT:
		{
			result.Fin();
		}
		break;

		}
		//-----------------------------------------
		//�t���b�v�֐�
		ScreenFlip();
	}

	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

