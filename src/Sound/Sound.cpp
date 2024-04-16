#include"DxLib.h"
#include"sound.h"

int Sound::BGM::handle[BGM_MAX];
int Sound::SE::handle[SE_MAX];


//������
void Sound::Init()
{
	BGM::Init();
	SE::Init();
}

//������
void Sound::BGM::Init()
{
	for (int i = 0; i < BGM_MAX; i++)
	{
		//�ǂݍ���
		handle[i] = LoadSoundMem(BGMPath[i]);
	}
}
void Sound::SE::Init()
{
	for (int i = 0; i < SE_MAX; i++)
	{
		//�ǂݍ���
		handle[i] = LoadSoundMem(SEPath[i]);
	}
}

//�Đ�������
void Sound::BGM::PlayButton(int nameType)
{
	PlaySoundMem(handle[nameType], DX_PLAYTYPE_LOOP, true);
}
void Sound::SE::PlayButton(int nameType)
{
	PlaySoundMem(handle[nameType], DX_PLAYTYPE_LOOP, true);
}

//��~�ƍ폜
void Sound::BGM::StopDelButton(int nameType)
{
	StopSoundMem(handle[nameType]);
	DeleteSoundMem(handle[nameType]);

}
void Sound::SE::StopDelButton(int nameType)
{
	StopSoundMem(handle[nameType]);
	DeleteSoundMem(handle[nameType]);

}