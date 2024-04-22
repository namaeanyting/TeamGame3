#pragma once

enum BGM_TYPE
{
	BGM_TITLE,
	BGM_PLAY,
	BGM_RESULT,
	BGM_MAX,
};
enum SE_TYPE
{
	SE_PUNCH,
	SE_MONSTER,
	/*SE_TITLE,
	SE_PLAY,
	SE_RESULT,*/
	SE_MAX,
};

class Sound
{
public:
	//������
	static void Init();

	class BGM
	{
	private:
		//���n���h��
		static int handle[BGM_MAX];
	public:
		//������
		static void Init();	
		//�Đ�������
		static void PlayButton(int nameType);
		//��~�ƍ폜
		static void StopDelButton(int nameType);
		//���ʒ���
		static void Volume(int type, int volume);
	};

	class SE
	{
	private:
		//���n���h��
		static int handle[SE_MAX];

	public:
		//������
		static void Init();
		//�Đ�������
		static void PlayButton(int nameType);
		//��~�ƍ폜
		static void StopDelButton(int nameType);
		//���ʒ���
		static void Volume(int type, int volume);

	};
};

/*
�錾	int ChangeVolumeSoundMem( int VolumePal , int SoundHandle ) ;

�T��	�������ɓǂ݂��񂾉��f�[�^�̍Đ��Ƀ{�����[����ݒ肷��

����	int VolumePal �@: �ݒ肷�鉹��( 0 �` 255 )
        int SoundHandle : ���ʂ�ݒ肷�鉹�̎��ʔԍ�(�T�E���h�n���h��)
�߂�l	�@�O�F����
�@		�|�P�F�G���[����

���	�@�Đ����鉹�̉��ʂ�ݒ肵�܂��B�O�͖����A�Q�T�T�ōő剹�ʂł��B
�@		�����Đ����ł����ʂ̕ύX�͉\�ł��B


		 // ���ʂ̐ݒ�
	ChangeVolumeSoundMem( 255 * 80 / 100, SHandle ) ;
*/
/*
�錾	int SetVolumeMusic( int Volume ) ;

�T��	�l�h�c�h���͂l�o�R�t�@�C���̉��t(�Đ�)�̉��ʂ�ݒ肷��

����	int Volume : ����( 0�`255 )
�߂�l	�@�O�F����
�@	�|�P�F�G���[����

���	�@PlayMusic�֐� �ŊJ�n�������t�̉��ʂ�ݒ肵�܂��O�������A
		�Q�T�T���ő剹��(�f�t�H���g)�ƂȂ�܂��B

*/